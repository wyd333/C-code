#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
//��������Ϸ

//�˵���
void menu(){
	printf("********************\n");
	printf("**  ����Ϸ�˵���  **\n");
	printf("*                  *\n");
	printf("*      1.��ʼ      *\n");
	printf("*      0.�˳�      *\n");
	printf("********************\n");
	
}
//��Ϸʵ��
int game(int guess,int key){
	if(guess > key){
		return 1;
	}else if(guess == key){
		return 0;
	}else if(guess < key){
		return -1;
	}
	return -2;
}

int main(){
	int input = 0;
	int guess = 0;
	srand((unsigned)time(NULL));
	//��Ϸ�������̿���
	do{
		menu();
		printf("Game begin now??:>");
		scanf("%d",&input);
		switch (input) {
			case 1:{
				int key = rand()%101;	//	0��100֮��
				printf("Game Begin!\n");
				printf("Please enter the number you want to guess:>\n");
				
				while(1){
					scanf("%d",&guess);
					
					if(game(guess,key) == 1){
						printf("Too large! Please enter again!>:\n");
					}else if(game(guess,key) == 0){
						printf("WOW! You get it!!\n");
						break;
					}else if(game(guess,key) == -1){
						printf("Too small! Please enter again!>:\n");
					}
				}
				break;
			}
			case 0:
				printf("�˳���Ϸ��\n");
				break;
			default:
				printf("��������ȷ��ѡ�\n");
				break;
		}
		Sleep(2000);
		system("cls");
	}while(input);	
}

