/* WIN-TC BGI ͼ�α��ģ�� */

#include "Conio.h"
#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#define closegr closegraph


#define R 10

#define UP    0
#define DOWN  1
#define RIGHT 2
#define LEFT  3

#define UPKEY     18432
#define DOWNKEY   20480
#define LEFTKEY   19200
#define RIGHTKEY  19712
#define ESC       283

int dirction=RIGHT;
int food_x=0;
int food_y=0;

struct node
{
     int x;
     int y;
     struct node *next;
};
#define SIZE sizeof(struct node)

struct node *head=0;
struct node *end=0;
struct node *newnode=0;

void delay(int x)
{
     int i;
     while(x--)
     {
         i=100000;
         while(i--);

     }
}
/* ��ʧ����*/
void drawcircle(int x,int y)
{
    setcolor(YELLOW);
    circle(x*R*2,y*R*2,R);
}
void discircle(int x, int y)
{
    setcolor(BLUE);
    circle(x*R*2,y*R*2,R);
}
/* ������һ���ڵ�*/
void addbody(void)
{
     newnode=malloc(SIZE);
     newnode->x=food_x;
     newnode->y=food_y;
     head->next=newnode;
     newnode->next=end;
     head=newnode;
  /*   newnode->next=end;  */
}
void go(void)
{
    int flag=0;
    int xx=end->x;
    int yy=end->y;
    discircle(end->x,end->y); /*ɾ��β��*/
    switch(dirction)          /*ǰ��һλ*/
    {
        case UP:    end->y=head->y-1;end->x=head->x;break;
        case DOWN:  end->y=head->y+1;end->x=head->x;break;
        case RIGHT: end->x=head->x+1;end->y=head->y;break;
        case LEFT:  end->x=head->x-1;end->y=head->y;break;
    }
    /* �Ե�ʳ��ػ�ʳ��*/
    if((end->x==food_x)&&(end->y==food_y))
    {
    end->x=xx;
    end->y=yy;
        addbody();
        food_x=random(20);
        food_y=random(20);
        drawcircle(food_x,food_y);
        drawcircle(end->next->x,end->next->y);
        flag=1;
    }
    else
    {
        head=end;
        end=end->next;
        drawcircle(head->x,head->y);
    }
    if(!flag)
    discircle(end->x,end->y);
    delay(5000);
}
void initgr(void) /* BGI��ʼ�� */
{
  int gd = DETECT, gm = 0; /* ��gd = VGA,gm = VGAHI��ͬ��Ч�� */
  registerbgidriver(EGAVGA_driver);/* ע��BGI��������Բ���Ҫ.BGI�ļ���֧������ */
  initgraph(&gd, &gm, "");
}

int main(void)
{
  int key=0;

  initgr(); /* BGI��ʼ�� */

  randomize(); /* �漴������ʼ��*/
  /* ��ʳ��*/
  food_x=random(20);
  food_y=random(20);
  drawcircle(food_x,food_y);

  newnode = malloc(SIZE);
  end  = malloc(SIZE);
  head = newnode;
  head->x=10;
  head->y=10;
  end->x=10;
  end->y=10;
  end = head->next;

  setbkcolor(BLUE);
  while(1)
  {
      /* ��ⰴ��*/
      if(bioskey(1))
      {
          key=bioskey(0);
          if((UPKEY==key)&&(dirction!=DOWN))dirction=UP;
          if((DOWNKEY==key)&&(dirction!=UP))dirction=DOWN;
          if((RIGHTKEY==key)&&(dirction!=LEFT))dirction=RIGHT;
          if((LEFTKEY==key)&&(dirction!=RIGHT))dirction=LEFT;
          if(key==ESC)exit(1);
      }
      go();
  }

  /*****�˲���������Լ��Ĵ��룬����
  line(25, 25, 220, 220);
  circle(100, 100, 50);
  �ȵ�*****/

  getch(); /* ��ͣһ�£�����ǰ���ͼ��������н�� */
  closegr(); /* �ָ�TEXT��Ļģʽ */
  return 0;
}
