#include <nan.h>
#include <unistd.h>
#include <string.h>
#include <node_buffer.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/if.h>
#include <sys/ioctl.h>

#define CAN_INTERFACE "can0"
#define CAN_FRAME_SIZE 8

using namespace v8;

NAN_METHOD(ReceivedCANData)
{
    Nan::HandleScope scope;

    int s;
    int nbytesRead;
    struct can_frame frame;
    struct sockaddr_can addr;
    struct ifreq ifr;
    
    // ------------------------------ Create socket ------------------------------
    // s = socket (PF_CAN, SOCK_DGRAM, CAN_BCM)  // Send
    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)  // Read
    {
        Nan::ThrowError("ERROR: Socket creation failed");
        return;
    }

    // ------------------------------ Interface setup ------------------------------
    strcpy(ifr.ifr_name, CAN_INTERFACE);
    ioctl(s, SIOCGIFINDEX, &ifr);
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    // Bind socket to the can interface
    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        close(s);
        Nan::ThrowError("ERROR: Binding failed");
        return;
    }

    // ------------------------------ Reading frames -----------------------------
    nbytesRead = read(s, &frame, sizeof(struct can_frame));

    if (nbytesRead < 0)
    {
        // close(s);
        Nan::ThrowError("ERROR: Read failed");
        return;
    }
    // if (nbytesRead < sizeof(struct can_frame))
    // {
    //   Nan::ThrowError("EEROR: Read incomplete CAN frame");
    //   return;
    // }

    // Close socket
    close(s);

    // ------------------------------ Nan Method prep for JS -----------------------------
    // Object to hold the CAN data
    Local<Object> result = Nan::New<Object>();
    Nan::Set(result, Nan::New<String>("id").ToLocalChecked(), Nan::New<Number>(frame.can_id));
    Nan::Set(result, Nan::New<String>("dlc").ToLocalChecked(), Nan::New<Number>(frame.can_dlc));

    // Create a Buffer to hold the data
    Local<ArrayBuffer> buffer = ArrayBuffer::New(Isolate::GetCurrent(), frame.data, CAN_FRAME_SIZE); // Read
    //Nan::Set(result, Nan::New<String>("data").ToLocalChecked(), ArrayBuffer::New(Isolate::GetCurrent(), buffer));
    Nan::Set(result, Nan::New<String>("data").ToLocalChecked(), buffer);

    info.GetReturnValue().Set(result);
}

NAN_MODULE_INIT(Init)
{
    Nan::Set(target,
      Nan::New<String>("ReceivedCANData").ToLocalChecked(),
      Nan::GetFunction(Nan::New<FunctionTemplate>(ReceivedCANData)).ToLocalChecked()
    );
}

NODE_MODULE(WillsNodeCAN, Init)
