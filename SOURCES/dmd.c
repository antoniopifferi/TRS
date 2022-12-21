
#include "dmd.h"
void writeOnFile(char *fileName, unsigned char *data, int size){
	FILE * pData = fopen(fileName, "a");
	for(int k=0; k<size; k++){
		fprintf(pData, "%d\n", data[k]);
	}
	fprintf(pData, "\n\n");
	fclose(pData);
}

void writeOnFile_int(char *fileName, int data [], int size){
	FILE * pData = fopen(fileName, "a");
	for(int k=0; k<size; k++){
		fprintf(pData, "%d\n", data[k]);
	}
	fprintf(pData, "\n\n");
	fclose(pData);
}

char * convlen(int a, int l){

	char * res;
	res = (char*)malloc(l * sizeof(char));
	if(a == 0){
		while(l>0){
            res[l-1]='0';
            l--;
        }
	}
	else{ // go to the last position of the string (least significant bit)
		l--;
		while(a!=1 && l>-1){ // convert the number by successive divisions by 2
			if(a%2==0)
				res[l]='0';
			else
				res[l]='1';
			a/=2;
			l--;
		}
		res[l]='1';
		while(l>0){ // fill the remaining bits
			l--;
			res[l]='0';
        }
	}
	return res;
}

int * bitsToBytes(const char *a, const int size){

	int *bits_int;
	int *bytes;
	int size_bytes;
	int i,j,cont;

	bits_int = (int*)malloc(size * sizeof(int));
	for(i=0; i<size; i++){
		bits_int[i] = a[i]-'0'; // conversion ASCII char -> number (bit)
    }

	if(size%8>0)
		size_bytes = size/8+1;
	else
		size_bytes = size/8;
	bytes = (int*)malloc(size_bytes * sizeof(int));
	j = size-1;
	for(i=0; i<size_bytes; i++){
		bytes[i] = 0;
		cont = 0;
		while(j>-1 && cont<8){
			bytes[i] += pow2_i_dmd(cont)*(bits_int[j]); // conversion bits -> number
			cont++;
			j--;
		}
	}
	free(bits_int);
	return bytes;
}

int talkDMD_int(hid_device *handle, const char mode, const char sequencebyte, const char com1, const char com2, const int *data, const int sizeData){
	unsigned char *tmp;
	tmp = (unsigned char *)malloc(sizeData*sizeof(unsigned char));
	for(int i=0; i<sizeData; i++)
		tmp[i] = (unsigned char)data[i];

	int res = talkDMD_char(handle, mode, sequencebyte, com1, com2, tmp, sizeData);

	free(tmp);
	return res;
}

int talkDMD_char(hid_device *handle, const char mode, const char sequencebyte, const char com1, const char com2, const unsigned char *data, const int sizeData){

	unsigned char buffer[SIZE_SEND];
	char flagstring[8];
	int res;
	int i,k;

    // Flag Byte (says read or write in the buffer)
	if(mode == 'r')
		flagstring[0] = '1'; // 11000000 -> 0xC0
	else
		flagstring[0] = '0'; // 01000000 -> 0x80
	flagstring[1] = '1';
	for(i=2; i<8; i++)
		flagstring[i] = '0';
	buffer[0] = 0x00;
	int *tmp = bitsToBytes(flagstring, 8);
	buffer[1] = tmp[0];
	free(tmp);

	// Sequence byte
	buffer[2] = sequencebyte;

	// Length
	char *tmpChar;
	tmpChar = convlen(sizeData+2, 16);
	tmp = bitsToBytes(tmpChar, 16);
	buffer[3] = tmp[0]; // LSB
	buffer[4] = tmp[1]; // MSB
	free(tmp);
	free(tmpChar);

	// USB Commands
	buffer[5] = com2;
	buffer[6] = com1;

	long int tot = 7; // bytes used for commands
	int j = 0;

	// this is the case of a read command
	if(data == NULL){
        res = hid_write(handle, buffer, 7);
        return 0;
	}

	// attach data in the buffer
	if((tot+sizeData)<SIZE_SEND){
        // data fit the buffer: load to DMD
		for(i=0; i<sizeData; i++)
            buffer[tot+i] = data[i];
		for(i=tot+sizeData; i<SIZE_SEND; i++)           // se il pacchetto finisce prima perchè devo riempirlo di 0? Posso interromperlo e inviare meno di 65 bytes al dmd
            buffer[i] = 0x00;
		if(!DEBUG){
			res = hid_write(handle, buffer, SIZE_SEND);
			// printf("written bytes = %d \n", res);
		}
		else{
            if(PRINT_BYTES){
                for(k=0; k<SIZE_SEND; k++)
                    printf("%d, ", buffer[k]);
                printf("\n\n");
			}
			else
                writeOnFile("cCommand.txt", buffer, SIZE_SEND);
		}
	}
	else{
        // data exceed buffer size: load in many times (only the first time needs the header + commands)
		for(i=0; i<SIZE_SEND-tot; i++)
            buffer[i+tot] = data[i];
		if(!DEBUG){
			res = hid_write(handle, buffer, SIZE_SEND);
			// printf("written bytes = %d \n", res);
		}
		else{
            if(PRINT_BYTES){
                for(k=0; k<SIZE_SEND; k++)
                    printf("%d, ", buffer[k]);
                printf("\n\n");
            }
			else
                writeOnFile("cCommand.txt", buffer, SIZE_SEND);
		}
		for(i=0; i<SIZE_SEND; i++)
            buffer[i] = 0;
		int i = 1;
		j = SIZE_SEND-tot;
		while(j<sizeData){
			buffer[i] = data[j];
			j++;
			i++;
			if(i%SIZE_SEND == 0){
				if(!DEBUG){
                    res = hid_write(handle, buffer, SIZE_SEND);
                    // printf("written bytes = %d \n", res);
				}
				else{
				    if(PRINT_BYTES){
                        for(k=0; k<SIZE_SEND; k++)
                            printf("%d, ", buffer[k]);
                        printf("\n\n");
				    }
					else
                        writeOnFile("cCommand.txt", buffer, SIZE_SEND);
				}
                i = 1;
			}
		}
		if(i%SIZE_SEND !=0 && i != 1){
			while(i%SIZE_SEND!=0){
				buffer[i] = 0x00;
				j++;
				i++;
            }
			if(!DEBUG){
				res = hid_write(handle, buffer, SIZE_SEND);
				// printf("written bytes = %d \n", res);
			}
			else{
                if(PRINT_BYTES){
                    for(k = 0; k<SIZE_SEND;k++)
                        printf("%d, ", buffer[k]);
                    printf("\n\n");
                }
				else
                    writeOnFile("cCommand.txt", buffer, SIZE_SEND);
			}
		}
	}
	//if(!DEBUG)
	//	checkForErrors(handle);
	//fclose(pFile);
    return 0;
}

