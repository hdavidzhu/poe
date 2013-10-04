# Script used to communicate position to the Arduino.
# Written by David Zhu.

# Declarations.

# Connect to the Arduino Serial Port.
ser = serial.Serial(port = "/dev/ttyACM0", baudrate = 9600, timeout = 0.1)