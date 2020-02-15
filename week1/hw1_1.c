#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a=0, b=0, c=0, d=0, e=1;
	int x;
	while (a*40000+b*4000+c*400+d*40+4*e != e*10000+d*1000+c*100+b*10+a){
		if (e==9&&d!=9){
			e=0;
			d++;
		}else if (e==9&&d==9&&c!=9){
			e=0;
			d=0;
			c++;
		}else if (e==9&&d==9&&c==9&&b!=9){
			e=0;
			d=0;
			c=0;
			b++;
		}else if (e==9&&d==9&&c==9&&b==9&&a!=9){
			e=0;
			d=0;
			c=0;
			b=0;
			a++;
		}else {
			e++;
		}
		
	}
	x=10000*a+1000*b+100*c+10*d+e;
	printf("%d",x);
	return x;
}
