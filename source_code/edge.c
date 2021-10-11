#include <math.h>

#include <kilombo.h>

#include "edge.h"

int counter=0;
enum {STOP,LEFT,RIGHT,STRAIGHT};

typedef struct
{
  Neighbor_t neighbors;

  //int N_Neighbors;
  uint8_t bot_type;
  uint8_t bot_state;
  uint8_t move_type;

  message_t transmit_msg;
  char message_lock;

  received_message_t RXBuffer[RB_SIZE];
  uint8_t RXHead, RXTail;

} MyUserdata;

REGISTER_USERDATA(MyUserdata)

#ifdef SIMULATOR
#include <stdio.h>    // for printf
#else
#define DEBUG         // for printf to serial port
#include "debug.h"
#endif

void set_bot_state(int state)
{
  mydata->bot_state = state;
}

int get_bot_state(void)
{
  return mydata->bot_state;
}

void set_move_type(int type)
{
  mydata->move_type = type;
}

int get_move_type(void)
{
  return mydata->move_type;
}
void rxbuffer_push(message_t *msg, distance_measurement_t *dist)
{
  if (counter==1 && kilo_uid==1)
  {
    set_color(RGB(1,0,1));//purple
  }
  if (counter==1 && kilo_uid==2)
  {
    set_color(RGB(1,0,1));//purple
  }
  if (counter==1 && kilo_uid==3)
  {
    set_color(RGB(1,0,1));//purple
  }
  if (counter==2 && kilo_uid==2)
  {
    set_color(RGB(3,3,0));//yellow
  }
  if (counter==2 && kilo_uid==3)
  {
    set_color(RGB(3,3,0));//yellow
  }
  if (counter==3 && kilo_uid==1)
  {
    set_color(RGB(3,3,0));//yellow
  }
  if (counter==3 && kilo_uid==3)
  {
    set_color(RGB(3,3,0));//yellow
  }
  if (counter==4 && kilo_uid==1)
  {
    set_color(RGB(3,3,0));//yellow
  }
  if (counter==4 && kilo_uid==2)
  {
    set_color(RGB(3,3,0));//yellow
  }
  if (counter==5 && kilo_uid==0)
  {
    set_color(RGB(3,0,0));//Red
    set_motors(0, 0);
  }
  if (counter==5 && kilo_uid==1)
  {
    set_color(RGB(3,0,0));//Red
    //set_motors(kilo_turn_left, 0);
  }
  if (counter==5 && kilo_uid==2)
  {
    set_color(RGB(0,0,0));//black
  }
  if (counter==5 && kilo_uid==3)
  {
    set_color(RGB(3,0,0));//Red
    //set_motors(kilo_turn_left, 0);
  }
  // else if (counter==0 && kilo_uid!=0)
  // {
  //   set_color(RGB(0,3,0));//green
  // }
}// to push message

message_t *message_tx()
{
  Neighbor_t temp;
  temp.timestamp = kilo_ticks - mydata->neighbors.timestamp;
  if (kilo_uid==0)
  {
    if (temp.timestamp  >=250 && temp.timestamp < 500)
    {
      counter=1;
      set_color(RGB(255,102,0));//orange
      set_motors(kilo_turn_left, 0);
    }
  }
  if (kilo_uid==1)
  {
    if(temp.timestamp  >= 500 && temp.timestamp < 750)
    {
      counter=2;
      set_color(RGB(255,0,0));//red
    }
  }
  if (kilo_uid==2)
  {
    if(temp.timestamp  >= 750 && temp.timestamp < 1000)
    {
      counter=3;
      set_color(RGB(0,0,0));//black
    }
  }
  if (kilo_uid==3)
  {
    if(temp.timestamp  >= 1000 && temp.timestamp < 1250)
    {
      counter=4;
      set_color(RGB(255,0,0));//red
    }
  }
  if (temp.timestamp  >= 1250 && temp.timestamp < 1500)
  {
    // if(kilo_uid!=2)
    // {
      counter=5;
      //set_color(RGB(255,0,0));//red
    // }
  }
  // else
  // {
  //   if(temp.timestamp  > 1250)
  //   {
  //     mydata->neighbors.timestamp = kilo_ticks;
  //   }
  //   counter=0;
  // }
}
// to send messages you can ignore the logic of time stamps etc

void setup()
{
  if(kilo_uid == 0)
  {
  set_color(RGB(0,0,3));
  //set_motors(0, 0);
  //set_move_type(LEFT);

  }
  else
  {
  set_color(RGB(0,3,0));//green

  }
  set_move_type(STOP);
  set_bot_state(LISTEN);
  mydata->neighbors.timestamp = kilo_ticks;
}



void loop()
{}



int main(void)
{
  kilo_init();

  //SET_CALLBACK(botinfo, botinfo);
  //SET_CALLBACK(reset, setup);


 kilo_start(setup, loop);
 kilo_message_rx = rxbuffer_push;
 kilo_message_tx = message_tx;

  return 0;
}
