#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main1(){
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int left = 0;
	int right = sizeof(a) / sizeof(a[0]) - 1;
	int to_find;
	int mid = (left + right) / 2;
	printf("please input a number (1-10)\n");
	scanf("  %d", &to_find);
	while (left <= right){
		if (to_find < a[mid]){
			right = mid - 1;
		}
		else if (to_find > a[mid]){
			left = mid + 1;
		}
		else{
			break;
		}
	}
	if (left <= right){
		printf("find,its subscript is %d\n",mid);
	}
	else{
		printf("can'find\n");
	}
	system("pause");
	return 0;
}