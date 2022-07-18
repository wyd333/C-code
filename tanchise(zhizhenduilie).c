/* WIN-TC BGI 图形编程模板 */

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
/* 消失身体*/
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
/* 新增加一个节点*/
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
    discircle(end->x,end->y); /*删除尾巴*/
    switch(dirction)          /*前进一位*/
    {
        case UP:    end->y=head->y-1;end->x=head->x;break;
        case DOWN:  end->y=head->y+1;end->x=head->x;break;
        case RIGHT: end->x=head->x+1;end->y=head->y;break;
        case LEFT:  end->x=head->x-1;end->y=head->y;break;
    }
    /* 吃到食物，重画食物*/
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
void initgr(void) /* BGI初始化 */
{
  int gd = DETECT, gm = 0; /* 和gd = VGA,gm = VGAHI是同样效果 */
  registerbgidriver(EGAVGA_driver);/* 注册BGI驱动后可以不需要.BGI文件的支持运行 */
  initgraph(&gd, &gm, "");
}

int main(void)
{
  int key=0;

  initgr(); /* BGI初始化 */

  randomize(); /* 随即函数初始化*/
  /* 画食物*/
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
      /* 检测按键*/
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

  /*****此部分添加你自己的代码，例如
  line(25, 25, 220, 220);
  circle(100, 100, 50);
  等等*****/

  getch(); /* 暂停一下，看看前面绘图代码的运行结果 */
  closegr(); /* 恢复TEXT屏幕模式 */
  return 0;
}
