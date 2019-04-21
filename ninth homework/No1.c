//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//void ChangeJiOu(int a[],int n){
//	int tmp = 0;
//	int i = 0, j = 8;
//	while (a[i++] % 2 && i <= 8);
//	while (a[j--] % 2 == 0 && j >= 0);
//	while (i <= j){
//		tmp = a[i - 1];
//		a[i - 1] = a[j + 1];
//		a[j + 1] = tmp;
//
//		while (a[i++] % 2);
//		while (a[j--] % 2 == 0);
//	}
//	for (i = 0; i < 9; i++){
//		printf("%d ", a[i]);
//	}
//}
//int main(){
//	int a[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	ChangeJiOu(a, 9);
//	system("pause");
//	return 0;
//}