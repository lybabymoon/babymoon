#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define  Max_row 15
#define  Max_col 15
void Menu(){
	printf("******************\n");
	printf("****1.游戏开始****\n");
	printf("****0.退出游戏****\n");
	printf("******************\n");
}

char chessboard[Max_row][Max_col];

void SetChessboard(){
	for (int row = 0; row < Max_row; ++row){
		for (int col = 0; col < Max_col; ++col){
			chessboard[row][col] = ' ';
		}
	}
}
void Print(){
	/*    printf("    |");
	for (int col = 0; col < Max_col; ++col){
		printf(" %d  ", col);
	}
    for (int row = 0; row < Max_row; ++row){
		    printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", chessboard[row][0],
			chessboard[row][1], chessboard[row][2], chessboard[row][3],
			chessboard[row][4], chessboard[row][5], chessboard[row][6],
			chessboard[row][7], chessboard[row][8], chessboard[row][9],
			chessboard[row][10], chessboard[row][11], chessboard[row][12],
			chessboard[row][13], chessboard[row][14]);
		if (row != Max_row - 1){
			printf("|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
		}
	}*/
	int i = 0;
	int j = 0;

	for (i = 0; i < Max_row; i++)
	{
		printf("   %d", i); //打印棋盘 x 轴坐标提示
	}
	printf("\n");

	for (j = 0; j < Max_col; j++)
	{
		printf("---|"); //打印第一行棋盘
	}
	printf("\n");

	for (i = 0; i < Max_row; i++)
	{
		for (j = 0; j < Max_col; j++)
		{
			printf(" %c |", chessboard[i][j]); //打印竖标
		}
		printf(" %d ", i); //打印棋盘 y 轴坐标提示
		printf("\n");

		for (j = 0; j < Max_col; j++)
		{
			printf("---|"); //打印横标
		}
		printf("\n");
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
		if (chessboard[row][col] != ' '){
			printf("您输入的坐标已经被占了!!!\n");
			continue;
		}
		chessboard[row][col] = 'x';
		break;
	}
}
// x玩家胜,o电脑胜,q和棋
char CheckOver(){
	int i = 0;
	int j = 0;

	// 横线上五子连成一线，赢家产生
	for (i = 0; i < Max_row; i++)
	{
		for (j = 0; j < Max_col - 4; j++)
		{
			if (chessboard[i][j] == chessboard[i][j + 1]
				&& chessboard[i][j + 1] == chessboard[i][j + 2]
				&& chessboard[i][j + 2] == chessboard[i][j + 3]
				&& chessboard[i][j + 3] == chessboard[i][j + 4]
				&& chessboard[i][j] != ' ')
			{
				return chessboard[i][j];
			}
		}
	}

	// 竖线上五子连成一线，赢家产生
	for (j = 0; j < Max_col; j++)
	{
		for (i = 0; i < Max_row - 4; i++)
		{
			if (chessboard[i][j] == chessboard[i + 1][j]
				&& chessboard[i + 1][j] == chessboard[i + 2][j]
				&& chessboard[i + 2][j] == chessboard[i + 3][j]
				&& chessboard[i + 3][j] == chessboard[i + 4][j]
				&& chessboard[i][j] != ' ')
			{
				return chessboard[i][j];
			}
		}
	}

	// 斜线上五子连成一线，赢家产生
	for (i = 0; i < Max_row - 4; i++)
	{
		if (chessboard[i][i] == chessboard[i + 1][i + 1]
			&& chessboard[i + 1][i + 1] == chessboard[i + 2][i + 2]
			&& chessboard[i + 2][i + 2] == chessboard[i + 3][i + 3]
			&& chessboard[i + 3][i + 3] == chessboard[i + 4][i + 4]
			&& chessboard[i][i] != ' ')
		{
			return chessboard[i][i];
		}

		if (chessboard[i][i + 4] == chessboard[i + 1][i + 3]
			&& chessboard[i + 1][i + 3] == chessboard[i + 2][i + 2]
			&& chessboard[i + 2][i + 2] == chessboard[i + 3][i + 1]
			&& chessboard[i + 3][i + 1] == chessboard[i + 4][i]
			&& chessboard[i][i + 4] != ' ')
		{
			return chessboard[i][i + 4];
		}
	}

	//游戏平局
	if(IsFull())
	{
		return 'p';
	}

	//游戏结束
	return ' ';
}
void ComputerGo(){
	printf("电脑落子!\n");
	while (1){
		int row = rand() % Max_row;
		int col = rand() % Max_col;
		if (chessboard[row][col] != ' '){
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
	else if (winner == 'p'){
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
		else if (choice == 0){
			break;
		}
	}
	system("pause");
	return 0;
}