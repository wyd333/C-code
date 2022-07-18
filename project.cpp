#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3

void game_init(char chessBoard[ROWS][COLS]);
void print_chessBoard(char chessBoard[ROWS][COLS]);
void player(char chessBoard[ROWS][COLS]);
void computer(char chessBoard[ROWS][COLS]);
int is_Full(char chessBoard[ROWS][COLS]);
char judgeWin(char chessBoard[ROWS][COLS]);
void game();
int menu();


int main()
{
	printf("hi~\n������ɰ���С����(��^v^��) \n\n");
	printf("��������~��������һ����ò��ã�\n");
	printf("             ����              \n\n");
	srand((unsigned int)time(0));
	while (1){
		int choice = menu();
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			printf("����Ͳ��棬�ߣ��ݰ���������\n");
			break;
		}
		else{
			printf("����ѡ0��1���Ͳ�Ҫ���Ķ�����(��������)...\n");
			continue;
		}
	}
	printf("\n\n");
	system("pause");
	return 0;
}

void game_init(char chessBoard[ROWS][COLS]){
	for (int row = 0; row < ROWS; row++){
		for (int col = 0; col < COLS; col++){
			chessBoard[row][col] = ' ';
		}
	}
}

void print_chessBoard(char chessBoard[ROWS][COLS]){
	printf("\n\n\n����\n�����ڵ������Ǹ��ӵĺ������꣡\n\n�����ʱ�����������꣬���������꣬�������£�\n\n");
	printf("+(0)+(1)+(2)+\n");
	printf("+---+---+---+\n");
	for (int row = 0; row < ROWS; row++) {
		printf("| %c | %c | %c |(%d)\n", chessBoard[row][0],chessBoard[row][1], chessBoard[row][2],row);
		printf("+---+---+---+\n");
	}
}

void player(char chessBoard[ROWS][COLS]){
	while (1){
		int row = 0;
		int col = 0;
		printf("��Ҫ���ģ�\n���������������꣨row col����");
		scanf("%d %d", &row, &col);
		
		if (row < 0 || row >= ROWS || col < 0 || col >= COLS){
			printf("\n��������겻����Ч��Χ [0, 2] �ڣ�����һ�Σ�����>��\n");
			continue;
		}
		if (chessBoard[row][col] != ' '){
			printf("��Ҫ�����λ���Ѿ�����������!\n");
			continue;
		}
		chessBoard[row][col] = 'x';
		break;
	}
}

void computer(char chessBoard[ROWS][COLS]){
	while (1){
		int row = rand() % ROWS;
		int col = rand() % COLS;
		if (chessBoard[row][col] != ' ') {
			continue;
		}
		chessBoard[row][col] = 'o';
		break;
	}
}

int is_Full(char chessBoard[ROWS][COLS]){
	for (int row = 0; row < ROWS; row++){
		for (int col = 0; col < COLS; col++){
			if (chessBoard[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}

char judgeWin(char chessBoard[ROWS][COLS]){
	for (int row = 0; row < ROWS; row++) {
		if ((chessBoard[row][0] != ' ')&&(chessBoard[row][0] == chessBoard[row][1])&&(chessBoard[row][0] == chessBoard[row][2])) {
			return chessBoard[row][0];
		}
	}
	for (int col = 0; col < COLS; col++) {
		if (chessBoard[0][col] != ' ' && chessBoard[0][col] == chessBoard[1][col] && chessBoard[0][col] == chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	if (chessBoard[0][0] != ' ' && chessBoard[0][0] == chessBoard[1][1] && chessBoard[0][0] == chessBoard[2][2]) {
		return chessBoard[0][0];
	}
	if (chessBoard[2][0] != ' ' && chessBoard[2][0] == chessBoard[1][1] && chessBoard[2][0] == chessBoard[0][2]) {
		return chessBoard[2][0];
	}
	if (is_Full(chessBoard)) {
		return 'q';
	}
	return ' ';
}

void game(){
	char chessBoard[ROWS][COLS] = { 0 };
	game_init(chessBoard);
	char winner = ' ';
	while (1){
		system("cls");
		print_chessBoard(chessBoard);
		player(chessBoard);
		winner = judgeWin(chessBoard);
		if (winner != ' ') {
			break;
		}
		computer(chessBoard);
		winner = judgeWin(chessBoard);
		if (winner != ' ') {
			break;
		}
	}
	print_chessBoard(chessBoard);
	if (winner == 'x') {
		printf("���ϣ���ȻӮ�ˣ������ޣ�		(T_T)\n");
	}
	else if (winner == 'o') {
		printf("��Ӯ�������������ٺ٣�		o(*������*)��\n");
	}
	else {
		printf("ƽ�֣�һ����		(��������)\n");
	}
}

int menu(){
	printf("-------��������С��Ϸ��-------\n\n");
	printf("$           1.��ʼ           $\n");
	printf("$           0.�˳�           $\n");
	printf("--------------------------\n");
	int choice = 0;
	printf("��һ�֣�:>");
	scanf("%d", &choice);
	return choice;
}