void changeMode(hid_device *handle, int mode_){
	unsigned char mode[1];
	mode[0] = mode_;
	printf("DMD Mode changed to %d\n", mode_);
	talkDMD_char(handle, 'w', 0x00, 0x1a, 0x1b, mode, 1);
}

void stopSequence(hid_device *handle){
	unsigned char mode[1] = {0};
	printf("DMD Stop Sequence\n");
	talkDMD_char(handle, 'w', 0x00, 0x1a, 0x24, mode, 1);
}

void startSequence(hid_device *handle){
	unsigned char mode[1] = {2};
	printf("DMD Start Sequence\n");
	talkDMD_char(handle, 'w', 0x00, 0x1a, 0x24, mode, 1);
}

void reset(hid_device *handle){
	unsigned char mode[1] = {2};
	printf("DMD Reset\n");
	talkDMD_char(handle, 'w', 0x00, 0x02, 0x00, mode, 1);
}

void checkForErrors(hid_device *handle){

    // not working correctly (sometimes reads the previous command from buffer instead of the response of the dmd to the check error command)

	unsigned char message[5];
	//sleep(5);
	talkDMD_char(handle, 'r', 0x11, 0x01, 0x00, NULL, 0);
	//sleep(1);
	int res = hid_read(handle, message, 5);
	//printf("read bytes: %d\n", res);
	if(res == -1)
        printf("***HIDAPI ERROR\n");
        /*
    if(message[1] != 0xC0)
        printf("***DMD: Command not found or command failed\n");
    if(message[2] == 0x11)
        printf("Sequence byte mateches\n");
    else
        printf("Sequence byte NOT match\n");
    if(message[5] != 0)
        printf("***DMD ERROR CODE %d\n", message[5]);
        */
        /*
        for(int i=0; i<5; i++)
            printf("%d,", message[i]);
        printf("\n");
        */

}

void checkErrorMessage(hid_device *handle){

    unsigned char message1[64];
    unsigned char message2[64];
    unsigned char message[128];
    int res = 0;
    talkDMD_char(handle, 'r', 0x11, 0x01, 0x01, NULL, 0);
    //sleep(5);
    res = hid_read(handle, message1, 64);
    res = hid_read(handle, message2, 64);
    for(int i=0; i<128; i++){
        if(i<64)
            message[i] = message1[i];
        else
            message[i] = message[i-64];
    }
    printf("%s", message);
    printf("\n");

}

/*
void checkForErrors(hid_device *handle){
	// it does not work. Probably not implemented correctly
	if( hid_error(handle)==NULL)
		printf("errori");
	unsigned char message[1] = {1};
	int res = hid_read(handle, message,1);
	char * flag = convlen(res, 8);
	for(int i = 0; i<8; i++)
	printf("%c", flag[i]);
	printf("\n");
	//if(flag[2]== '1'){
		//printf("errori");
		char *a= NULL;
		command(handle, 'r',0x22,0x01,0x00, a, 0);
		int error = hid_read(handle, message,1);
		printf("error = %d \n", error);
		command(handle, 'r',0x22,0x01,0x01,a, 0);
		message[0] = 128;
		int response = hid_read(handle, message,1);
		printf("response = %d \n", response);

	//}

}
*/

/*
void checkForErrors(hid_device *handle){
	// it does not work. Probably not implemented correctly
	if(hid_error(handle)==NULL)
		printf("errori");
	//unsigned char message[1] = {0x0100};
	//int res = hid_read(handle, message,1);
	command(handle, 'r', 0x22, 0x01, 0x00, NULL, 0);  // TODO sostituirla con talkDMD (forse conviene spostare checkErrors in measure.c)
	unsigned char message[1] = {0x81};
	int res = hid_read(handle, message, 1);
	//char * flag = convlen(res, 8);
	//for(int i = 0; i<8; i++)
	printf("%d", res);
	//getchar();
	//printf("\n");
	//free(flag);
	//if(flag[2]== '1'){
		//printf("errori");
//		char *a= NULL;
//		command(handle, 'r',0x22,0x01,0x00, a, 0);
//		int error = hid_read(handle, message,1);
//		printf("error = %d \n", error);
//		command(handle, 'r',0x22,0x01,0x01,a, 0);
//		message[0] = 128;
//		int response = hid_read(handle, message,1);
//		printf("response = %d \n", response);
	//}
}
*/

