#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int *makeArrayOfInts() {
   	int *arr;
   	arr=(int*)malloc(sizeof(int)*10);
   	assert(arr!= NULL);
   	int i;
   	for (i=0; i<10; i++) {
      	*(arr+i) = i;
   	}
   	return arr;
}

int main(int argc, char *argv[]) {
	/*int *brr;
   	brr=(int*)malloc(sizeof(int)*10);
   	assert(brr!= NULL);
   	int i;
   	for (i=0; i<10; i++) {
    	*(brr+i) = i;
   	}
	*/
	int *p;
	p=makeArrayOfInts();
	printf("%d",*(p+2));
	return 0;
}
