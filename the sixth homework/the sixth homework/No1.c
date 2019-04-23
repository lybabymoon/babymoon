#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


//¥Ú”°≥À∑®±Ì
int Chengfabiao(int n){
	int i = 0;
	int j = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			printf(" %2d*%2d=%2d", i, j, i*j);
		}
		printf("\n");
	}
	}
int main1(){
	int n = 0;
	printf("please input your number:\n");
	scanf("%d", &n);
	Chengfabiao(n);
    system("pause");
	return 0;
}