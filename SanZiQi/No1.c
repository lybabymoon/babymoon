#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define  Max_row 3
#define  Max_col 3
void Menu(){
	printf("******************\n");
	printf("****1.游戏开始****\n");
	printf("****0.退出游戏****\n");
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
	printf("玩家落子!!!\n");
	while (1){
		printf("请输入一组坐标:");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= Max_row || col >= Max_col || row < 0 || col < 0){
			printf("请使用规范操作,蠢货!!!\n");
			continue;
		}
		if(chessboard[row][col] !=' '){
			printf("您输入的坐标已经被占了!!!\n");
			continue;
		}
		chessboard[row][col] = 'x';
		break;
	}
}
// x玩家胜,o电脑胜,q和棋
char CheckOver(){
	//检查行,列,对角线
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
	printf("电脑落子!\n");
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
	//必须把所有的位置都找完
}
void Game(){
	        //0.创建棋盘
	    char winner = ' ';
	    SetChessboard();
	        while (1){
				system("cls");
			//1.打印棋盘
			Print();
			//2.玩家走
			PeopleGo();
			//3.检测游戏是否结束

		winner = CheckOver();
		if (winner != ' '){
			break;
		}
			//4.电脑走
			ComputerGo();
			//5.检测游戏是否结束
		winner = CheckOver();
		if (winner != ' '){
			break;
		}
	} 
			system("cls ");
			if (winner == 'x'){
				printf("你赢了!!\n");
			}
			else if (winner == 'o'){
				printf("你输了!!\n");
			}
			else if (winner == 'q'){
				printf("和棋!!\n");
			}
			else{
				printf("出错了!!\n");
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
			printf("有缘再见!!\n");
			break;
		}
	}
	system("pause");
	return 0;
}