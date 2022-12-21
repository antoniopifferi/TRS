# -*- coding: utf-8 -*-

import sys
import numpy as np
import matplotlib.pyplot as plt

def flipData(data):
	return data.transpose()

def printData(data):
	print(sys.path)
	print(data)

def plot(data): 
	plt.figure()
	plt.title("From plot")
	plt.plot(data)
	#plt.show()
	plt.show(block=False)
	plt.pause(1)
	plt.close()
	
def plot2D(data): 
	plt.figure()
	plt.title("From plot2D")
	plt.imshow(data, aspect='auto')
	#plt.show()
	plt.show(block=False)
	plt.pause(1)
	plt.close()
	
def createImage(dimX,dimY):
	xc = 10
	yc = 10
	sigma = 5
	xInd = np.linspace(0,dimX,256)
	yInd = np.linspace(0,dimY,256)
	X, Y = np.meshgrid(xInd, yInd)
	Z = np.exp(-((X-xc)**2+(Y-yc)**2)/sigma)
	plt.figure()
	plt.title("From createImage")
	plt.imshow(Z, cmap='gray', aspect='auto')
	plt.show(block=False)
	plt.pause(1)
	plt.close()
	return Z
	
	