/*
 Copyright (C) 2011 J. Coliz <maniacbug@ymail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.

 03/17/2013 : Charles-Henri Hallard (http://hallard.me)
              Modified to use with Arduipi board http://hallard.me/arduipi
						  Changed to use modified bcm2835 and RF24 library
TMRh20 2014 - Updated to work with optimized RF24 Arduino library

 */

/**
 * Example RF Radio Ping Pair
 *
 * This is an example of how to use the RF24 class on RPi, communicating to an Arduino running
 * the GettingStarted sketch.
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <RF24/RF24.h>

using namespace std;
//
// Hardware configuration
// Configure the appropriate pins for your connections

/****************** Raspberry Pi ***********************/

RF24 radio(22,0);

/********** User Config *********/
// Assign a unique identifier for this node, 0 or 1
bool radioNumber = 1;

/********************************/

// Radio pipe addresses for the 2 nodes to communicate.
const uint8_t pipes[][6] = {"1Node","2Node"};


int main(int argc, char** argv){

  bool role_ping_out = true, role_pong_back = false;
  bool role = role_pong_back;

  cout << "RF24/examples/GettingStarted/\n";

  // Setup and configure rf radio
  radio.begin();

  // optionally, increase the delay between retries & # of retries
  radio.setRetries(15,15);
  // Dump the configuration of the rf unit for debugging
  radio.printDetails();


      radio.openReadingPipe(1,pipes[0]);
      radio.openReadingPipe(2,pipes[1]);
	radio.startListening();
	
	// forever loop
	while (1)
	{
			// if there is data ready
			if ( radio.available() )
			{
				// Dump the payloads until we've gotten everything
				unsigned long got_time;
                                uint8_t pipeNum;

				// Fetch the payload, and see if this was the last one.
				while(radio.available(&pipeNum)){
					radio.read( &got_time, sizeof(unsigned long) );
				}
				// Spew it
				printf("Got payload(%d) %lu...\n",pipeNum, got_time);
				
				
			}
		
	} // forever loop

  return 0;
}

