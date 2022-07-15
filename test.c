//测试三子棋游戏
#include"game.h"

void menu() {
	printf("***************************\n");
	printf("**** 1.play		0.exit ****\n");
	printf("***************************\n");
}

void test() {
	int input = 0;
	do {
		menu();
		
		printf("请选择:>");
		scanf("%d", &input);
		switch (input){
		case 1:
			printf("游戏开始！");
			break;
		case 0:
			printf("退出游戏！");
			break;
			default:
				printf("请输入正确的选项！");
				break;
		}
	} while (input);
	
}


int main() {
	test();
	
	return 0;
}
