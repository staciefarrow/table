# This code is to be used with only one Arduino: it allows to transmit serial commands as strings.

import time
import smbus

bus = smbus.SMBus(1)

address = 0x04

def writeNumber(value):

	for character in str(value): # convert into a string and iterate over it
        	bus.write_byte(address, ord(character)) # send each char's ASCII encoding

	return -1

while True:
	#var = input("Enter a character: ")
    #if not var:
	#	continue

    try:
        var = input("Enter a character: ")
    except ValueError:
        print "Try again"
        continue

	writeNumber(var)
	print("Sent: ", var)
time.sleep(1)
