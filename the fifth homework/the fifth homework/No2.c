#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Land(){
	int i = 0;
	char code[21] = "zby0327";
	char input[21] = {0};
	for (; i < 3; i++){
		printf("please input your cipher code(Up to three times !)\n ");
		scanf("%s", input);
		if (0 == strcmp(input,code)){
			printf("Landing success!\n");
			break;                     // return 0 
		}
		else if (input != code){
			printf("fail to land!\n");
		}
		else if (i = 3){
			printf("fail to land!\n");
			break;
		}
	}
}

int main2(){
	Land();
	system("pause");
	return 0;
}