#include "can.h"

#include <sys/socket.h>
#include <linux/can.h>
#include <net/if.h>

#define CAN_INTERFACE "can0"
#define CAN_FRAME_SIZE 8

NAN_METHOD(RetrieveCanMessage) {
  Nan::HandleScope scope;

  v8::Local<v8::String> result = Nan::New("Reee test123").ToLocalChecked();
  info.GetReturnValue().Set(result);
}

NAN_MODULE_INIT(Init) {
  Nan::Set(target, Nan::New("RetrieveCanMessage").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(RetrieveCanMessage)).ToLocalChecked());
}

NODE_MODULE(WillsNodeCan, Init)