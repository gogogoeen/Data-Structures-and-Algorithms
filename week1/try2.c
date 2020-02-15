#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void change(int x, int y){
	int tmp;
	tmp=x;
	x=y;
	y=tmp;
}

int main(int argc, char *argv[]) {
	char str[7]={'a','c','d','g','o','t','\0'};
	int num[]={0,1,2,3,4,5};
	int i, j, k, tmp;
	
		tmp=num[2];
		num[2]=num[3];
		num[3]=tmp;
		for (i=0;i<=5;i++){
				printf("%d",num[i]);
			}
	
	return 0;
}