/*
int command(hid_device *handle, const char mode, const char sequencebyte, const char com1, const char com2, const char *data, const int sizeData){
	unsigned char buffer[SIZE];
	char flagstring[8];
	if(mode == 'r')
		flagstring[0] = '1';
	else
		flagstring[0] = '0';
	flagstring[1] = '1';
	for(int i=2; i<8; i++)
		flagstring[i] = '0';
	buffer[0] = 0x0;
	int *tmp = bitsToBytes(flagstring, 8);
	buffer[1] = tmp[0];
	free(tmp);
	buffer[2] = sequencebyte;
	char *tmpChar;
	tmpChar = convlen(sizeData+2, 16);
	tmp = bitsToBytes(tmpChar, 16);
	buffer[3] = tmp[0];
	buffer[4] = tmp[1];
	free(tmp);
	free(tmpChar);
	buffer[5] = com2;
	buffer[6] = com1;
	long int tot = 7;
	int j = 0;
	if((tot+sizeData)<SIZE){
		for(int i=0; i<sizeData; i++ ) buffer[tot+i] = data[i];
		for(int i=tot+sizeData; i<SIZE; i++) buffer[i] = 0x00;
		if(!DEBUG){
			int res = hid_write(handle, buffer, SIZE);
			printf("written bytes = %d \n", res);
		}
		else{
			for(int k = 0; k<SIZE;k++){
				printf("%d, ", buffer[k]);
			}
			printf("\n");
		}
	}
	else{
		for(int i=0; i<SIZE-tot; i++) buffer[i+tot] = data[i];
		if(!DEBUG){
			int res = hid_write(handle, buffer, SIZE);
			printf("written bytes = %d \n", res);
		}
		else{
			for(int k=0; k<SIZE; k++){
				printf("%d, ", buffer[k]);
			}
			printf("\n");
		}
		buffer[0] = 0x00;
		for(int i=0; i<SIZE; i++) buffer[i] = 0;
		int i = 1;
		j = SIZE-tot;
		while(j<sizeData){
			buffer[i] = data[j];
			j++;
			i++;
			if(i%SIZE==0){
				if(!DEBUG){
				int res = hid_write(handle, buffer, SIZE);
				printf("written bytes = %d \n", res);
				}
				else{
					for(int k=0; k<SIZE; k++){
						printf("%d, ", buffer[k]);
					}
					printf("\n");
				}
				i =1;
			}
		}
		if(i%SIZE !=0 && i != 1){
			while(i%SIZE!=0){
				buffer[i] =0x00;
				j++;
				i++;
				}
			if(!DEBUG){
				int res = hid_write(handle, buffer, SIZE);
				printf("written bytes = %d \n", res);
			}
			else{
				for(int k=0; k<SIZE; k++){
					printf("%d, ", buffer[k]);
				}
				printf("\n");
			}
		}
	}
	//if(!DEBUG)
	//	checkForErrors(handle);
	return 0;
}
*/
void configureLut(struct Patterns *pattern, int size, int rep){

	// number of LUT entries
	char *im = convlen(size, 11);

	// number of patterns in the sequence
	char *r = convlen(rep, 32);

	// place info in the bit string of LUT configuration
	char string[48];
	int i;
	for(i=0; i<48; i++){
		if(i<32)
			string[i] = r[i];
		else if(i<37)
			string[i] = '0';
		else
			string[i] = im[i-37];
    }
	free(im);
	free(r);
	int *tmp =  bitsToBytes(string, 48);
	for(i=0; i<6; i++)
        pattern->configureLut[i] = tmp[i];
	//command(handle, 'w',0x00,0x1a,0x31,tmp,6);

	free(tmp);
}
void mergeImages(unsigned char ***images, unsigned char ***res){
	int i,j,k;
	// initialization of 3D array
	for(i=0; i<SIZE_PATTERN; i++){
		for(j=0; j<HEIGHT; j++){
			for(k=0; k<WIDTH; k++){
				res[j][k][(2-i/8)] = 0;
			}
		}
	}
	// filling of 3D array with images
	for(i=0; i<SIZE_PATTERN; i++){
		for(j=0; j<HEIGHT; j++){
			for(k=0; k<WIDTH; k++){
				res[j][k][(2-i/8)] += images[i][j][k]*pow_i_dmd(2, i%8);
			}
		}
	}
}

