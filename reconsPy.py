#import sdtfile
import numpy as np
import matplotlib.pyplot as plt
#import matplotlib as mpl
from PIL import Image
from scipy.sparse.linalg import lsmr
from scipy.linalg import hadamard
#from transformMatrix import transformMatrix
from hadamardOrdering import cake_cutting

#def readSdt(fileName, numBanks):
#	data = []
#	for i in range(numBanks):
#		if numBanks == 1:
#			sdt = sdtfile.SdtFile(fileName+".sdt")
#		elif numBanks<10:
#			sdt = sdtfile.SdtFile(fileName+"_c"+str(i)+".sdt")
#		elif numBanks<100:
#			if i<10:
#				sdt = sdtfile.SdtFile(fileName+"_c0"+str(i)+".sdt")
#			else:
#				sdt = sdtfile.SdtFile(fileName+"_c"+str(i)+".sdt")
#		elif numBanks<1000:
#			if i<10:
#				sdt = sdtfile.SdtFile(fileName+"_c00"+str(i)+".sdt")
#			elif i<100:
#				sdt = sdtfile.SdtFile(fileName+"_c0"+str(i)+".sdt")
#			else:
#				sdt = sdtfile.SdtFile(fileName+"_c"+str(i)+".sdt")
#		time = sdt.times[0][:]
#		batch = sdt.data[0].shape[0];
#		for j in range(batch):
#			data.append(sdt.data[0][j,:])
#  	return (time,data)

# def readDat(filename, n_curves, n_rep, gain, NUMCHAN):	   
	# # bisogna definire come sarà il file .dat (quanti loop ci sono)
    # HEADLEN = 764
    # SUBLEN = 204
    # T = 50 # ns (dipende dalla SPC board)
    # data = []
    # with open(filename+'.dat','rb') as rawdata:
	    # header = rawdata.read(HEADLEN)
	    # res=[]
	    # for _ in range(n_rep):
			# for _ in range(n_curves):
				# subheader = rawdata.read(SUBLEN)      
				# value = np.fromfile(rawdata,dtype='H',count=NUMCHAN)
				# res.append(value)
	    # data = np.array(res)
    # dt = T/NUMCHAN/gain*10**3 # ps
    # time = np.arange(0,dt*NUMCHAN,step=dt)
    # return (time,data)

def plotData(time, data, name, startGate, endGate, saveFigures = False):
	plt.pcolormesh(data)
	plt.title("Spectrum vs Time")
	plt.axvline(startGate,ymin=0,ymax=1,color='r')
	plt.axvline(endGate,ymin=0,ymax=1,color='r')
	if saveFigures:
		plt.savefig(name+".jpg")
	plt.show()
	plt.close()
	plt.plot(np.sum(data[:,startGate:endGate], axis = 1))
	plt.title("Spectrum")
	if saveFigures:
		plt.savefig(name+"linear.jpg")
	plt.show()
	plt.close()
    
def accumulate(data, nBasis, ADCres):
	tot = np.zeros((nBasis, ADCres))
	i = 0
	for el in data:
		idx = i%nBasis		
		tot[idx,:] += el
		i+=1
	return tot

def subtractBkg(data, start, end):
	datLen = len(data)
	averageBkg = np.zeros((datLen,1))
	for k in range(datLen):
		averageBkg[k] = np.mean(data[k][start:end]) 
		data[k] -= averageBkg[k]
	return data

def reconstructRaster(data, nMeas, ADCres, startGate, endGate, saveFigures = False): 
	H = np.eye(nMeas)
	recons = np.zeros((nMeas,ADCres))   
	for i in range(ADCres):
		recons[:,i] = lsmr(H, data[:,i])[0]
	recons[0] = recons[1] # per eliminare il segnale della base sempre 1
	fig, ax = plt.subplots(1,2)
	ax[0].pcolormesh(recons)
	ax[0].set_title("Spectrum vs Time")
	ax[0].axvline(startGate,ymin=0,ymax=1,color='r')
	ax[0].axvline(endGate,ymin=0,ymax=1,color='r')
	if saveFigures:
		plt.savefig(name+".jpg")
	ax[1].plot(np.sum(recons[:,startGate:endGate], axis = 1))
	ax[1].set_title("Spectrum")
	if saveFigures:
		plt.savefig(name+"linear.jpg")
	plt.show()
	plt.pause(0.001)

