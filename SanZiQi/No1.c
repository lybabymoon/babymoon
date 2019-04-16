#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define  Max_row 3
#define  Max_col 3
void Menu(){
	printf("******************\n");
	printf("****1.��Ϸ��ʼ****\n");
	printf("****0.�˳���Ϸ****\n");
	printf("******************\n");
}

char chessboard[Max_row][Max_col];

void SetChessboard(){
	for (int row = 0;row < Max_row; ++row){
		for (int col = 0; col < Max_col; ++col){
			 chessboard[row][col] = ' ';
		}
}
}
void Print(){
	for (int row = 0; row < Max_row; ++row){
		printf("| %c | %c | %c |\n", chessboard[row][0],
			chessboard[row][1], chessboard[row][2]);
		if (row != Max_row - 1){
			printf("|---|---|---|\n");
		}
    }
}
void PeopleGo(){
	printf("�������!!!\n");
	while (1){
		printf("������һ������:");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= Max_row || col >= Max_col || row < 0 || col < 0){
			printf("��ʹ�ù淶����,����!!!\n");
			continue;
		}
		if(chessboard[row][col] !=' '){
			printf("������������Ѿ���ռ��!!!\n");
			continue;
		}
		chessboard[row][col] = 'x';
		break;
	}
}
// x���ʤ,o����ʤ,q����
char CheckOver(){
	//�����,��,�Խ���
	for (int row = 0; row < Max_row; ++row){
		if (chessboard[row][0] == chessboard[row][1] &&
			chessboard[row][0] == chessboard[row][2]){
			return chessboard[row][0];
		}
	}
	for (int col = 0; col < Max_col; ++col){
		if (chessboard[0][col] == chessboard[1][col] && 
			chessboard[0][col] == chessboard[2][col]){
			return chessboard[0][col];
		}
	}
	if ((chessboard[0][0] == chessboard[1][1] && chessboard[0][0] == chessboard[2][2]) ||
		(chessboard[0][2] == chessboard[1][1] && chessboard[0][2] == chessboard[2][0])){
		return chessboard[1][1];
	}
	if (IsFull()){
		return 'q';
	}
	return ' ';
}
void ComputerGo(){
	printf("��������!\n");
	while (1){
		int row = rand() % Max_row;
		int col = rand() % Max_col;
		if (chessboard[row][col] != ' ' ){
			continue; 
		}
		else{
			chessboard[row][col] = 'o';
			break;
		}
	}
}
int IsFull(){
	for (int row = 0; row < Max_row; ++row){
		for (int col = 0; col < Max_col; ++col){
			if (chessboard[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
	//��������е�λ�ö�����
}
void Game(){
	        //0.��������
	    char winner = ' ';
	    SetChessboard();
	        while (1){
				system("cls");
			//1.��ӡ����
			Print();
			//2.�����
			PeopleGo();
			//3.�����Ϸ�Ƿ����

		winner = CheckOver();
		if (winner != ' '){
			break;
		}
			//4.������
			ComputerGo();
			//5.�����Ϸ�Ƿ����
		winner = CheckOver();
		if (winner != ' '){
			break;
		}
	} 
			system("cls ");
			if (winner == 'x'){
				printf("��Ӯ��!!\n");
			}
			else if (winner == 'o'){
				printf("������!!\n");
			}
			else if (winner == 'q'){
				printf("����!!\n");
			}
			else{
				printf("������!!\n");
			}
			system("pause");
			system("cls");
			Print();
}
int main(){
	Menu();
	while (1){
		int choice;
		scanf("%d", &choice);
		if (choice == 1){
			Game();
			system("cls");
			Menu();
		}
		else if(choice == 0){
			printf("��Ե�ټ�!!\n");
			break;
		}
	}
	system("pause");
	return 0;
}