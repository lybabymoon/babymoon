#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//3.ʵ��һ�������ж�year�ǲ������ꡣ
int Runnian(int year){
	if (0 == year % 4 && year % 100 != 0 || year % 400 == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main3(){
	int n = 0;
	printf("please input a number:\n");
	scanf("%d", &n);
	if (Runnian(n)){
		printf("this is a leap year!!!!");
	}
	else {
		printf("this is not a leap year!!!");
	}
	system("pause");
	return 0;
}