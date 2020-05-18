/*

for(int i = 0; i<line;i++){ 
if(t[set_index][i].valid == 1) {
	if(t[set_index][i].tagger == tag) {
//ask question here about validity with 0 but address is there.
	hit++;
		if(character == 'R') {
		break;
		}	
		else if(character == 'W'){
		mem_write++;
		break;
		}
	
	}//
	else if(t[set_index][i].tagger != tag) {
	//do fifo
	//it is a miss
	miss++;
		if(character == 'R') {
		mem_read++;
		}
		else if (character =='W') {
		mem_read++;
		mem_write++;
		}
	//FIFO 
	for(int k = 0; k<set; k++) {
		if(m==1){
break;
}
		for (int j = 0; j<line;j++){
			if(t[k][j].time == timerchecker) {
			timerchecker++;
			timer++;
			t[k][j].time = timer;
			t[k][j].valid = 1;
			t[k][j].tagger = tag;
			m = 1;
			break;
			}	
		}
	}	
break;
}
}

else if(t[set_index][i].valid != 1) {
//that means it couldnt find the tag.
miss++;
	if(character == 'R') {
	mem_read++;
	}
	else if(character == 'W') {
	mem_read++;
	mem_write++;	
	}
//start by comparing timerrchecker with every single one, the moment you find it increase timerchecker by 1 so next time it knows the next least number is that. 
	timer++;
	t[set_index][i].tagger = tag;
	t[set_index][i].time = timer;
	t[set_index][i].valid = 1;
//must return Memory read:
//	     	Memory write:
//	     	Cache read:
//	     	cache write:
//	     	just print them out pretty much. 
//do while statement with the file, if w then do w function, if read then do read function
//
break;
}

*/



#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define DEBUG 1
// if(DEBUG) printf("debugging statement\n");
typedef struct {
unsigned int valid;//checks if empty or not
unsigned long int tagger; //cecks if address is available or not
unsigned int time; //helps with replacement policy
} santosh;

void direct(int setbits,int set,int blockbits,int line,FILE *fp){
santosh **t;
t = malloc(set*sizeof(santosh*));
for (int i = 0; i < set; i++){
    t[i] = malloc(line * sizeof(santosh));
}
for (int i = 0; i < set; i++) {
	for(int j = 0; j<line; j++) {
		t[i][j].tagger = 0;
		t[i][j].time = 0;
		t[i][j].valid = 0;
}
}
//if(DEBUG) printf("debugging statement\n");
int mask = (1<<setbits)-1;
int hit = 0;
int miss = 0;
int mem_write = 0;
int mem_read = 0;
char character;
int address = 0;
//int checker = 0;
int timer = 0;
int i = 0;
//int checker2 = 0;
//change if next empty line must be filled, first, if no empty lines then switch with the one that we are told to directly, over write it
//int timerchecker = 1;
while(fscanf(fp,"%c %x\n", &character, &address)!=EOF){
//if(DEBUG) printf("debugging statement\n");
//printf("%d\n",address);
//timer =0;
int m = 0;
int l = 0;
int n = 0; //counter for validity and stuff
unsigned int set_index = (address >> blockbits) & mask;
unsigned long tag = (address >> blockbits) >> setbits;
 i = 0;
//printf("%d\n",line);
while (i < line) {
//if(m==1){break;}
//printf("%d\n",i);
//if(DEBUG) printf("debugging statement\n");
	if(t[set_index][i].valid == 1) {
		if(t[set_index][i].tagger == tag) {
		m = 1; //m being 1 means it is true.
			if(character == 'R'){
			hit++;
			break;
			}
			else if(character == 'W'){
		//	if(DEBUG) printf("debugging statement\n");
			hit++;
			mem_write++;
			break;	
			}
	//	break;
		}
		else if(t[set_index][i].tagger != tag) {
		l++; //THIS SIGNIFIES WHETHER OR NOT WE SHOULD DO FIFO, IF l IS EQUAL TO LINES THEN WE MUST FIFO SINCE VALIDITY IS 1 AND ALL OF THEM DONT EQUAL TAG
		}
	}
	else if(t[set_index][i].valid == 0) { 	//couldnt find the tag if n is equal to lines.
	n++;
	}	
i++;
}
if (n > 0 && m!=1) {//that means both lines were invalid so we have to do miss++ and write to it.THIS MEANS THERE IS OPEN SPACE.
	if(character == 'R'){
	miss++;
	mem_read++;
	}
	else if(character == 'W'){
	miss++;
	mem_read++;
	mem_write++;
	}


	//find smallest element within the set
			int largest = t[set_index][0].time; 
	for(int j = 1; j<line; j++){
		if(t[set_index][j].time>largest){
		largest = t[set_index][j].time;
		}
	//find smallest element within the set
}	

	for(int j = 0;j<line;j++) {
		if(t[set_index][j].valid== 0) {
		timer = largest + 1;
		t[set_index][j].tagger = tag;
		t[set_index][j].time = timer;
		t[set_index][j].valid = 1;
		break;
		}

		
	}	

		
//now write to the cache
//doesnt matter where
//t[set_index][

}
if(l == line) {
	if(character == 'R') {
	mem_read++;
	miss++;
	}
	else if(character == 'W') {
	miss++;
	mem_read++;
	mem_write++;
	}
//this means we must do FIFO, it is also a miss.
	//FIFO RIGHT HERE
	int smallest = t[set_index][0].time; 
	for(int j = 1; j<line; j++){
		if(t[set_index][j].time<smallest){
		smallest = t[set_index][j].time;
		}
	//find smallest element within the set
}
		int largest = t[set_index][0].time; 
	for(int j = 1; j<line; j++){
		if(t[set_index][j].time>largest){
		largest = t[set_index][j].time;
		}
	//find smallest element within the set
}
	//find smallest element within the set

	//NOW WE FOUND SMALLEST TIMER
	for(int j = 0; j<line; j++){
		if(t[set_index][j].time == smallest){
		//NOW REPLACE AND UPDATE EVERYTHING
		timer = largest+1;
		t[set_index][j].tagger = tag;
		t[set_index][j].time = timer;
		t[set_index][j].valid = 1;
		break;
		}		
	}

//if (m != 1) {
//if m doesnt equal to one that means the lines did not match up with the tags therefore we must do FIFO.

}





}





//print all 4 stuff
printf("Memory reads:%d\n",mem_read);
printf("Memory writes:%d\n",mem_write);
printf("Cache hits:%d\n",hit);
printf("Cache misses:%d\n",miss);
for (int i = 0; i < set; i++){
    free(t[i]);
}
}

