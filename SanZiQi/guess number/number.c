#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
int Menu(){
	printf("******************\n");
	printf("*****1.start******\n");
	printf("*****0.return*****\n");
	printf("******************\n");
	printf("**��������������**\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Game(){
	//1
	int r_number=rand() % 100 + 1;
	//2
while(1){
	printf("please input a number(0-100): ");
	int num = 0;
	scanf("%d", &num);
	//3.4.
	if (num > r_number){
		printf("too high\n");
	}
	else if(num < r_number){
		printf("too low\n");
	}
	else{
		printf(" you are right\n");
		break;
	}
  }
}
int main(){
	 srand(time(0));
	while (1){
		int choice = Menu();
		if (choice == 1){
			Game();
		}
		else if (choice == 0){
			printf("��ӭ�´ι���!!!");
			break;
		}
		else{
			printf("�䲻�Բ�����,�����Ŭ��!!!");
		}
	}

	system("pause\n");
	return 0;
}