#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//��������
void Sushu(int a){
	int c = (int)sqrt(a);
	if (0 == a % c){
		printf("��������");
	}
	else{
		printf("������!");
	}
}
int mains(){
	int b;
	printf("������һ������!\n");
	scanf(" %d", &b);
	Sushu(b);
	system("pause");
	return 0;
}