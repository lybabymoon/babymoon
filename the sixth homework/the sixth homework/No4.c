#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��Ҫ�޸�
//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
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
		//�������е���βԪ�ؽ�����ֱ��left��right���
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