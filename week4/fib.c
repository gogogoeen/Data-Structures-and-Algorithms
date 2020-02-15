#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	unsigned long long int *np;
	np=(unsigned long long int*)malloc(atoi(argv[1])*sizeof(unsigned long long int));
	assert(np!= NULL);
	int i;
	for (i=0;i<atoi(argv[1]);i++){
		if (i+1==1){
			*(np+i)=1;
			printf("%llu\n",*(np+i));
		}else if (i+1==2){
			*(np+i)=1;
			printf("%llu\n",*(np+i));
		}else {
			*(np+i)=*(np+i-1)+*(np+i-2);
			printf("%llu\n",*(np+i));
		}
		
	}
	free(np);
	return 0;
}