void definePatterns(struct Patterns *pattern, const int index, const int exposure, const int bitdepth, const char *color, const int triggerIn, const int darkTime, const int triggerOut, const int patInd, const int bitPos){

	//char payload[12];
	unsigned char * payload;
	payload = (unsigned char *)malloc(12 * sizeof(unsigned char));
	char * tmpChar = NULL;
	int i;

	// Pattern index
	tmpChar = convlen(index, 16);
	int *index_ = bitsToBytes(tmpChar, 16);
	payload[0] = index_[0];
	payload[1] = index_[1];
	free(index_);
	free(tmpChar);

	// Pattern exposure in microseconds
	tmpChar = convlen(exposure, 24);
	int *exposure_ = bitsToBytes(tmpChar, 24);
	for(i=0; i<3; i++)
        payload[2+i] = exposure_[i];
	free(tmpChar);
	free(exposure_);

	// Pattern options
	char optionsByte[8];
	optionsByte[7] = '1';               // clear pattern after exposure
	char *bitDepth = NULL;
	bitDepth = convlen(bitdepth-1, 3);  // bit-depth of the image
	for(i=0; i<3; i++)
        optionsByte[4+i] = bitDepth[i];
	free(bitDepth);
	for(i=0; i<3; i++)              // LED color
        optionsByte[1+i] = color[i];
	if(triggerIn)                       // trigger to change pattern
        optionsByte[0]='1';
	else
        optionsByte[0]='0';
	int *tmp;
	tmp = bitsToBytes(optionsByte, 8);
	payload[5] = tmp[0];
	free(tmp);

	// Dark time in microseconds
	tmpChar = convlen(darkTime, 24);
	tmp = bitsToBytes(tmpChar, 24);
	free(tmpChar);
	for(i = 0; i<3; i++)
        payload[6+i] = tmp[i];
	free(tmp);

	// trigger out when pattern changes
	if(triggerOut)
        tmpChar = convlen(0, 8);
	else
        tmpChar = convlen(1, 8);
	tmp = bitsToBytes(tmpChar, 8);
	payload[9] = tmp[0];
	free(tmp);
	free(tmpChar);

	// Image pattern index
	char lastBits[16];
	char *patInd_;
	patInd_ = convlen(patInd, 11);

	// Bit position in the image pattern (0-23) -> position of the pattern in the pack of 24 patterns
	char *bitPos_;
	bitPos_ = convlen(bitPos, 5);
	for(i = 0; i<5; i++)
        lastBits[i] = bitPos_[i];
	for(i = 0; i<11; i++)
        lastBits[i+5] = patInd_[i];
	tmp = bitsToBytes(lastBits, 16);
	payload[10] = tmp[0];
	payload[11] = tmp[1];

	// put info in struct Patterns
	for(i=0; i<12; i++)
		pattern->defPatterns[bitPos + SIZE_PATTERN*patInd][i] = payload[i];
	writeOnFile("cPattern.txt", payload, 12);
	//command(handle, 'w',0x00,0x1a,0x34,payload,12);
	free(payload);
	free(tmp);
	free(bitPos_);
	free(patInd_);
}

void defSequence(struct Patterns *pattern, unsigned char ***matrixes, int *exposure, int *trigger_in, int dark_time, int *trigger_out, int repetition, const int size){

	unsigned char *encoded;
	int szEncoded;
	int i = 0;
	int j = 0;
	int k = 0;
	unsigned char ***imageData;
	imageData = (unsigned char ***)malloc(SIZE_PATTERN*sizeof(unsigned char**));
	for(i=0; i<SIZE_PATTERN; i++){
		imageData[i] = (unsigned char **)malloc(HEIGHT*sizeof(unsigned char*));
		for(j = 0; j<HEIGHT; j++ ){
			imageData[i][j] = (unsigned char*)malloc(WIDTH*sizeof(unsigned char));
		}
	}
	unsigned char ***mergedImagesint;
	mergedImagesint = (unsigned char ***)malloc(HEIGHT*sizeof(unsigned char**));
	for(i = 0; i<HEIGHT; i++){
		mergedImagesint[i] = (unsigned char **)malloc(WIDTH*sizeof(unsigned char*));
		for(j = 0; j<WIDTH; j++ ){
			mergedImagesint[i][j] = (unsigned char*)malloc(3*sizeof(unsigned char));
		}
	}
	
	int nBatches = celing_dmd(size, SIZE_PATTERN);
	pattern->numOfBatches = nBatches;
	pattern->bmpLoad = (unsigned char ***)malloc(nBatches*sizeof(unsigned char **));
	pattern->setBmp = (unsigned char (*)[6])malloc(nBatches*sizeof(unsigned char[6]));
	pattern->packNum = (int *)malloc(nBatches*sizeof(int *));
	pattern->bitsPackNum =(int **)malloc(nBatches*sizeof(int*));
	pattern->exposure = (int*)malloc(size*sizeof(int));

	printf("Setting pattern sequence\n");

	i = 0;
	while(i<size || i%SIZE_PATTERN!=0){

        // put data in imageData
		if(i<size){
			for(j=0; j<HEIGHT; j++){
				for(k=0; k<WIDTH; k++){
					imageData[i%SIZE_PATTERN][j][k] = matrixes[i][j][k];
                }
            }
        }
		else{
			for(j=0; j<HEIGHT; j++){
				for(k=0; k<WIDTH; k++){
					imageData[i%SIZE_PATTERN][j][k] = 0;
                }
            }
		}
		i++; // here because from 0 to SIZE_PATTERN-1 we have an array of length SIZE_PATTERN

		// image data reached SIZE_PATTERN dimension -> compress image
		if(i%SIZE_PATTERN == 0){
			struct Node *bitString = NULL;
			int bytecount = 0;
			mergeImages(imageData, mergedImagesint); // pack images
			bytecount = newEncode2(mergedImagesint, &bitString); // compress (enhanced Run-Length Encoding)
			//bytecount = newEncodeDMDScopeFoundary(mergedImagesint, &bitString);
			//bytecount = takeFromTxt(&bitString);

			unsigned char *tmp;
			//printf("bytecount = %d \n", bytecount);
			tmp =(unsigned char*)malloc(bytecount*sizeof(unsigned char));
			struct Node *next;
			int p = 0;

			while(bitString!=NULL){ // all data are in a dynamic LIFO list and here they are taken out
				tmp[p]=bitString->data;
				next = bitString->next;
				free(bitString);
				bitString = next;
				p++;
			}

			encoded =(unsigned char*)malloc(bytecount*sizeof(unsigned char)); // and inverted here
			p=bytecount;
			szEncoded = bytecount;
			while(p>0){
				p--;
				encoded[bytecount-p-1]=tmp[p];
			}
			printf("szEncoded = %d \n", szEncoded);
			//printf("Press ENTER to continue\n");
			//getchar();
			writeOnFile("cNewEncode.txt", encoded, szEncoded);
			free(tmp);
			char c111[3]={'1','1','1'};
			for(j = (i/SIZE_PATTERN-1)*SIZE_PATTERN; j<i && j<size; j++){
				//printf("j = %d \n", j);
				pattern->exposure[j] = exposure[j];
				//define pattern deve essere diviso perchè si indica di quale batch fa parte quello specifico pattern (???)
				definePatterns(pattern, j, exposure[j], 1, c111, trigger_in[j], dark_time, trigger_out[j], (i-1)/SIZE_PATTERN, j-(i/SIZE_PATTERN-1)*SIZE_PATTERN); // single pattern settings
			}

			int idx = (i-1)/SIZE_PATTERN;
			setBmp(pattern, idx, szEncoded); // set image (compressed group of 24 patterns) settings
			bmpLoad(pattern, idx, encoded, szEncoded); // load image (in struct Patterns)
			free(encoded);
		}
	}
	configureLut(pattern, size, repetition); // configure sequence of patterns

	// free memory of images
	for(i = 0; i<SIZE_PATTERN;i++){
		for(int j = 0; j<HEIGHT; j++)
            free(imageData[i][j]);
	}
	for(i = 0; i<SIZE_PATTERN;i++){
		free(imageData[i]);
	}
	free(imageData);

	for(i = 0; i<HEIGHT; i++){
		for(j = 0; j<WIDTH; j++)
            free(mergedImagesint[i][j]);
	}
	for(i = 0; i<HEIGHT; i++){
		free(mergedImagesint[i]);
	}
	free(mergedImagesint);

}

