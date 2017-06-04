//nxt_roam.cpp
//a small demonstration program for the nxt_remote.cpp library
//(c) 12.2006 by Daniel Berger (daniel.berger@tuebingen.mpg.de)

/* Description:
The program assumes that the two motors of the vehicle are connected to motor outputs
A and C, the front touch sensor is connected to sensor input 1, and the ultrasonic sensor 
to input 4.
All interfacing is done via the NXT_* variables.
The robot is going forward and turns progressively when obstacles near. When an obstacle 
is hit (the touch sensor activated), the program stops.
This is a windows console program which uses the conio.h console interface of Visual C++
for easy keyboard access and text output to the console window.
Simply put nxt_remote.cpp, nxt_remote.h and roam.cpp in a windows console project in Visual C++,
set the serial port used for bluetooth communication in the nxtr->startcommunication() command, 
switch on the robot and make sure the serial port connection is working.
Then compile, run and enjoy. :)
*/

#include <windows.h>
#include <conio.h>
#include "nxt_remote.h"

nxt_remote *nxtr;

int main(int argc, char* argv[]){
  int i;
  nxtr=new nxt_remote(); //this is our interface with the NXT
  nxtr->startcommunication("COM5");
  bool Check = nxtr->startcommunication("COM5");
  _cprintf("Starting NXT communication on port COM5... ");
  if (Check==0)
  { //initialize interface and check if initialization failed
    _cprintf("NXT communication failed.");
  }

  else 
  {
	  _cprintf("NXT communication Success.");
  }
    
  
  while (!_kbhit())
  {
  }
  //set sensor types, switch on used sensors and motors
  //nxtr->NXT_sensortype[0]=0x01; //switch
  ////nxtr->NXT_sensortype[1]=0x08; //microphone (sound_dba)
  ////nxtr->NXT_sensortype[2]=0x06; //light inactive
  //nxtr->NXT_sensortype[3]=0x0B; //ultrasonic sensor (LOWSPEED_9V)
  //nxtr->NXT_sensoron[0]=1;
  //nxtr->NXT_sensoron[3]=1;
  //nxtr->NXT_motoron[0]=1;
  //nxtr->NXT_motoron[2]=1;

  //while((!_kbhit())&&(nxtr->NXT_sensorvalnorm[0]>500)){ //loop until key pressed or touch sensor activated
  //  _cprintf("S1: %i, S4: %i\r\n",nxtr->NXT_sensorvalnorm[0],nxtr->NXT_sensorvalraw[3]); //report state on screen
  //
  //  //the following code lets the robot move linear if no obstacle, and turn at approaching obstacles
  //  i=nxtr->NXT_sensorvalraw[3]; //get current ultrasonic distance measure
  //  if (i<0) i=0; if (i>50) i=50; //constrain to values between 0 and 50
  //  nxtr->NXT_motorval[0]=i;
  //  nxtr->NXT_motorval[2]=(i*2)-50;

  //  Sleep(50); //this is important so that the NXT-managing background thread is not blocked
  //}

  nxtr->stopcommunication();   //stop interfacing. This also stops the motors.
	return 0;
}