#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Menu(){
	printf("*********************\n");
	printf("*******1.start*******\n");
	printf("*******0.quit********\n");
	printf("*********************\n");
	printf("please input your choice:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


#define Max_row 9
#define Max_col 9
#define Mine_Count 10

void  Init(char show_map[Max_row][Max_col],
	char mine_map[Max_row][Max_col]){
	//1.��ʼ�� show_map *
	for (int row = 0; row < Max_row; ++row){
		for (int col = 0; col < Max_col; ++col){
			show_map[row][col] = '*';
		}
	}
	//2.��ʼ�� mine_map 0
	for (int row = 0; row < Max_row; ++row){
		for (int col = 0; col < Max_col; ++col){
			mine_map[row][col] = '0';
		}
	}
	//3.����ҳ� 10��λ�õĵ���
	int mine_count = Mine_Count;
	while (mine_count > 0){
		int row = rand() % Max_row;
		int col = rand() % Max_col;
		if (mine_map[row][col] == '1'){
			continue;
		}
		mine_map[row][col] = '1';
		--mine_count;
	}
}

//51 minites
void  printMap(char map[Max_row][Max_col]){
	printf(" |");
	for (int col = 0; col < Max_col; col++){
		printf("%d ", col);
	}
	printf("\n");
	for (int col = 0; col < Max_col; col++){
		printf("--");
	}
	printf("\n");
		for (int row = 0; row < Max_row; ++row){
			printf("%d|", row);
			for (int col = 0; col < Max_col; ++col){
				printf("%c ", map[row][col]);
			}
			printf("\n");
	  }
}

void UpdateShowMap(int row, int col,
	char mine_map[Max_row][Max_col],
	char show_map[Max_row][Max_col]){
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0
		&& mine_map[row - 1][col - 1] == '1'){
		++count;
	}
	if (row - 1 >= 0
		&& mine_map[row - 1][col] == '1'){
		++count;
	}
	if (row - 1 >= 0 && col + 1 < Max_col
		&& mine_map[row - 1][col + 1] == '1'){
		++count;
	}
	if (col - 1 >= 0
		&& mine_map[row][col - 1] == '1'){
		++count;
	}
	if (col + 1 < Max_col
		&& mine_map[row][col + 1] == '1'){
		++count;
	}
	if (row + 1 < Max_row && col - 1 >= 0
		&& mine_map[row + 1][col - 1] == '1'){
		++count;
	}
	if (row + 1 < Max_row
		&& mine_map[row + 1][col] == '1'){
		++count;
	}
	if (row + 1 < Max_row && col + 1 < Max_row
		&& mine_map[row + 1][col + 1] == '1'){
		++count;
	}
	show_map[row][col] = count + '0';
}


//��ʼһ��Ϸ
void Game(){
	//1.����������λ���� ��Ϊ��ͼ
	char show_map[Max_row][Max_col];
	char mine_map[Max_row][Max_col];
	//2.��ʼ����ͼ
	Init(show_map, mine_map);
	int blank_count = 0;
	//3.print map
	while (1){
		system("cls");
		printMap(show_map);
		//4.��ʾ�������,У��
		printf("������Ҫ������λ��:\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= Max_row ||
			col < 0 || col >= Max_col){
			printf("�������,����������!!\n");
			continue;
		}
		if (show_map[row][col] != '*'){
			printf("����������Ѿ�����!\n");
			continue;
		}
		//5.�ж��Ƿ�����
		
		if (mine_map[row][col] == '1'){
			system("cls");
			printMap(mine_map);
			printf("������,����Ŭ��\n");
			return;
		}
		++blank_count;
		//6.�ж��Ƿ�ʤ��
		system("cls");
		if (blank_count == Max_row * Max_col - Mine_Count ){
			printf("��Ӯ��!!\n");
			return;
		}
		//7.������ҵ�ǰλ�õ�����
		UpdateShowMap(row, col,mine_map,show_map);
	}
}
int main(){
	srand((unsigned int)time(0));
	while (1){
		int choice = Menu();
		if (choice == 0){
			printf("See you next time!!\n");
			break;
		}
		else if (choice == 1){
			Game();
		}
		else{
			printf("You are mistake!!!\n");
		}
	}
	system("pause");
	return 0;
}