void push(struct Node **head, unsigned char data){
	struct Node* newRef = (struct Node*)malloc(sizeof(struct Node));
	newRef->data = data;
	newRef->next = (*head);
	(*head) = newRef;
}

void allocatePattern_dmd(struct Patterns *p, int nEl){
	p->nEl = nEl;
	p->defPatterns = (unsigned char(*)[12])malloc(nEl*sizeof(unsigned char[12]));
}

int isRowEqual(const unsigned char *a, const unsigned char *b){
	for(int i=0; i<3; i++)
		if(a[i]!=b[i]) return 0;
	return 1;
}

void setBmp(struct Patterns *pattern, const int  index, const int size){

	unsigned char payload[6];
	char index_[16];
	char *tmp;
	int *tmp2;
	int i;

	// image index (only first 5 bits, the others are reserved and put to 0)
	tmp = convlen(index, 5);
	for(i=0; i<11; i++)
        index_[i] = '0';
	for(i=0; i<5; i++)
        index_[i+11] = tmp[i];
	free(tmp);
	tmp2 = bitsToBytes(index_, 16);
	for(i=0; i<2; i++)
        payload[i] = tmp2[i];
	free(tmp2);

	// number of bytes in the compressed image including the 48 bytes header
	int *total;
	tmp = convlen(size, 32);
	total = bitsToBytes(tmp, 32);
	free(tmp);
	for(i=0; i<4; i++)
        payload[i+2] = total[i];
	free(total);

	// put info in struct Patterns
	for(i=0; i<6; i++)
        pattern->setBmp[index][i] = payload[i];
	writeOnFile("cSetBmp.txt", payload, 6);
}

void bmpLoad(struct Patterns *pattern, const int index, const unsigned char *image, const int size){

	int packNum = size/504 + 1; // upload is limited to 504 bytes (DMD has a buffer of 512 bytes)
	pattern->bmpLoad[index] = (unsigned char **)malloc(packNum*sizeof(unsigned char*));
	pattern->packNum[index] = packNum;
	pattern->bitsPackNum[index] = (int *)malloc(packNum*sizeof(int));
	int i,j;
	
	for(i=0; i<packNum; i++){
		//if(i%100 == 0) printf("%d di %d\n", i, packNum);
		unsigned char *payload;
		int bits;
		char *leng;

		// number of bytes in the packet i-th
		if(i<packNum-1){
			leng = convlen(504, 16);
			bits = 504;
		}
		else{
			leng = convlen(size%504, 16);
			bits = size%504;
		}
		pattern->bitsPackNum[index][i] = bits+2; // total length of data include also the first two bytes
		int *tmp;
		tmp = bitsToBytes(leng, 16);
		free(leng);
		payload = (unsigned char*)malloc((bits+2)*sizeof(unsigned char));
		for(j = 0; j<2; j++)
            payload[j] = tmp[j];
		free(tmp);

		// content of the packet i-th
		for(j=0; j<bits; j++)
            payload[j+2] = image[504*i+j];

        // all data is saved in struct Patterns -> bmpLoad
		pattern->bmpLoad[index][i] = (unsigned char *)malloc((bits+2)*sizeof(unsigned char));
		for(j=0; j<bits+2; j++)
            pattern->bmpLoad[index][i][j] = payload[j];
		//command(handle, 'w',0x11,0x1a,0x2b, payload, bits+2);

		free(payload);
	}
}

