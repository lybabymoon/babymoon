#include<stdint.h>
#include<stdlib.h>


int main1(){
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0;
	for (i = 1; i <= 13; i=i+2){
		for (j = 1; j <= i; j++){
					printf("*");
		}
		printf("\n");
	}
	for (m = 11; m >= 1; m = m - 2){
		for (n = 1; n <= m;n++){
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}