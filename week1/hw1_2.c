#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	char str[7]={'a','c','d','g','o','t','\0'};
	int num[]={0,1,2,3,4,5};
	int i, j, k, m, n, tmp, tmp1;
	int count=0;
	for (n=0;n<=5;n++){
		tmp=num[0];										//last six digits change
		num[0]=num[n];
		for (i=0;i<n;i++){
				tmp1=num[1+i];
				num[1+i]=tmp;
				tmp=tmp1;
		}
		for (m=0;m<=4;m++){
			tmp=num[1];									//last five digits change
			num[1]=num[1+m];
			for (i=0;i<m;i++){
					tmp1=num[2+i];
					num[2+i]=tmp;
					tmp=tmp1;
			}
			for (k=0;k<=3;k++){
				tmp=num[2];								//last four digits change
				num[2]=num[2+k];
				for (i=0;i<k;i++){
						tmp1=num[3+i];
						num[3+i]=tmp;
						tmp=tmp1;
				}
				for (j=0;j<=2;j++){
					tmp=num[3];							//last three digits change
					num[3]=num[3+j];					
					for (i=0;i<j;i++){
						tmp1=num[4+i];
						num[4+i]=tmp;
						tmp=tmp1;
					}
					
					for (i=0;i<=5;i++){                 
						printf("%c",str[num[i]]);		
					}									
					printf("\n");
					count++;
					tmp=num[4];							//change last two digits
					num[4]=num[5];
					num[5]=tmp;
					for (i=0;i<=5;i++){
						printf("%c",str[num[i]]);
					}
					printf("\n");
					count++;
					tmp=num[4];							//change last two digits
					num[4]=num[5];
					num[5]=tmp;
					
					tmp=num[3+j];						//last three digits change
					num[3+j]=num[3];					
					for (i=0;i<j;i++){
						tmp1=num[2+j-i];
						num[2+j-i]=tmp;
						tmp=tmp1;
					}
				}
				tmp=num[2+k];							//last four digits change
				num[2+k]=num[2];					
				for (i=0;i<k;i++){
					tmp1=num[1+k-i];
					num[1+k-i]=tmp;
					tmp=tmp1;
				}
			}
			tmp=num[1+m];								//last five digits change
			num[1+m]=num[1];					
			for (i=0;i<m;i++){
				tmp1=num[m-i];
				num[m-i]=tmp;
				tmp=tmp1;
			}
		}
		tmp=num[n];										//last six digits change
		num[n]=num[0];					
		for (i=0;i<n;i++){
			tmp1=num[n-i-1];
			num[n-i-1]=tmp;
			tmp=tmp1;
		}
	}
	return count;
}


