#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//查找素数
void Sushu(int a){
	int c = (int)sqrt(a);
	if (0 == a % c){
		printf("不是素数");
	}
	else{
		printf("是素数!");
	}
}
int mains(){
	int b;
	printf("请输入一个数字!\n");
	scanf(" %d", &b);
	Sushu(b);
	system("pause");
	return 0;
}