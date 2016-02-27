#!/usr/bin/env python

# Andrew Blanford
# Monitor a directory and send any new files over the network
# uses watchdog library and scp protocol

import sys
import time
import os
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

# Create a Event Handler subclass to send new files
# Override "on_created" to get the filename and send it 
class NewFileSender(FileSystemEventHandler):
   # destination is the full path to where to send the file in scp syntax
   # eg. user@server:path
   def __init__(self, destination):
      self.destination = destination 

   # post newly created files to the provide destination
   def on_created(self, event):
      # copy the file to generic name 'result.png' so the webpage will see it
      cmd = 'scp ' + event.src_path + ' ' + self.destination
      # use the underlying os to execute the scp command
      os.system(cmd + ' > /dev/null 2>&1')


# Main function
# take 2 arguments 
# 1: directory to monitor, (default '.')
# 2: destination (default './result.png')
# destination can be scp destination eg. 
# ablanfor@mason.gmu.edu:~/public_html/result.png
if __name__ == "__main__":
    path = sys.argv[1] if len(sys.argv) > 1 else '.'
    dest = sys.argv[2] if len(sys.argv) > 2 else './result.png'
    #dest = "ablanfor@mason.gmu.edu:~/public_html/result.png"

    print "Copying new files from ", path, " to ", dest

    # set up directory observer which will activte the event handler
    # when something changes
    event_handler = NewFileSender(dest)
    observer = Observer()
    observer.schedule(event_handler, path, recursive=False)
    observer.start()

    # clean up nicely on ctrl-c
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()
