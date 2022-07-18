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
	printf("hi~\n我是你可爱滴小电脑(●^v^●) \n\n");
	printf("陪陪我嘛~来和我下一盘棋好不好？\n");
	printf("             ↓↓              \n\n");
	srand((unsigned int)time(0));
	while (1){
		int choice = menu();
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			printf("不玩就不玩，哼！拜拜了您！！\n");
			break;
		}
		else{
			printf("让你选0和1，就不要输别的东西嘛(ˉ▽ˉ；)...\n");
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
	printf("\n\n\n规则：\n括号内的数字是格子的横纵坐标！\n\n下棋的时候先输行坐标，再输列坐标，不许乱下！\n\n");
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
		printf("你要下哪？\n输入棋盘落子坐标（row col）：");
		scanf("%d %d", &row, &col);
		
		if (row < 0 || row >= ROWS || col < 0 || col >= COLS){
			printf("\n你输的坐标不在有效范围 [0, 2] 内，再输一次！！！>：\n");
			continue;
		}
		if (chessBoard[row][col] != ' '){
			printf("你要下棋的位置已经有棋子了噢!\n");
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
		printf("哎呦，居然赢了，厉害噢！		(T_T)\n");
	}
	else if (winner == 'o') {
		printf("我赢啦！你输啦，嘿嘿！		o(*￣▽￣*)ブ\n");
	}
	else {
		printf("平局，一般般吧		(ˉ▽ˉ；)\n");
	}
}

int menu(){
	printf("-------【三子棋小游戏】-------\n\n");
	printf("$           1.开始           $\n");
	printf("$           0.退出           $\n");
	printf("--------------------------\n");
	int choice = 0;
	printf("来一局？:>");
	scanf("%d", &choice);
	return choice;
}
