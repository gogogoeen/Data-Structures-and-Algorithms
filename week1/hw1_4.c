#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct{
	int Tnumber;
	char Date[14];
	char Time[5];
	char Mode;
	char Start[31];
	char End[31];
	int Jnumber;
	char Fareapplied[13];
	float Fare;
	float Discount;
	float Amount;
}singleride;

int main(int argc, char *argv[]) {
 	//char a="x";
 	//printf("%c\n",a);
 	
	singleride ride1={3505, "Sun28/07/2019", "13:17", 'T', "Kings Cross", "Strathfield", 9, "Travel Reward", 4.48, 2.92, 1.56};
 	singleride ride2={3503, "Fri26/07/2019", "18:00", 'B', "Anzac Pde bf Addison St", "Taylor Square", 8, "No", 3.73, 0, 3.73};
 	singleride ride3={3501, "Fri26/07/2019", "10:20", 'B', "Flinders St af Oxford St", "UNSW", 7, "No", 3.73, 0, 3.73};
	printf("Transaction number:%d  Date:%s  Time:%s Mode:%c  Start:%s End:%s  Journey number:%d  Fare Applied:%s  Fare:%.2f  Discount:%.2f  Amount:%.2f\n",ride1.Tnumber,ride1.Date,ride1.Time,ride1.Mode,ride1.Start,ride1.End,ride1.Jnumber,ride1.Fareapplied,ride1.Fare,ride1.Discount,ride1.Amount);
	printf("Transaction number:%d  Date:%s  Time:%s Mode:%c  Start:%s End:%s  Journey number:%d  Fare Applied:%s  Fare:%.2f  Discount:%.2f  Amount:%.2f\n",ride2.Tnumber,ride2.Date,ride2.Time,ride2.Mode,ride2.Start,ride2.End,ride2.Jnumber,ride2.Fareapplied,ride2.Fare,ride2.Discount,ride2.Amount);
	printf("Transaction number:%d  Date:%s  Time:%s Mode:%c  Start:%s End:%s  Journey number:%d  Fare Applied:%s  Fare:%.2f  Discount:%.2f  Amount:%.2f\n",ride3.Tnumber,ride3.Date,ride3.Time,ride3.Mode,ride3.Start,ride3.End,ride3.Jnumber,ride3.Fareapplied,ride3.Fare,ride3.Discount,ride3.Amount);
	return 0;
}
