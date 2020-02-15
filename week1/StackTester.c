// Integer Stack ADO tester ... COMP9024 19T3
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int main(void) {
	int i, n;
	char str[BUFSIZ];

	StackInit();

	printf("Enter a positive number: ");
	scanf("%s", str);
	if ((n = atoi(str)) > 0) {    // convert to int and test if positive
		for (i = 0; i < n; i++) {
		 	printf("Enter a number: ");
		 	scanf("%s", str);
		 	StackPush(atoi(str));
	    }
	}
	
	for (i=0;i<n;i++){
		int a;
		a=StackPop();
		printf("%d\n",a);   
	}

   return 0;
}
