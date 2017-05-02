#sends a single character through i2c

import time
import smbus


bus = smbus.SMBus(1)

address = 0x04

def writeNumber(value):

	bus.write_byte(address, ord(value))

	return -1


while True:
	var = input("Enter a character: ")
	
	if not var:
		continue
	
	writeNumber(var)
	print("Sent: ", var)
	time.sleep(1)
