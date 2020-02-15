#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	int data[12]={5,3,6,2,7,4,9,1,8};
	printf("data value\n");
	for (i=0;i<12;i++){
		printf("%d\n",data[i]);	
	}
	printf("\n");
	printf("data address\n");
	for (i=0;i<12;i++){
		printf("%p\n",&data[i]);	
	}
	printf("\n");
	printf("%d\n",*data+4);
	
	/*int data[12]={5,3,6,2,7,4,9,1,8};
	printf("data value\n");
	for (i=0;i<12;i++){
		printf("%d\n",data[i]);	
	}
	printf("\n");
	printf("data address\n");
	for (i=0;i<12;i++){
		printf("%p\n",&data[i]);	
	}
	printf("\n");
	return 0;
	*/
}
