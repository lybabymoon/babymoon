#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void printfArray(int a[],int n){
	int i;
	for (i = 0; i < n; i++){
		printf(" %d", a[i]);
	}

	putchar('\n');
}


int main1(){

	
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[10] = { 11,12,13,14,15,16,17,18,19,20};
	int temp ;
	
	for (int i = 0; i <= 10; i++){
		temp = a[i];
		a[i]= b[i];
		b[i] = temp;
	}
	printfArray(a, 10);
	printfArray(b, 10);



	system("pause");
	return 0;
}