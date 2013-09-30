# Script for re-running the LIDAR program.
# This script lacks control of the Arduino. Instead it takes old data and replots them.
# Written by Jack Fan and David Zhu.

# Load packages.
from time import sleep
import serial
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from math import *

# Open backup files.
fx = open('xlist.txt','r')
fy = open('ylist.txt','r')
fz = open('zlist.txt','r')

# Read those files.
xdata = fx.read()
ydata = fy.read()
zdata = fz.read()

xs = xdata.split('\n')
ys = ydata.split('\n')
zs = zdata.split('\n')

for i in range(len(xs)-1):
	xs[i] = float(xs[i])
	ys[i] = float(ys[i])
	zs[i] = float(zs[i])

# Pop off the weird space.
xs.pop()
ys.pop()
zs.pop()

# Plot.
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.scatter(xs,ys,zs,s=100,c='r',marker='o')	# Creates a scatter plot.
plt.xlim([-25,25])	# Set explicit boundaries on the plot.
plt.ylim([0,50])
ax.set_zbound(0,50)
plt.show()	# Plot.