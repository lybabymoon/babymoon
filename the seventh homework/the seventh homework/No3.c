//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
////3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
////例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//int DigitSum(int n){
//	int sum = 0; 
//	sum = n / 1000 + n / 100 % 10 + n / 10 % 10 + n % 10;
//	return sum;
//}
//int DigitSum1(int n){
//	if (n < 9){
//		return n;
//	}
//	return n % 10 + DigitSum1(n / 10) ;
//}
//int main(){
//	int n = 0;
//	printf("please input a number\n");
//	scanf("%d", &n);
//	printf("sum=%d\n",DigitSum(n));
//	printf("sum1=%d\n" ,DigitSum1(n));
//	system("pause");
//	return 0;
//}