int newEncode2(unsigned char ***image, struct Node **bitString){

	// BMP header
	int byteCount = 48; // header length (bytes)
	char *tmpChar;
	int *res;
	int i,j,k,n;

	// Signature
	push(bitString, 0x53);
	push(bitString, 0x70);
	push(bitString, 0x6c);
	push(bitString, 0x64);

	// Image width
	tmpChar = convlen(WIDTH, 16);
	res = bitsToBytes(tmpChar, 16);
	push(bitString, res[0]);
	push(bitString, res[1]);
	free(tmpChar);
	free(res);

	// Image heigth
	tmpChar = convlen(HEIGHT, 16);
	res = bitsToBytes(tmpChar, 16);
	push(bitString, res[0]);
	push(bitString, res[1]);
	free(tmpChar);
	free(res);

	// Number of bytes in the encoded image data
	for(i=0; i<4; i++) push(bitString, 0x00);
	struct Node *link = *bitString; // image size is not known a priori (added at the end of the encoding)

	// Reserved
	for(i=0; i<8; i++) push(bitString, 0xff);

	// Background color + Reserved
	for(i=0; i<5; i++) push(bitString, 0x00);

	// Compression
	push(bitString, 0x02);

	// Reserved
	push(bitString, 0x01);
	for(i=0; i<21; i++) push(bitString, 0x00);

	// Here we have the actual encoding
	// enhanced Run-Length encoding
	// controlbyte1, controlbyte2, controlbyte3, result
	// 0,0,NA = end of line
	// 0,1,0 = end of image
	// 0,1,n = copy n pixels from previous line
	// 0,n,NA = n uncompressed pixels
	// n>1,NA,NA = repeat following n pixels
	// if n<128 encode with 1 byte, if n>=128 encode with 2 bytes: byte 0 = (n&0x7f)|0x80, byte 1 = n>>7
	n = 0;
	i = 0;
	j = 0;

	while(i<HEIGHT){
		while(j<WIDTH){
			if(i>0 && isRowEqual(image[i][j],image[i-1][j])){
				for(; j<WIDTH && isRowEqual(image[i][j],image[i-1][j]); j++, n++);
                push(bitString, 0x00);
                push(bitString, 0x01);
                byteCount += 2;
                if(n>=128){
                    push(bitString, (n & 0x7f) | 0x80);
                    push(bitString, n>>7);
                    byteCount += 2;
                }
                else{
                    push(bitString, n);
                    byteCount++;
				}
                n = 0;
			}
			else{
				if(j<1919 && isRowEqual(image[i][j],image[i][j+1])){
					n++;
					for(; j<WIDTH-1 && isRowEqual(image[i][j],image[i][j+1]); n++, j++);
					if(n>=128){
						push(bitString, (n & 0x7f) | 0x80);
						push(bitString, n>>7);
						byteCount += 2;
					}
					else{
						push(bitString, n);
						byteCount++;
					}
					push(bitString, image[i][j-1][0]);
					push(bitString, image[i][j-1][1]);
					push(bitString, image[i][j-1][2]);
					byteCount += 3;
					n = 0;
					j++;
				}
				else{
					if(j>WIDTH-3 ||
						isRowEqual(image[i][j+1],image[i][j+2]) ||
						(i>0 && isRowEqual(image[i][j+1],image[i-1][j+1])) ||
						(i==0 && isRowEqual(image[i][j+1],image[HEIGHT-1][j+1]))){
						push(bitString, 0x01);
						byteCount++;
						push(bitString, image[i][j][0]);
						push(bitString, image[i][j][1]);
						push(bitString, image[i][j][2]);
						byteCount += 3;
						j++;
						n = 0;
					}
					else{
						push(bitString, 0x00);
						byteCount++;
						struct Node *toAppend = NULL;
						for(; !isRowEqual(image[i][j],image[i][j+1]) &&( (i >0 && isRowEqual(image[i][j],image[i-1][j])) || (i == 0 && isRowEqual(image[i][j],image[HEIGHT-1][j]))); n++, j++){//cambiato qui
							push(&toAppend, image[i][j][0]);
							push(&toAppend, image[i][j][1]);
							push(&toAppend, image[i][j][2]);
						}
						if(n>=128){
							push(bitString, (n & 0x7f) | 0x80);
							push(bitString, n>>7);
							byteCount += 2;
						}
						else{
							push(bitString, n);
							byteCount++;
						}
						int *tmp;
						tmp =(int*)malloc(n*sizeof(n));
						struct Node *next;
						for(k=0; toAppend!=NULL; k++){
							tmp[k] = toAppend->data;
							next = toAppend->next;
							free(toAppend);
							toAppend = next;
                        }
						for(k=n; k>0; k++)
							push(bitString, tmp[k-1]);
						byteCount += n;
						free(tmp);
						n = 0;
                    }
                }
            }
        }
		j = 0;
		i++;
		push(bitString, 0x00); // end of line
		push(bitString, 0x00);
		byteCount += 2;
    }
	push(bitString, 0x00); // end of image
	push(bitString, 0x01);
	push(bitString, 0x00);
	byteCount += 3;
	while(byteCount%4 != 0){
		push(bitString, 0x00);  // perchè?? una volta finita l'immagine non dovrebbero esserci più byte
		byteCount++;
	}
	int size = byteCount;
	int *total;
	tmpChar = convlen(size, 32);
	total = bitsToBytes(tmpChar, 32);
	for(int q=0; q<4; q++){
		link->data = total[3-q]; // insert the size of the image in the header
		link = link->next;
	}
	free(tmpChar);
	free(total);
	return byteCount;
}

int takeFromTxt(struct Node **bitString){
	FILE* file = fopen ("pyNewEncode.txt", "r");
 	int i = 0;
	int byteCount = 0;
  	fscanf (file, "%d", &i);
  	while (!feof (file)){
        byteCount++;
	    push(bitString, i);
	    fscanf (file, "%d", &i);
		printf("%d\n",i);
    }
	fclose (file);
	return byteCount;
}

