#!/usr/bin/env python

# Functions for graphing 

import os
import sys

# graphing libraries
import matplotlib as mpl
# Necessary for 'headless' useage (must be before pyplot import)
mpl.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.dates as mdates

from datetime import datetime as dt

# matlab style symbols for graph points
graphSymbols = ['bo', 'ro', 'g^', 'yv', 'ks']

def createAndSaveGraph(data):
   # figure out a name based on when we make the graph
   now = dt.today()
   nowStr = now.strftime('%m%d%Y-%H%M%S') 
   filename = 'data-' + nowStr + '.png'
   print('Save to', filename)

   numPlots = len(data)

   # Turn off interactive mode - don't display the graph locally
   plt.ioff()
   # clear any previous figure
   plt.clf()

   # depending on range of expected values, sharey may not be desireable
   # forces all subplots to save range
   fig, axarr = plt.subplots(nrows=numPlots, sharex=True, sharey=False)
   
   # set the title on the first subplot
   axarr[0].set_title('Data Collected ' + now.strftime('%m/%d/%Y %H:%M:%S'))

   # plot each nodes data on a separate subplot
   for i in range(numPlots):
      # only try to plot data if any available
      if len(data[i]) > 0:
         x,y = zip(*data[i])
         axarr[i].plot(x,y, graphSymbols[i], label='Node'+str(i+1))
      # Label the Axes
      axarr[i].set_ylabel('Node' + str(i+1))
      # put the legend to the right
      # axarr[i].set_legend(bbox_to_anchor=(1.05, 1), loc=2, numpoints=1, scatterpoints=1)


   # format the date range for the figure
   plt.xlabel('Date / Time')
   plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%m/%d/%Y %H:%M:%S'))
   plt.gca().xaxis.set_major_locator(mdates.MinuteLocator())
   fig.autofmt_xdate()

   # save the graph as an image
   plt.savefig(filename, bbox_inches='tight')

   return filename

# Post the file to the GMU server
# overwrites 'result.png'
def postResults(filename):
   # copy the file to generic name 'result.png' so the webpage will see it
   cmd = 'scp ' + filename + ' ablanfor@mason.gmu.edu:~/public_html/result.png'
   print cmd
   os.system(cmd + ' > /dev/null 2>&1')
   #os.system(cmd)



# testing...
if __name__ == '__main__':
   data = []
   for t in range(5): 
      test = 1
      data.append([])
      if t != 3:
         while test < 20:
            t1 = dt.today()
            data[t].append((t1, test*(t+1)))
      #      print t1, ",", test
            test += 1

   name = createAndSaveGraph(data)

   postResults(name)
