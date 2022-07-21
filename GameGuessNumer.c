#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
//猜数字游戏

//菜单栏
void menu(){
	printf("********************\n");
	printf("**  【游戏菜单】  **\n");
	printf("*                  *\n");
	printf("*      1.开始      *\n");
	printf("*      0.退出      *\n");
	printf("********************\n");
	
}
//游戏实现
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
	//游戏整体流程控制
	do{
		menu();
		printf("Game begin now??:>");
		scanf("%d",&input);
		switch (input) {
			case 1:{
				int key = rand()%101;	//	0到100之间
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
				printf("退出游戏！\n");
				break;
			default:
				printf("请输入正确的选项！\n");
				break;
		}
		Sleep(2000);
		system("cls");
	}while(input);	
}