void readBMP(char* filename, int *** image)
{
	//https://stackoverflow.com/questions/9296059/read-pixel-value-in-bmp-file
	//io uso 3 canali qui
	//ma può essere solo b/n
	//NOT TESTED

    int i;
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];

    // read the 54-byte header
    fread(info, sizeof(unsigned char), 54, f);

    // extract image height and width from header
    int width = *(int*)&info[18]; //devo fare assert che sia uguale a mio widthS
    int height = *(int*)&info[22];

    // if height < 0 the image is stored from top to bottom
    int heightSign = 1;
    if (height < 0){
        heightSign = -1;
    }

    // allocate 3 bytes per pixel
    long int size = 3 * width * abs(height);
    unsigned char* data = (unsigned char*)malloc(size*sizeof(unsigned char));

    // read the rest of the data at once
    fread(data, sizeof(unsigned char), size, f);
    fclose(f);

    if(heightSign == -1){
        for(i=0; i<size; i+=3){
            // prendo solo da un canale.(se è RGB mi interessa solo 1)
            int idx = i/3;
            if(data[i]>127) (*image)[idx/width][idx%width]=1;
            else (*image)[idx/width][idx%width]=0;
        }
    }
    else{
        for(i=0; i<size; i+=3){
            // prendo solo da un canale.(se è RGB mi interessa solo 1)
            int idx = i/3;
            if(data[size-i-1]>127) (*image)[idx/width][idx%width]=1;
            else (*image)[idx/width][idx%width]=0;
        }
    }
}

int pow2_i_dmd(const int exp){
	int res = 1;
	for(int i=0; i<exp; i++)
		res *= 2;
	return res;
}

int pow_i_dmd(const int b,const int exp){
	int res=1;
	for(int i=0; i<exp; i++)
		res*=b;
	return res;
}

int celing_dmd(const int a, const int b){
	if(a%b == 0) return a/b;
	else return a/b +1;
}

/*
command is the function that does the comunication with the dmd, every other function that wants to comunicate with the dmd need to use this function
There are two command function implemented because one could want to pass a vector of int and char
*/
/*
int command(hid_device *handle, const char mode, const char sequencebyte, const char com1, const char com2, const int *data, const int sizeData){
	char *tmp;
	tmp = (char *)malloc(sizeData*sizeof(char));
	for(int i = 0; i<sizeData; i++)
		tmp[i] = (char)data[i];

	int res = command(handle, mode, sequencebyte, com1,com2,tmp,sizeData);

	free(tmp);
	return res;
}
*/

