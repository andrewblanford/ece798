#!/usr/bin/sudo python

# Andrew Blanford
# Receive data from PIC24 sensor node
# uses RF24 library and GPIO

# For timestamps
import time
from datetime import datetime as dt
# For data lock
from threading import Lock
# RF24 wireless radio library
from RF24 import *
# for data formatting
import struct
# For GPIO access
import RPi.GPIO as GPIO
# graphing functions
import graphutils


########### USER CONFIGURATION ###########
# CE Pin, CSN Pin, SPI Speed
# Setup for GPIO 22 CSN and CE0 with SPI Speed @ 8Mhz
radio = RF24(RPI_V2_GPIO_P1_22, BCM2835_SPI_CS0, BCM2835_SPI_SPEED_8MHZ)

# Graphing Interval in seconds
GRAPH_INTERVAL = 1 * 10
##########################################

# Node1-5 addresses 
# These have to have the first 4 bytes the same
# LSB is unique
# corresponds to ascii characters "Node1", "Node2" ... 
# python doesn't use the same string conversion as C, so we do it this way
pipes = [0x65646F4E31, 0x65646F4E32, 0x65646F4E33, 0x65646F4E34]

# somewhere to store the received data
dataToGraph = []
dataLock = Lock()

# use GPIO numbering
GPIO.setmode(GPIO.BCM)

# setup the interrupt pin as input
GPIO.setup(27, GPIO.IN)

# Start RF operations
radio.begin()
radio.setRetries(15,15)

# mask all interrupts except rx_ready
radio.maskIRQ(True, True, False)

# Open read channels for each pipe
for i in range(len(pipes)):
   print('Open Reading Pipe', i, pipes[i])
   radio.openReadingPipe(i + 1, pipes[i])
   # Add a blank data buffer for each pipe
   dataToGraph.append([])

# Begin listening mode
radio.startListening()
radio.printDetails()

# IRQ Handler for rx_ready
# @param channel - the GPIO pin/channel triggering callback
def radioCallback(channel):
   # get the interrupt flags
   [tx_ok, tx_fail, rx_ready] = radio.whatHappened()
   if rx_ready:
      while radio.available():
         [avail, pipe] = radio.available_pipe()
         if avail:
            # Fetch the payload, and see if this was the last one.
            recv_buffer = radio.read(4)
            # "L" is unsigned long c type (4 bytes) (see struct.unpack doc)
            data = struct.unpack("L", recv_buffer)
            # get the current time
            now = dt.today()
            # try the lock - returns false instead of blocking
            # if lock not available, we drop the data sample (don't want to block interrupt)
            if dataLock.acquire(False):
               dataToGraph[pipe - 1].append((now, data[0]))
               dataLock.release()

            print('Got payload from={} value="{}"'.format(pipe, data[0]))


# register the IRQ handler 
GPIO.add_event_detect(27, GPIO.FALLING, callback=radioCallback)

print "Graph interval", GRAPH_INTERVAL, "seconds"

# forever loop
while 1:
   # wait while data is captured
   time.sleep(GRAPH_INTERVAL)
   # lock the data buffers
   dataLock.acquire()

   # create a graph image
   filename = graphutils.createAndSaveGraph(dataToGraph)
   print "Graph saved: ", filename

   # clear old data
   for i in range(len(dataToGraph)):
      del dataToGraph[i][:]

   # release lock with fresh buffers
   dataLock.release()
   
