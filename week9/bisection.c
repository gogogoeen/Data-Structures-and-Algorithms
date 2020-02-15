#include <stdio.h>
#include <stdlib.h>

#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double myfun (double x){
	return sin(x);
}

double bisection(double (*f)(double), double x1, double x2){
	double e=1.0e-10;
	double mid;
	mid=(x1+x2)/2;
	while(f(mid)!=0&&(x1-x2)>e){
		
		mid=(x1+x2)/2;
		if (f(x1)*f(x2)<0){
			x2=mid;
		}else {
			x1=mid;
		}
	}
	return mid;
}

int main(int argc, char *argv[]) {
	
	double ans=bisection(myfun,2.0,4.0);
	printf("%.10f\n",ans);
	
	
	return 0;
}
