#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
double Change(double f){
	double c ;
	return c = (5.0 / 9) * (f - 32);
}
double Area(double a,double b,double c){
	double area,s;
	s = (a + b + c) / 2;
	return area = sqrt(s*(s - a)*(s - b)*(s - c));
}
int main(){
	//1.
	/*printf("please input a number!\n");
	double f = 64.0;
	scanf("%f", &f);
	printf("%f", Change(f));*/

	//2.
	//printf(" \t ");
	double a, b, c;
	printf("please input a,b,c\n");
	scanf("%f %f %f\n", &a, &b, &c);
	printf("%f", Area(a, b, c));
	system("pause");
	return 0;
}