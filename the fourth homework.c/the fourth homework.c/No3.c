#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
  int main(){
	int a;
	int Sn = 0;
	printf("please input a number: \n");
	scanf("%d", &a);
	/*for (int i = 0; i <= 4; i++){
		for (int j = 5; j <= 1; j--){
			Sn = a*j*(10 ^ i)+Sn;
			printf(" %d", Sn);
		}
		
	}*/
	Sn = a * 5 + a * 4 * 10 + a * 3 * 100 + a * 2 * 1000 + a * 10000;
		printf(" %d", Sn);
		system("pause");
		return 0;
}