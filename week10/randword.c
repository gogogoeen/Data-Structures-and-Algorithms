#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause")a or input loop */

int main(int argc, char *argv[]) {
	srand(atoi(argv[2]));
	char letter[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int i;
	for (i=0;i<atoi(argv[1]);i++){
		int randompick=rand()%26;
		printf("%c", letter[randompick]) ;
	}
	printf("\n");
	return 0;
}