santosh** coldcache(int set, int line) {
//cache2 = (struct santosh**)malloc(sizeof(struct santosh)*set);
santosh **t;
t = malloc(set*sizeof(santosh*));
for (int i = 0; i < set; i++){
    t[i] = malloc(line * sizeof(santosh));
}
for (int i = 0; i < set; i++) {
	for(int j = 0; j<line; j++) {
		t[i][j].tagger = 0;
		t[i][j].time = 0;
		t[i][j].valid = 0;
}
}
return t;
}

santosh **t;
int mem_read = 0;
void prefetch(int prefetchsize,int setbits, int set, int blockbits, int line, unsigned long tag, int address,int blocksize) {
int pre_address = address;
int timer = 0;
//pre_address1 = address;
int jay = 0;
for (jay = 0; jay<prefetchsize;jay++) {
//timer = 0;
//int x = 0;
//int y = 0;
int mm = 0;
int ll = 0;
int nn = 0;
int ii= 0;
//pre_address1 = pre_address+blocksize;
pre_address = pre_address+blocksize;
unsigned int preset = (pre_address>>blockbits) & ((1<<setbits)-1);
unsigned long pretag = (pre_address>>blockbits) >>setbits;
	while(ii<line) {
	if(t[preset][ii].valid == 1) {
		if(t[preset][ii].tagger == pretag) {
			mm = 1;//THIS TELLS US ITS A HIT WE DONT HAVE TO DO ANYTHING
			//break;
		}
		else if (t[preset][ii].tagger != pretag) {
		ll++;//COUNTING THE LINES THAT ALREADY HAVE A TAG IN IT BUT IS NOT THE TAG WE ARE LOOKING FOR
	
			}
		}
	else if (t[preset][ii].valid == 0){
	nn++;//SIGNIFIES THAT THERE IS AN OPEN SPACE
		}
ii++;
	}
if (nn > 0 && mm != 1){//this means there is space
//find the largest within the n amount of prefetch size sets.
//mem_read++;
int largest = t[preset][0].time;
	for(int jj = 1; jj<line; jj++) {
		if(t[preset][jj].time>largest) {
		largest = t[preset][jj].time;
		}	
	}
	for(int jj = 0; jj<line;jj++) {
		if(t[preset][jj].valid == 0) {
		timer = largest+1;
		t[preset][jj].tagger = pretag;
		t[preset][jj].time = timer;
		t[preset][jj].valid = 1;
		break;
		}
	}

mem_read++;
//return;
}
 if(ll == line) {
//mem_read++;
	int smallest = t[preset][0].time;
	for(int jj = 1; jj<line; jj++) {
	if(t[preset][jj].time<smallest){
	smallest = t[preset][jj].time;
		}
	}
	int largest = t[preset][0].time;
	for(int jj = 1; jj<line;jj++) {
		if(t[preset][jj].time>largest){
		largest = t[preset][jj].time;
		}	
	}
	for(int jj = 0; jj<line;jj++) {
		if(t[preset][jj].time == smallest) {
		timer = largest +1;		
		t[preset][jj].tagger = pretag;
		t[preset][jj].time = timer;
		t[preset][jj].valid = 1;
		break;
		}	


	}

mem_read++;
//return;
}
 //imem_read++;



//mem_read--;
}
//mem_read--;
//printf("%d\n",mem_read);
//printf("%di\n",jay);
} 
//mem_read--;
void directprefetch(int setbits,int set,int blockbits, int line,FILE *fp,int prefetchsize,int blocksize) {
t = coldcache(set,line);
//if(DEBUG) printf("debugging statement\n");
int mask = (1<<setbits)-1;
int hit = 0;
int miss = 0;
int mem_write = 0;
//int mem_read = 0;
char character;
int address = 0;
//int checker = 0;
int timer = 0;
int i = 0;
//int checker2 = 0;
//change if next empty line must be filled, first, if no empty lines then switch with the one that we are told to directly, over write it
//int timerchecker = 1;

while(fscanf(fp,"%c %x\n", &character, &address)!=EOF){
//if(DEBUG) printf("debugging statement\::");
//printf("%d\n",address);
//timer =0;
//printf("%c\n",character);
if(character == '#'){
break;
}
int m = 0;
int l = 0;
int n = 0; //counter for validity and stuff
unsigned int set_index = (address >> blockbits) & mask;
unsigned long tag = (address >> blockbits) >> setbits;
 i = 0;
//printf("%d\n",line);
while (i < line) {
//if(m==1){break;}
//printf("%d\n",i);
//if(DEBUG) printf("debugging statement\n");
	if(t[set_index][i].valid == 1) {
		if(t[set_index][i].tagger == tag) {
		m = 1; //m being 1 means it is true.
			if(character == 'R'){
			hit++;
			//break;
			}
			else if(character == 'W'){
		//	if(DEBUG) printf("debugging statement\n");
			hit++;
			mem_write++;
			//break;	
			}
	//	break;
		}
		else if(t[set_index][i].tagger != tag) {
		l++; //THIS SIGNIFIES WHETHER OR NOT WE SHOULD DO FIFO, IF l IS EQUAL TO LINES THEN WE MUST FIFO SINCE VALIDITY IS 1 AND ALL OF THEM DONT EQUAL TAG
		}
	}
	else if(t[set_index][i].valid == 0) { 	//couldnt find the tag if n is equal to lines.
	n++;
	}	
i++;
}
if (n > 0 && m!=1) {//that means both lines were invalid so we have to do miss++ and write to it.THIS MEANS THERE IS OPEN SPACE.
	if(character == 'R'){
	miss++;
	mem_read++;
	}
	else if(character == 'W'){
	miss++;
	mem_read++;
	mem_write++;
	}


	//find smallest element within the set
			int largest = t[set_index][0].time; 
	for(int j = 1; j<line; j++){
		if(t[set_index][j].time>largest){
		largest = t[set_index][j].time;
		}
	//find smallest element within the set
}	

	for(int j = 0;j<line;j++) {
		if(t[set_index][j].valid== 0) {
		timer = largest + 1;
		t[set_index][j].tagger = tag;
		t[set_index][j].time = timer;
		t[set_index][j].valid = 1;
		break;
		}

		
	}	

		
//now write to the cache
//doesnt matter where
//t[set_index][
prefetch(prefetchsize, setbits, set, blockbits, line, tag, address, blocksize);

}
if(l == line) {
	if(character == 'R') {
	mem_read++;
	miss++;
	}
	else if(character == 'W') {
	miss++;
	mem_read++;
	mem_write++;
	}
//this means we must do FIFO, it is also a miss.
	//FIFO RIGHT HERE
	int smallest = t[set_index][0].time; 
	for(int j = 1; j<line; j++){
		if(t[set_index][j].time<smallest){
		smallest = t[set_index][j].time;
		}
	//find smallest element within the set
}
		int largest = t[set_index][0].time; 
	for(int j = 1; j<line; j++){
		if(t[set_index][j].time>largest){
		largest = t[set_index][j].time;
		}
	//find smallest element within the set
}
	//find smallest element within the set

	//NOW WE FOUND SMALLEST TIMER
	for(int j = 0; j<line; j++){
		if(t[set_index][j].time == smallest){
		//NOW REPLACE AND UPDATE EVERYTHING
		timer = largest+1;
		t[set_index][j].tagger = tag;
		t[set_index][j].time = timer;
		t[set_index][j].valid = 1;
		break;
		}		
	}

//if (m != 1) {
//if m doesnt equal to one that means the lines did not match up with the tags therefore we must do FIFO.
prefetch(prefetchsize, setbits, set, blockbits, line, tag, address, blocksize);

}





}





//print all 4 stuff
//mem_read--;
printf("Memory reads:%d\n",mem_read);
printf("Memory writes:%d\n",mem_write);
printf("Cache hits:%d\n",hit);
printf("Cache misses:%d\n",miss);
for (int i = 0; i < set; i++){
    free(t[i]);
}

/*santosh **t;
t = malloc(set*sizeof(santosh*));
for (int i = 0; i < set; i++){
    t[i] = malloc(line * sizeof(santosh));
}
for (int i = 0; i < set; i++) {
	for(int j = 0; j<line; j++) {
		t[i][j].tagger = 0;
		t[i][j].time = 0;
		t[i][j].valid = 0;
}
}
//if(DEBUG) printf("debugging statement\n");
int mask = (1<<setbits)-1;
int hit = 0;
int miss = 0;
int mem_write = 0;
int mem_read = 0;
char character;
int address = 0;
//int checker = 0;
int timer = 0;
int i = 0;
 int pre_address = 0;
//int checker2 = 0;
//change if next empty line must be filled, first, if no empty lines then switch with the one that we are told to directly, over write it
//int timerchecker = 1;
while(fscanf(fp,"%c %x\n", &character, &address)!=EOF){

//if(DEBUG) printf("debugging statement\n");
//printf("%d\n",address);
//timer =0;
int m = 0;
int l = 0;
int n = 0; //counter for validity and stuff
unsigned int set_index = (address >> blockbits) & mask;
unsigned long tag = (address >> blockbits) >> setbits;
 i = 0;
//printf("%d\n",line);
while (i < line) {
//if(m==1){break;}
//printf("%d\n",i);
//if(DEBUG) printf("debugging statement\n");
	if(t[set_index][i].valid == 1) {
		if(t[set_index][i].tagger == tag) {
		m = 1; //m being 1 means it is true.
		//break;
			if(character == 'R'){
			hit++;
			break;
			}
			else if(character == 'W'){
		//	if(DEBUG) printf("debugging statement\n");
			hit++;
			mem_write++;
			break;	
			}
	//	break;
		}
		else if(t[set_index][i].tagger != tag) {
		l++; //THIS SIGNIFIES WHETHER OR NOT WE SHOULD DO FIFO, IF l IS EQUAL TO LINES THEN WE MUST FIFO SINCE VALIDITY IS 1 AND ALL OF THEM DONT EQUAL TAG
		}
	}
	else if(t[set_index][i].valid == 0) { 	//couldnt find the tag if n is equal to lines.
	n++;
	}	
i++;
}
if (n > 0 && m!=1) {//that means both lines were invalid so we have to do miss++ and write to it.THIS MEANS THERE IS OPEN SPACE. but still do prefetch, for the prefetch
//for the prefetch, we have to do for loop for the size of prefetch then check each set of that prefetch for hit or miss accordingly and fifo if both addresses are full or put it in first open space of the address.
	if(character == 'R'){
	miss++;
	mem_read++;
	}
	else if(character == 'W'){
	miss++;
	mem_read++;
	mem_write++;
	}
//RESET CACHE HERE.

pre_address = address;
//pre_address1 = address;
for (int j = 0; j<prefetchsize;j++) {
int mm = 0;
int ll = 0;
int nn = 0;
int ii= 0;
//pre_address1 = pre_address+blocksize;
pre_address = pre_address+blocksize;
unsigned int preset = (pre_address>>blockbits) & ((1<<setbits)-1);
unsigned long pretag = (pre_address>>blockbits) >>setbits;
	while(ii<line) {
	if(t[preset][ii].valid == 1) {
		if(t[preset][ii].tagger == pretag) {
			mm = 1;//its a hit it exists.
			break;
		}
		else if (t[preset][ii].tagger != pretag) {
		ll++;	
	
			}
		}
	else if (t[preset][ii].valid == 0){
	nn++;
		}
ii++;
	}
if (nn > 0 && mm != 1){//this means there is space
//find the largest within the n amount of prefetch size sets.
mem_read++;
int largest = t[preset][0].time;
	for(int jj = 1; jj<line; jj++) {
		if(t[preset][jj].time>largest) {
		largest = t[preset][jj].time;
		}	
	}
	for(int jj = 0; jj<line;jj++) {
		if(t[preset][jj].valid == 0) {
		timer = largest+1;
		t[preset][jj].tagger = pretag;
		t[preset][jj].time = timer;
		t[preset][jj].valid = 1;
		break;
		}
	}


} 
if(ll == line) {
mem_read++;
	int smallest = t[preset][0].time;
	for(int jj = 1; jj<line; jj++) {
	if(t[preset][jj].time<smallest){
	smallest = t[preset][jj].time;
		}
	}
	int largest = t[preset][0].time;
	for(int jj = 1; jj<line;jj++) {
		if(t[preset][jj].time>largest){
		largest = t[preset][jj].time;
		}	
	}
	for(int jj = 0; jj<line;jj++) {
		if(t[preset][jj].time == smallest) {
		timer = largest +1;		
		t[preset][jj].tagger = pretag;
		t[preset][jj].time = timer;
		t[preset][jj].valid = 1;
		break;
		}	


	}


}

}

}//end of n?0 and m!=1
if(l == line) {
	if(character == 'R') {
	mem_read++;
	miss++;
	}
	else if(character == 'W') {
	miss++;
	mem_read++;
	mem_write++;
	}
pre_address = address;
//pre_address1 = address;
for (int j = 0; j<prefetchsize;j++) {
int mm = 0;
int ll = 0;
int nn = 0;
int ii= 0;
//pre_address1 = pre_address+blocksize;
pre_address = pre_address+blocksize;
unsigned int preset = (pre_address>>blockbits) & ((1<<setbits)-1);
unsigned long pretag = (pre_address>>blockbits) >>setbits;
	while(ii<line) {
	if(t[preset][ii].valid == 1) {
		if(t[preset][ii].tagger == pretag) {
			mm = 1;//its a hit it exists.
			break;
		}
		else if (t[preset][ii].tagger != pretag) {
		ll++;	
	
			}
		}
	else if (t[preset][ii].valid == 0){
	nn++;

		}
ii++;
	}
if (nn > 0 && mm != 1){//this means there is space
//find the largest within the n amount of prefetch size sets.
mem_read++;
int largest = t[preset][0].time;
	for(int jj = 1; jj<line; jj++) {
		if(t[preset][jj].time>largest) {
		largest = t[preset][jj].time;
		}	
	}
	for(int jj = 0; jj<line;jj++) {
		if(t[preset][jj].valid == 0) {
		timer = largest+1;
		t[preset][jj].tagger = pretag;
		t[preset][jj].time = timer;
		t[preset][jj].valid = 1;
		break;
		}
	}


} 
if(ll == line) {
mem_read++;
	int smallest = t[preset][0].time;
	for(int jj = 1; jj<line; jj++) {
	if(t[preset][jj].time<smallest){
	smallest = t[preset][jj].time;
		}
	}
	int largest = t[preset][0].time;
	for(int jj = 1; jj<line;jj++) {
		if(t[preset][jj].time>largest){
		largest = t[preset][jj].time;
		}	
	}
	for(int jj = 0; jj<line;jj++) {
		if(t[preset][jj].time == smallest) {
		timer = largest +1;		
		t[preset][jj].tagger = pretag;
		t[preset][jj].time = timer;
		t[preset][jj].valid = 1;
		break;
		}	


	}


}

}





}
}//end of while loop
//print all 4 stuff
printf("Memory reads:%d\n",mem_read);
printf("Memory writes:%d\n",mem_write);
printf("Cache hits:%d\n",hit);
printf("Cache misses:%d\n",miss);
for (int i = 0; i < set; i++){
    free(t[i]);
}
}//end of function*/
}
void assoc(int setbits,int set,int blockbits,int line,FILE *fp){
santosh **t;
t = malloc(set*sizeof(santosh*));
for (int i = 0; i < set; i++){
    t[i] = malloc(line * sizeof(santosh));
}
for (int i = 0; i < set; i++) {
	for(int j = 0; j<line; j++) {
		t[i][j].tagger = 0;
		t[i][j].time = 0;
		t[i][j].valid = 0;
}
}
//if(DEBUG) printf("debugging statement\n");
int mask = (1<<setbits)-1;
int hit = 0;
int miss = 0;
int mem_write = 0;
int mem_read = 0;
char character;
int address = 0;
//int checker = 0;
int timer = 0;
int i = 0;
//int checker2 = 0;
//change if next empty line must be filled, first, if no empty lines then switch with the one that we are told to directly, over write it
//int timerchecker = 1;
while(fscanf(fp,"%c %x\n", &character, &address)!=EOF){
//if(DEBUG) printf("debugging statement\n");
//printf("%d\n",address);
//timer =0;
int m = 0;
int l = 0;
int n = 0; //counter for validity and stuff
unsigned int set_index = (address >> blockbits) & mask;
unsigned long tag = (address >> blockbits) >> setbits;
 i = 0;
//printf("%d\n",line);
while (i < line) {
//if(m==1){break;}
//printf("%d\n",i);
//if(DEBUG) printf("debugging statement\n");
	if(t[set_index][i].valid == 1) {
		if(t[set_index][i].tagger == tag) {
		m = 1; //m being 1 means it is true.
			if(character == 'R'){
			hit++;
			break;
			}
			else if(character == 'W'){
		//	if(DEBUG) printf("debugging statement\n");
			hit++;
			mem_write++;
			break;	
			}
	//	break;
		}
		else if(t[set_index][i].tagger != tag) {
		l++; //THIS SIGNIFIES WHETHER OR NOT WE SHOULD DO FIFO, IF l IS EQUAL TO LINES THEN WE MUST FIFO SINCE VALIDITY IS 1 AND ALL OF THEM DONT EQUAL TAG
		}
	}
	else if(t[set_index][i].valid == 0) { 	//couldnt find the tag if n is equal to lines.
	n++;
	}	
i++;
}
if (n > 0 && m!=1) {//that means both lines were invalid so we have to do miss++ and write to it.THIS MEANS THERE IS OPEN SPACE.
	if(character == 'R'){
	miss++;
	mem_read++;
	}
	else if(character == 'W'){
	miss++;
	mem_read++;
	mem_write++;
	}


	//find smallest element within the set
			int largest = t[set_index][0].time; 
	for(int j = 1; j<line; j++){
		if(t[set_index][j].time>largest){
		largest = t[set_index][j].time;
		}
	//find smallest element within the set
}	//if its, 

	for(int j = 0;j<line;j++) {
		if(t[set_index][j].valid== 0) {
		timer = largest + 1;
		t[set_index][j].tagger = tag;
		t[set_index][j].time = timer;
		t[set_index][j].valid = 1;
		break;
		}

		
	}	

		
//now write to the cache
//doesnt matter where
//t[set_index][

}
if(l == line) {
	if(character == 'R') {
	mem_read++;
	miss++;
	}
	else if(character == 'W') {
	miss++;
	mem_read++;
	mem_write++;
	}
//this means we must do FIFO, it is also a miss.
	//FIFO RIGHT HERE
	int smallest = t[set_index][0].time; 
	for(int j = 1; j<line; j++){
		if(t[set_index][j].time<smallest){
		smallest = t[set_index][j].time;
		}
	//find smallest element within the set
}
		int largest = t[set_index][0].time; 
	for(int j = 1; j<line; j++){
		if(t[set_index][j].time>largest){
		largest = t[set_index][j].time;
		}
	//find smallest element within the set
}
	//find smallest element within the set

	//NOW WE FOUND SMALLEST TIMER
	for(int j = 0; j<line; j++){
		if(t[set_index][j].time == smallest){
		//NOW REPLACE AND UPDATE EVERYTHING
		timer = largest+1;
		t[set_index][j].tagger = tag;
		t[set_index][j].time = timer;
		t[set_index][j].valid = 1;
		break;
		}		
	}

//if (m != 1) {
//if m doesnt equal to one that means the lines did not match up with the tags therefore we must do FIFO.

}





}





//print all 4 stuff
printf("Memory reads:%d\n",mem_read);
printf("Memory writes:%d\n",mem_write);
printf("Cache hits:%d\n",hit);
printf("Cache misses:%d\n",miss);

for (int i = 0; i < set; i++){
    free(t[i]);
}
}


