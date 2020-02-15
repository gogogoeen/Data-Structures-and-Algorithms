#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	int max=5;
	int j=0;
	for (i=1;i<max;i++){
		printf("%d",i);
	}
	while (j<max){
		printf("%d",j);
		j++;
	}
	return 0;
}
