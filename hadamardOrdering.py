# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import math
from scipy.linalg import hadamard
from scipy.ndimage.measurements import label

def cake_cutting(n, is2D):
	H = (hadamard(n)+np.ones(n))/2
	structure = np.array([[0,1,0],[1,1,1],[0,1,0]])
	nComp = []

	for i in range(n):
		basis = H[i,:]
		if is2D:
			basis = basis.reshape((int(math.sqrt(n)),int(math.sqrt(n)))) # deve essere come in getbasis.c
		else:
			basis = basis.reshape(1,n) # deve essere come in getbasis.c 
		labeled, nC = label(basis, structure)
		nComp.append(nC)

	order = np.zeros((n,1)) -1
	min_prev = -1

	for i in range(n):
		prev = 0
		eq = 0
		for j in range(n):
			if nComp[j] < nComp[i]:
				prev += 1
			elif nComp[j] == nComp[i]:
				if i > j:
					eq += 1
		order[i] = prev + eq

	H1 = np.zeros((n,n))
	for i in range(n):
		
		H1[int(order[i]),:] = H[i, :]
	H1 = 2*H1 -1
	return H1

#%% code to test the function
# nB = 16
# is2Dmode = True
# ordered_H = cake_cutting(nB, is2Dmode)
# if is2Dmode:
	# for k in range(nB):
		# bToPlot = ordered_H[k]
		# plt.imshow(bToPlot.reshape((int(math.sqrt(nB)),int(math.sqrt(nB)))))
		# plt.show()
		# plt.pause(0.5)
# else:
	# plt.imshow(ordered_H)
	# plt.show()
	
