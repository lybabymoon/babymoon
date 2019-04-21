#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int YangShi(int num[][3],int x,int y,int number){
	int i = 0, j = y-1;
	while (i<x&&y>=0){
		if (number > num[i][j]){
			i++;
		}
		else if (number < num[i][j]){
			j--;
		}
		else{
			return 1;
		}
	}
	return 0;
}
int main(){
	int num[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
	int number = 0;
	printf("Please input the number that you want to find!:\n");
	scanf("%d", &number);
	if (YangShi(num, 3, 3, number)){
		printf("find it!!\n");
	}
	else{
		printf("don't find it!!\n");
	}
	system("pause");
	return 0;
}