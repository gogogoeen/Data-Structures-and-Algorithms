#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void){
	int i, tmp1, tmp2, tmp3, tmp;
	tmp1=0;
	tmp2=0;
	tmp3=1;
	for (i=1;i<=10;i++){
		printf("Fib[%d]=%d\n",i,tmp3);
		tmp1=tmp2;
		tmp2=tmp3;
		tmp3=tmp1+tmp2;
		if (tmp3==1){
			printf("%d\n",tmp3);
		}else{
			
			tmp=tmp2;
			printf("%d\n",tmp);
			while (tmp!=1){
				if (tmp%2==0){
					tmp/=2;
					printf("%d\n",tmp);
				}else {
					tmp=3*tmp+1;
					printf("%d\n",tmp);
				}
			}
		}
		
	}
	return 0;
}
