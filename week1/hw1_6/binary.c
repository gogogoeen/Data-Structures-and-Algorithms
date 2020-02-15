#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num, i;
	int n=0;
	printf("Enter a number:");
	scanf("%d",&num);
	while (num>0){
		StackPush(num%2);
		num/=2;
		n++;
	}
	for (i=0;i<n;i++){
	
		int a;
		a=StackPop();
		printf("%d",a);   
	}
	return 0;
}
