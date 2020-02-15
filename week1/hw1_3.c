#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int input;
	scanf("%d",&input);
	while (input!=1){
		if (input%2==0){
			input/=2;
			printf("%d\n",input);
		}else {
			input=3*input+1;
			printf("%d\n",input);
		}
	}
	return 0;
}
