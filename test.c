//������������Ϸ
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
		
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input){
		case 1:
			printf("��Ϸ��ʼ��");
			break;
		case 0:
			printf("�˳���Ϸ��");
			break;
			default:
				printf("��������ȷ��ѡ�");
				break;
		}
	} while (input);
	
}


int main() {
	test();
	
	return 0;
}
