# -*- coding: utf-8 -*-

#from semaphore_win_ctypes import Semaphore # WORKS BUT LACKS OF WAIT FUNCTIONS
import win32event as w # documentation http://timgolden.me.uk/pywin32-docs/index.html
import numpy as np
import matplotlib.pyplot as plt

# hSem = Semaphore("hSem")
# pSem = Semaphore("pSem")
# hSem.open()
# pSem.open()

# 0x1F0003 corresponds to SEMAPHORE_ALL_ACCESS

hSem = w.OpenSemaphore(0x1F0003, False, "hSem")
pSem = w.OpenSemaphore(0x1F0003, False, "pSem")

print("THIS IS PYTHON SCRIPT")

plt.figure() # slowest part
n = 0 
# number of measurements = 10 (should be passed from C)
while(n<10):
	w.WaitForSingleObject(pSem, 10**4)	
	data = np.loadtxt("support.txt",dtype='int',delimiter=',')
	print(data[15])
	# 1D
	#plt.plot(data) 
	# 2D
	plt.cla()
	plt.imshow(data, aspect='auto')
	plt.show(block=False)
	plt.pause(0.03)
	w.ReleaseSemaphore(hSem, 1)
	n+=1
plt.close()