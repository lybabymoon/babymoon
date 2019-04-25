#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define  Max_row 15
#define  Max_col 15
void Menu(){
	printf("******************\n");
	printf("****1.��Ϸ��ʼ****\n");
	printf("****0.�˳���Ϸ****\n");
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
		printf("   %d", i); //��ӡ���� x ��������ʾ
	}
	printf("\n");

	for (j = 0; j < Max_col; j++)
	{
		printf("---|"); //��ӡ��һ������
	}
	printf("\n");

	for (i = 0; i < Max_row; i++)
	{
		for (j = 0; j < Max_col; j++)
		{
			printf(" %c |", chessboard[i][j]); //��ӡ����
		}
		printf(" %d ", i); //��ӡ���� y ��������ʾ
		printf("\n");

		for (j = 0; j < Max_col; j++)
		{
			printf("---|"); //��ӡ���
		}
		printf("\n");
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
		if (chessboard[row][col] != ' '){
			printf("������������Ѿ���ռ��!!!\n");
			continue;
		}
		chessboard[row][col] = 'x';
		break;
	}
}
// x���ʤ,o����ʤ,q����
char CheckOver(){
	int i = 0;
	int j = 0;

	// ��������������һ�ߣ�Ӯ�Ҳ���
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

	// ��������������һ�ߣ�Ӯ�Ҳ���
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

	// б������������һ�ߣ�Ӯ�Ҳ���
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

	//��Ϸƽ��
	if(IsFull())
	{
		return 'p';
	}

	//��Ϸ����
	return ' ';
}
void ComputerGo(){
	printf("��������!\n");
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
	else if (winner == 'p'){
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
		else if (choice == 0){
			break;
		}
	}
	system("pause");
	return 0;
}