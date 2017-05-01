
#This code lets you choose which Arduino to send i2c serial commands to.

import time
import smbus

bus = smbus.SMBus(1)

address = 0
address1 = 0x04
address2 = 0x06

# while loop prompts which Arduino to choose (1 or 2)
while address == 0:

    arduino = input("Select Arduino to communicate with: ")

    if arduino == 1:
        address = address1
    elif arduino == 2:
        address = address2
    else:
        print("Invalid entry: choose 1 or 2\n")
        continue


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
