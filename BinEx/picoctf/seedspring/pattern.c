#include<stdio.h>
#include<time.h>

/* gcc -m32 -o sequence-generator sequence-generator.c */
/* Usage: ./sequence-generator [unix-time] */

int main(int argc, char* argv[]){
	time_t seed;
	if(argc == 1){
		seed = time(0);
	}else if(argc == 2){
		seed = strtol(argv[1],NULL,10);
	}else{
		printf("Usage: %s [unix-time]\n",argv[0]);
		return 0;
	}	
	unsigned int random;
	srand(seed);
	for(int i=1; i<=30; i++){
		random = rand() & 15;
		printf("%u ",random);
	}
	puts("");
	return 0;
}
