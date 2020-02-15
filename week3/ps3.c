#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, len;
	char str[50];
	printf("Enter a word:");
	scanf("%s",&str);
	len=strlen(str);
	for (i=0;i<=len/2-1;i++){
		if (str[i]!=str[len-i-1]){
			printf("no");
			return 0;
		}
	}
	printf("yes");
	return 0;
}
