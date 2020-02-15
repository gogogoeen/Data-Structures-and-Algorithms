#include <stdio.h>
#include <string.h> 
#define LEN(x) sizeof(x) / sizeof(x[0])
int main(void) {
	float A[3][2]={
		{1,-2.5},
		{2,3.8},
		{10,1},
	};
	float B[3][2]={
		{2,2.5},
		{4,2.5},
		{10,-1},
	};
	float C[10][2];
	int countA=0;
	int countB=0;
	int countC=0;
	while (countA<LEN(B)||countB<LEN(B)){
		if (A[countA][0]<B[countB][0]&&countA<LEN(B)-1){
			C[countC][0]=A[countA][0];
			C[countC][1]=A[countA][1];
			countC++;
			countA++;
			//printf("%d\n",countC);
		}else if (A[countA][0]>B[countB][0]&&countB<LEN(B)-1){
			C[countC][0]=B[countB][0];
			C[countC][1]=B[countB][1];
			countC++; 
			countB++;
		
		}else if (A[countA][0]==B[countB][0]&&B[countB][1]+A[countA][1]!=0){
			C[countC][0]=B[countB][0];
			C[countC][1]=B[countB][1]+A[countA][1];
			countC++, countB++, countA++;
		
		}else if(A[countA][0]==B[countB][0]&&B[countB][1]+A[countA][1]==0){
			countB++, countA++;
		}else if(countA>=LEN(B)&&countB<LEN(B)){
			C[countC][0]=B[countB][0];
			C[countC][1]=B[countB][1];
			countC++; 
			countB++;			
		}else {
			C[countC][0]=A[countA][0];
			C[countC][1]=A[countA][1];
			countC++;
			countA++;
		}
		
	}
	int i, j;
	for (i=0;i<=countC-1;i++){
		for (j=0;j<=1;j++){
			printf("%.2f",C[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",countA);
	printf("%d\n",countB);
	printf("%d\n",countC);
	printf("%d",LEN(B));
	return 0;
}
