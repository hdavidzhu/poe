# Script for running the LIDAR program.

# Load packages.
import serial
import matplotlib

# Set definitions.
ser = serial.Serial('/dev/ttyACM0', 9600)