/*
int newEncodeDMDScopeFoundary(int ***image, struct Node **bitString){
	int byteCount;
	printf("image[0][0][0]=%d\n", image[0][0][0]);
	byteCount=48;
	push(bitString, 0x53);
	push(bitString, 0x70);
	push(bitString, 0x6c);
	push(bitString, 0x64);
	char*tmpChar;
	tmpChar = convlen(1920,16);
	int *res= bitsToBytes(tmpChar,16);
	push(bitString, res[0]);//dovrebbero essere solo 2 byte
	push(bitString, res[1]);
	free(res);
	free(tmpChar);
	tmpChar=convlen(1080,16);
	res= bitsToBytes(tmpChar,16);
	free(tmpChar);
	push(bitString, res[0]);//dovrebbero essere solo 2 byte
	push(bitString, res[1]);
	free(res);
	//tmpChar = convlen(0,32);
	//res=bitsToBytes(tmpChar,32);
	//free(tmpChar);

	for(int i = 0; i<4; i++) push(bitString, 0x00);
	struct Node *link = *bitString;
	//free(res);
	for(int i = 0; i<8; i++) push(bitString, 0xff);
	for(int i = 0; i<5; i++) push(bitString, 0x00);
	push(bitString, 0x02);
	push(bitString, 0x01);
	for(int i = 0; i<21; i++) push(bitString, 0x00);
	int n=0;
	//fino a qui va bene
	//da qui bho
	for(int i = 0; i<1080; i++){
		for(int j = 0; j<1920; j++){
			if(i>0){
				printf("\n byteCount  = %d \n",byteCount);

				if(isRowEqual(image[i][j],image[i-1][j])){
					while(j<1920 &&isRowEqual(image[i][j],image[i-1][j])){
						n++;
						j++;}
					push(bitString, 0x00);
					push(bitString, 0x01);
					byteCount+=2;
					if(n>=128){

						push(bitString, (n & 0x7f) | 0x80);
						push(bitString, n>>7);
						byteCount+=2;
					}else{
						push(bitString, n);
						byteCount++;
					}
					n=0;
				}else{//if(isRowEqual(image[i][j],image[i-1][j]))
					if(j<1919){
						if(isRowEqual(image[i][j],image[i][j+1])){
							n++;
							while(j<1919 && isRowEqual(image[i][j],image[i][j+1])){
								n++;
								j++;
							}
							if(n>=128){

								push(bitString, (n & 0x7f) | 0x80);
								push(bitString, n>>7);
								byteCount+=2;
							}else{
								push(bitString, n);
								byteCount++;
							}
							push(bitString, image[i][j][0]);
							push(bitString, image[i][j][1]);
							push(bitString, image[i][j][2]);
							byteCount+=3;
							j++;//TODO<-----------------------
							n=0;
						}else if(j>1917 || isRowEqual(image[i][j+1],image[i][j+2]) || isRowEqual(image[i][j+1],image[i-1][j+1])){
							push(bitString, 0x01);
							byteCount++;
							push(bitString, image[i][j][0]);
							push(bitString, image[i][j][1]);
							push(bitString, image[i][j][2]);
							byteCount+=3;
							j++;//TODO<----------------
							n=0;
						}else{//se j<1919e le condizioni isRowEqual non si verificano
							push(bitString, 0x00);

							byteCount++;
							struct Node *toAppend=NULL;
							while(j<1919 && !isRowEqual(image[i][j],image[i][j+1])){
								n++;//tutti quelli che sono diversi
								push(&toAppend, image[i][j][0]);
								push(&toAppend, image[i][j][1]);
								push(&toAppend, image[i][j][2]);
								j++;
							}
							if(n>=128){

								push(bitString, (n & 0x7f) | 0x80);
								push(bitString, n>>7);
								byteCount+=2;
							}else{
								push(bitString, n);
								byteCount++;
							}
							//aggiungere le cose contenute in toAppend
							//problema==sono aggiunti al contrario
							int *tmp;
							tmp =(int*)malloc(n*sizeof(n));
							struct Node *next;
							for(int k = 0; toAppend!=NULL; k++){
								tmp[k]=toAppend->data;
								next = toAppend->next;
								free(toAppend);
								toAppend = next;
							}
							for(int k =n; k>0; k++)
								push(bitString, tmp[k-1]);
							byteCount+=n;
							free(tmp);
							n=0;
						}

					}else if(j==1919){ //if(j<1919)
						push(bitString, 0x01);
						byteCount++;
						push(bitString, image[i][j][0]);
						push(bitString, image[i][j][1]);
						push(bitString, image[i][j][2]);
						byteCount+=3;
						j++;
						n=0;
					}
				}//else di if(isRowEqual(image[i][j],image[i-1][j]))
			}else{//if(i>0) quindi i == 0
				if(j<1919){

					if(isRowEqual(image[i][j],image[i][j+1])){

						n++;
						while(j<1919 && isRowEqual(image[i][j],image[i][j+1])){
							//printf("\n j= %d  n = %d\n",j, n);

							n++;
							j++;
						}
						if(n>=128){
							//printf("\n j= %d  n = %d\n",j, n);
							//getchar();
							push(bitString, (n & 0x7f) | 0x80);
							push(bitString, n>>7);
							byteCount+=2;
						}else{
							push(bitString, n);
							byteCount++;
						}
						push(bitString, image[i][j][0]);
						push(bitString, image[i][j][1]);
						push(bitString, image[i][j][2]);
						byteCount+=3;
						j++;//TODO<--------------------
						n=0;
					}else if(j>1917 || isRowEqual(image[i][j+1],image[i][j+2]) ||
						(i >0 && isRowEqual(image[i][j+1],image[i-1][j+1])) ||
						(i == 0 && isRowEqual(image[i][j+1],image[HEIGHT-1][j+1]))){						push(bitString, 0x01);
						byteCount++;
						push(bitString, image[i][j][0]);
						push(bitString, image[i][j][1]);
						push(bitString, image[i][j][2]);
						byteCount+=3;
						j++;//TODO;<------------------
						n=0;
					}else{//se j<1919e le condizioni isRowEqual non si verificano
						push(bitString, 0x00);
						byteCount++;
						struct Node *toAppend=NULL;
						while(j<1919 && !isRowEqual(image[i][j],image[i][j+1])){
							n++;//aggiungo tutti quelli diversi
							push(&toAppend, image[i][j][0]);
							push(&toAppend, image[i][j][1]);
							push(&toAppend, image[i][j][2]);
							j++;
						}
						if(n>=128){

							push(bitString, (n & 0x7f) | 0x80);
							push(bitString, n>>7);
							byteCount+=2;
						}else{
							push(bitString, n);
							byteCount++;
						}
						//aggiungere le cose contenute in toAppend
						//problema==sono aggiunti al contrario
						int *tmp;
						tmp =(int*)malloc(n*sizeof(n));
						struct Node *next;
						for(int k = 0; toAppend!=NULL; k++){
							tmp[k]=toAppend->data;
							next = toAppend->next;
							free(toAppend);
							toAppend = next;
						}
						for(int k =n; k>0; k--)
							push(bitString, tmp[k-1]);
						byteCount+=n;
						free(tmp);
						n=0;
					}

				}else if(j == 1919){ //if(j==1919)
					push(bitString, 0x01);
					byteCount++;
					push(bitString, image[i][j][0]);
					push(bitString, image[i][j][1]);
					push(bitString, image[i][j][2]);
					byteCount+=3;
					j++;//TODO<---------------
					n=0;
				}


			}
		}//while(j<SIZE_H)
		push(bitString, 0x00);
		push(bitString, 0x00);
		byteCount+=2;

	}//while(i<SIZE_W)
	push(bitString, 0x00);
	push(bitString, 0x01);
	push(bitString, 0x00);
	byteCount+=3;
	while(byteCount%4!=0){

		push(bitString, 0x00);
		byteCount++;
	}
	int size = byteCount;
	int *total;

	tmpChar = convlen(size,32);
	total = bitsToBytes(tmpChar,32);

	for(int q = 0; q<4; q++){//per riempiere i primi 4
		link->data=total[3-q];
		link = link->next;
	}
	free(tmpChar);
	free(total);
	return byteCount;

}
*/

/*
We want to use command pattern if we want a fast comunication with the dmd.
all the data is processed before the execution.
This function only perform the upload to the dmd (via the command function)
*/
/*
void commandPattern(hid_device *handle,struct Patterns * pattern, const int szPattern){
	//I only need to pass the data that we got from defSequence
	//all the rest must be processed during initialization or garbage collection
	for(int i = 0; i<szPattern; i++){
		//stopSequence(handle);
		int totExposure = 0;
		for(int j = 0; j<pattern[i].nEl; j++){
			totExposure +=pattern[i].exposure[j];
			command(handle,'w',0x00,0x1a,0x34,pattern[i].defPatterns[j],12);
			}
		//configureLut
		command(handle,'w',0x00,0x1a,0x31,pattern[i].configureLut,6);
		//setBmp
		command(handle,'w',0x00,0x1a,0x2a,pattern[i].setBmp,6);
		//bmpLoad
		for(int j = 0; j<pattern[i].packNum; j++){
			command(handle,'w',0x11,0x1a,0x2b,pattern[i].bmpLoad[j],pattern[i].bitsPackNum[j]);
		}
		stopSequence(handle);
		startSequence(handle);
		sleep(totExposure/1e6);//need to wait for the pattern to finish
					//sleep must be in input a number >0.001
	}

}
*/

