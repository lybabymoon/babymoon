#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//需要修改
//4.
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
//void Init(int a[],int n){
//	int b = 0;
//	for (int i = 0; i < n; i++){
//		printf("Please input your array:");
//		scanf(" %d",&b);
//		a[i]=b;
//	}
//	for (int j = 0; j < n; j++){
//		printf(" %d", a[j]);
//	}
//	printf("\n");
//}
void init(int data[],int a[],int n){
	int i;
	for (i = 0; i < n; i++){
		a[i] = data[i];
	}
}
void Empty(int a[],int n){
	memset(a, 0, sizeof(a[0]) * n);
}
void ReverseArry(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		//将数组中的首尾元素交换，直到left与right相等
		int tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}
	for (int i = 0; i < n; i++)
	{
		printf(" %d ", a[i]);
	}
	printf("\n");
}
int main4(){

	int a[10] = { 0 };
	int data[10] = { 9, 5, 1, 7, 4, 8, 6, 2 };
	int n =sizeof(a) / sizeof(a[0]);
	init(data,a,10);
	ReverseArry(a, n);
	Empty(a, n);
	system("pause");
	return 0;
}