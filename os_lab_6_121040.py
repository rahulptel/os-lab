#import necessary libraray files
import time
from threading import *
import threading
from random import *

## To implement monitor locks are used to achieve synchronization.
## Reference: http://stackoverflow.com/questions/8127648/how-to-synchronize-threads-in-python
##            http://effbot.org/zone/thread-synchronization.htm            

## Initialize the necessary locks for synchronization
## Check if buffer full or not
fullL = threading.Lock()
## Check if buffer empty or not
emptyL = threading.Lock()
## Constrain producer to producer
producerL = threading.Lock()
## Constarin consumer to consume
consumerL = threading.Lock()                        

## Buffer initialization
buf=[]

def producer():
    global buf
    time.sleep(randint(0,50))
    ## if queue is full it acquires a lock over thread which prevents producer to produce more items until customer bus something
    if len(buf) == 10:                                  
        print "\n Buffer (size 10) is full. Producer gets blocked"
        fullL.acquire()
    producerL.acquire()
    fullL.acquire()
    buf.append(randint(0,100))
    fullL.release()
    print "\n Producer produced "+str(buf[-1])
    ## Check everytime that if the empty was acquired due to no items in the buffer, then it must be released as the producer has appended an item.
    if emptyL.locked():
        emptyL.release()
    producerL.release()

def consumer():
    global buf
    time.sleep(randint(0,50))
    consumerL.acquire()
    ## If queue is empty it acquires a lock over thread which prevents customer to buy more items until the producer produces more
    if len(buf) < 1:                  
        print "\n Buffer (size 10) is empty. Consumer gets blocked"
        emptyL.acquire()
    emptyL.acquire()
    print "\n Consumer consumed "+str(buf[-1])
    del buf[-1]
    if emptyL.locked():
        emptyL.release()
    ## Check everytime that if the full lock was acquired as due to buffer full,then it must be released as the consumer has consumed an item.
    if fullL.locked():
        fullL.release()
    consumerL.release()

print "Threads are getting created"

# Create 20 producer threads
for i in xrange(20):
    Thread(target=producer).start();
# Create 5 consumer threads
for j in xrange(5):
    Thread(target=consumer).start();
    
print "Threads are running"
    