def reconstructHad1D(data, nBasis, ADCres, startGate, endGate, cs = False, saveFigures = False):
	#dataNp = np.zeros((len(data),ADCres)) # non nMeas perchè voglio dim uguali per la ricostruzione. Impongo però basi non misurate a 0
	#i = 0
	#for el in data:
	#	dataNp[i,:] = el 
	#	i+=1 
	if cs:
		H = cake_cutting(nBasis, False)
	else:
		H = 0.5*(hadamard(nBasis) + np.ones((nBasis, nBasis)))
	H = H[:len(data),:] # data è 2D
	recons = np.zeros((nBasis,ADCres))   
	for i in range(ADCres):
		#recons[:,i] = lsmr(H, dataNp[:,i])[0]
		recons[:,i] = lsmr(H, data[:,i])[0]
	recons[0] = recons[1] # per eliminare il segnale della base sempre = a 1
	# fig, ax = plt.subplots(1,2)
	# ax[0].pcolormesh(recons)
	# ax[0].set_title("Spectrum vs Time")
	# ax[0].axvline(startGate,ymin=0,ymax=1,color='r')
	# ax[0].axvline(endGate,ymin=0,ymax=1,color='r')
	# if saveFigures:
		# plt.savefig(name+".jpg")
	# ax[1].plot(np.sum(data[:,startGate:endGate], axis = 1))
	# ax[1].set_title("Spectrum")
	# if saveFigures:
		# plt.savefig(name+"linear.jpg")
	#plt.draw()
	#plt.show()
	#plt.pause()
	#plt.close()

def reconstructHad2D(data, nBasis, zoom, xcp, ycp, saveFigures = False, cs = False):

        #bisogna aggiungere qualcosa del genere nel caso si voglia utilizzare cs
        #dataNp = np.zeros((len(data),ADCres)) # non nMeas perchè voglio dim uguali per la ricostruzione. Impongo però basi non misurate a 0
	#i = 0
	#for el in data:
	#	dataNp[i,:] = el 
	#	i+=1
        #H = H[:len(data),:] # data è 2D

	sqNb = int(np.sqrt(nBasis))
	WIDTH = 1920
	HEIGHT = 1080
	reWIDTH = int(WIDTH/zoom) # resized dimension after zoom
	reHEIGHT = int(HEIGHT/zoom)
	xul = int(xcp-reWIDTH/2) # upper left corner
	yul = int(ycp-reHEIGHT/2)
	if xul+reWIDTH>WIDTH:
		xul = WIDTH-reWIDTH
	if xul<0:
		xul = 0
	if yul+reHEIGHT>HEIGHT:
		yul = HEIGHT-reHEIGHT
	if yul<0:
		yul = 0
	#np.savetxt("pysupport.txt",data,fmt="%u",delimiter=";") # debug: save data to txt file
	measure = np.sum(data,axis=1)
	#plt.imshow(data, aspect='auto') # debug: plot all measures 
	#plt.show()
	#plt.pause(0.01)
	#for i in range(nBasis):
	#	plt.plot(data[i])
	#plt.show()
	if cs:
		H = cake_cutting(nBasis, True)
	else:
		H = 0.5*(hadamard(nBasis) + np.ones((nBasis, nBasis)))
	recons2 = lsmr(H, measure)[0]
	recons2[0] = recons2[0]/nBasis # problem of first basis which is always one
	recons2back = Image.fromarray(np.zeros([HEIGHT,WIDTH]))
	recons2im = Image.fromarray(np.transpose(np.reshape(recons2,(sqNb,sqNb))))
	recons2imresized = recons2im.resize((reWIDTH,reHEIGHT), resample=Image.Resampling.NEAREST)
	#recons2imresizedr = recons2imresized.rotate(45) # rotate the image
	#plt.figure()
	plt.imshow(np.array(recons2imresized), aspect="equal")
	#ax.draw()
	#plt.show()
	#plt.colorbar()
	plt.title("recons only in region")
	plt.show()
	plt.pause(0.001)
	#if saveFigures:
	#	plt.savefig(name+".png")
	#plt.show(block=False)
	#plt.pause(1)
	#plt.close()
	#print("max:", np.max(np.array(recons2imresized)))
	##recons2back.paste(recons2imresized,(xul,yul))
	#recons2backr = recons2back.rotate(45) # rotate the image
	##plt.imshow(np.array(recons2back), aspect="equal")
	##plt.colorbar()
	##plt.title('recons zone on dmd')
	#if saveFigures:
	#	plt.savefig(name+"_dmd.png")
	##plt.show(block=True)
		
def createFigure():
	plt.ion()
	
def closePlt():
	plt.close()