void assocn(int setbits,int set,int blockbits,int line,FILE *fp) {
//if(DEBUG) printf("debugging statement\n");

santosh **t;
t = malloc(set*sizeof(santosh*));
for (int i = 0; i < set; i++){
    t[i] = malloc(line * sizeof(santosh));
}
for (int i = 0; i < set; i++) {
	for(int j = 0; j<line; j++) {
		t[i][j].tagger = 0;
		t[i][j].time = 0;
		t[i][j].valid = 0;
}
}
//if(DEBUG) printf("debugging statement\n");
int mask = (1<<setbits)-1;
int hit = 0;
int miss = 0;
int mem_write = 0;
int mem_read = 0;
char character;
int address = 0;
//int checker = 0;
int timer = 0;
int i = 0;
//int checker2 = 0;
//change if next empty line must be filled, first, if no empty lines then switch with the one that we are told to directly, over write it
//int timerchecker = 1;
while(fscanf(fp,"%c %x\n", &character, &address)!=EOF){
//if(DEBUG) printf("debugging statement\n");
//printf("%d\n",address);
//timer =0;
int m = 0;
int l = 0;
int n = 0; //counter for validity and stuff
unsigned int set_index = (address >> blockbits) & mask;
unsigned long tag = (address >> blockbits) >> setbits;
 i = 0;
//printf("%d\n",line);
while (i < line) {
//if(m==1){break;}
//printf("%d\n",i);
//if(DEBUG) printf("debugging statement\n");
	if(t[set_index][i].valid == 1) {
		if(t[set_index][i].tagger == tag) {
		m = 1; //m being 1 means it is true.
			if(character == 'R'){
			hit++;
			break;
			}
			else if(character == 'W'){
		//	if(DEBUG) printf("debugging statement\n");
			hit++;
			mem_write++;
			break;	
			}
	//	break;
		}
		else if(t[set_index][i].tagger != tag) {
		l++; //THIS SIGNIFIES WHETHER OR NOT WE SHOULD DO FIFO, IF l IS EQUAL TO LINES THEN WE MUST FIFO SINCE VALIDITY IS 1 AND ALL OF THEM DONT EQUAL TAG
		}
	}
	else if(t[set_index][i].valid == 0) { 	//couldnt find the tag if n is equal to lines.
	n++;
	}	
i++;
}
if (n > 0 && m!=1) {//that means both lines were invalid so we have to do miss++ and write to it.THIS MEANS THERE IS OPEN SPACE.
	if(character == 'R'){
	miss++;
	mem_read++;
	}
	else if(character == 'W'){
	miss++;
	mem_read++;
	mem_write++;
	}


	//find smallest element within the set
			int largest = t[set_index][0].time; 
	for(int j = 1; j<line; j++){
		if(t[set_index][j].time>largest){
		largest = t[set_index][j].time;
		}
	//find smallest element within the set
}	

	for(int j = 0;j<line;j++) {
		if(t[set_index][j].valid== 0) {
		timer = largest + 1;
		t[set_index][j].tagger = tag;
		t[set_index][j].time = timer;
		t[set_index][j].valid = 1;
		break;
		}

		
	}	

		
//now write to the cache
//doesnt matter where
//t[set_index][

}
if(l == line) {
	if(character == 'R') {
	mem_read++;
	miss++;
	}
	else if(character == 'W') {
	miss++;
	mem_read++;
	mem_write++;
	}
//this means we must do FIFO, it is also a miss.
	//FIFO RIGHT HERE
	int smallest = t[set_index][0].time; 
	for(int j = 1; j<line; j++){
		if(t[set_index][j].time<smallest){
		smallest = t[set_index][j].time;
		}
	//find smallest element within the set
}
		int largest = t[set_index][0].time; 
	for(int j = 1; j<line; j++){
		if(t[set_index][j].time>largest){
		largest = t[set_index][j].time;
		}
	//find smallest element within the set
}
	//find smallest element within the set

	//NOW WE FOUND SMALLEST TIMER
	for(int j = 0; j<line; j++){
		if(t[set_index][j].time == smallest){
		//NOW REPLACE AND UPDATE EVERYTHING
		timer = largest+1;
		t[set_index][j].tagger = tag;
		t[set_index][j].time = timer;
		t[set_index][j].valid = 1;
		break;
		}		
	}

//if (m != 1) {
//if m doesnt equal to one that means the lines did not match up with the tags therefore we must do FIFO.
}
}//while loop end
//print all 4 stuff
printf("Memory reads:%d\n",mem_read);
printf("Memory writes:%d\n",mem_write);
printf("Cache hits:%d\n",hit);
printf("Cache misses:%d\n",miss);
for (int i = 0; i < set; i++){
    free(t[i]);
}
}//function end
int setsize(int cachesize, int blocksize, int associativity ){
int set2 = cachesize/blocksize;
set2 = set2/associativity;
return set2;
}
int main(int argc, char** argv) {
/*char* n = argv[4];
char c = n[6];
char cc[2] = {c,'\0'};
int line = atoi(cc);
printf("%d\n",line);
*/
//printf("Not working\n");
int counterz=0;
int cachesize = 0;
int blocksize = 0;
char direct1[] = "direct";
char assoc1[] = "assoc";
//char assocn1[] = "assoc:%d";
//int carryforn = 0;
if(argc!= 7) {
printf("error\n");
exit(0);
}
FILE *fp = fopen(argv[6],"r");
FILE *fp2 = fopen(argv[6],"r");
cachesize = atoi(argv[1]);
blocksize = atoi(argv[2]);
int prefetch = atoi(argv[5]);
//we will need the number of set index bits
//number of block offset bits
if (strcmp(direct1,argv[4]) == 0){
//must create an array. 
//index bits
//santosh **t;
//int prefetch = atoi(argv[5]);
int line = 1;
int set = 0;
set = setsize(cachesize, blocksize, line);
int setbits = 0;
setbits = log2(set);
/*t = malloc(set*sizeof(santosh*));
for (int i = 0; i < set; ++i){
    t[i] = malloc(1 * sizeof(santosh));
}
for (int i = 0; i < set; i++) {
t[i][0].valid = 0;
t[i][0].time = 0;
t[i][0].tagger = 0;
}*/
//ofset bits
int blockbits = 0;
blockbits = log2(blocksize);
printf("no-prefetch\n");
direct(setbits,set,blockbits,line,fp);
printf("with-prefetch\n");
directprefetch(setbits,set,blockbits,line,fp2,prefetch,blocksize);
counterz = 1;
}
else if (strcmp(assoc1,argv[4])==0) {
int set = 1;
int line  = setsize(cachesize,blocksize,set);
int setbits = 0;
setbits = log2(set);
int blockbits = 0;
blockbits = log2(blocksize);
printf("no-prefetch\n");
assoc(setbits,set,blockbits,line,fp); 
printf("with-prefetch\n");
directprefetch(setbits,set,blockbits,line,fp2,prefetch,blocksize);

//counterz = 1;
}
else if (counterz == 0){
//int carryforn = atoi(argv[4]);
//carryforn = carryforn>>6;
char* n = argv[4];
char c = n[6];
char cc[2] = {c,'\0'};
int line = atoi(cc);
int set = setsize(cachesize,blocksize,line);
int setbits = log2(set);
int blockbits = log2(blocksize);
printf("no-prefetch\n");
assocn(setbits,set,blockbits,line,fp);
printf("with-prefetch\n"); 
directprefetch(setbits,set,blockbits,line,fp2,prefetch,blocksize);

//printf("%d\n",line);
}
//we know the number they give us next to assoc:n is the associativity, N being the number of lines i assume which simulates an n way associative cache
//ask in class about associative cache 
//ask about n amount associativity
//n ways
//also ask about fifo
//ask if validity is 1 and there is somethign already there in direct, do you go to next free, if no next free do you do just replace what is already there. 
//ask the same for set cache, if its full associative do you do the same.
//if its n ways ask about divison. 


//must determine if the access is a hit or a miss and the actions to perform in each case.
// the input is two columns, 
// 
//
// MUST SIMULATE ONE LEVEL CACHE
// 	INPUT: Cache size, associativity, replacement policy, and the block size are input paramete
//CACHE SIZE AND BLOCK SIZE ARE SPECIFIED IN BYTES.
//format inserted will be /file <cache size> <block size> <cache policy> <associativity><prefetch size> <trace file>
//







//printf("the end\n");
return 0;
}


