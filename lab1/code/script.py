# Script for running the LIDAR program.

# Load packages.
import serial

connected = False

ser = serial.Serial("/dev/ttyACM0", 9600)

while not connected:
	serin = ser.read()
	connected = True

ser.write("1")

while ser.read() == '1':
	ser.read()

ser.close()