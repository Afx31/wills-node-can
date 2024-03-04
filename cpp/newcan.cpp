#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/if.h>
#include <sys/ioctl.h>

// "Preprocessor directive which defines a macro"
#define CAN_INTERFACE "can0"
#define CAN_FRAME_SIZE 8

int main()
{
  int s;
  int nbytesRead;
  struct can_frame frame;
  struct sockaddr_can addr;
  struct ifreq ifr;

  // Create socket
  // s = socket (PF_CAN, SOCK_DGRAM, CAN_BCM); // Send
  if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)
  {
    //Nan::ThrowError("Socket creation failed");
    return;
  }  

  // Interface setup
  strcpy(ifr.ifr_name, CAN_INTERFACE);
  ioctl(s, SIOCGIFINDEX, &ifr);

  addr.can_family = AF_CAN;
  addr.can_ifindex = ifr.ifr_ifindex;

  // Bind socket to CAN interface
  if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0)
  {
    // Close?
    perror("Binding failed");
    return;
  }

  // --------------- Reading frames ---------------
  nbytesRead = read(s, &frame, sizeof(struct can_frame));

  if (nbytesRead < 0)
  {
    perror("CAN raw socket read");
    return 1;
  }
  if (nbytesRead < sizeof(struct can_frame))
  {
    fprintf(stderr, "read: incomplete CAN frame\n");
    return 1;
  }

  
  // Close socket
  close(s);

  // --------------- Writing frames ---------------
  nbytesWrite(s, &frame, sizeof(struct can_Frame));

}