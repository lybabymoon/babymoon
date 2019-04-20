#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	double aver = 0;
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	if ((a + b) % 2 == 0){
		aver = (a + b) >> 1;
	}
	else if ((a + b) % 2 == 1){
		aver = ((a + b) >> 1) + 0.5;
	}
	printf("%lf\n", aver);
	system("pause");
	return 0;
}