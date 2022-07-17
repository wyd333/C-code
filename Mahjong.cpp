#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

void Initial(int a[8][8]);/*初始化*/
int Output(int a[8][8]);/*输出*/
void Sort(int a[8][8]);/*重排*/
void Change(int a[8][8],int x,int y,int x1,int y1);/*交换数组内两坐标对的符号值*/
void Judge(int a[8][8],int b[4]);/*判断是否能够消除*/
void Zero(int a[8][8],int b[4]);/*设置为零，即：消除*/

int Two(int a[8][8],int b[4]);/*两条线*/

void Check(int a[8][8],int x,int y,char c[5]);/*返回某点上下左右的情况*/

int  UpDown(int a[8][8],int b[4],int g);
int  LeftRight(int a[8][8],int b[4],int g);

int main()
{
	int flag=1,flag1=1;
	//flag用于标记是否已经初始化，flag=1表示未初始化；flag1标记用户是否选择了退出，flag1=1表示未选择。
	int a[8][8]={0};//0 表示空格。使用数组a[8][8]存放符号值，其中仅用了下标1-6.
	int b[4];/*接收坐标*/
	char ch;
	do 
	{
		    int o;//用于标记是否已经获胜。
	        if(flag)
			{
				Initial(a);
				flag=0;
			}
			o=Output(a);
			if(o==0)
			{
				char ch;
				system("cls");
				cout << "您已经获胜！！按Enter键确定。" << endl;
				while(1)//确保用户输入 的是Enter键
				{
					ch=getch();
					if(ch==13)
						break;
				}
				flag=1;//标记为未初始化。
				system("cls");
				continue;//跳出本次循环，开始新的一局。				
			}


			while(1)//确保用户的输入符合要求
			{
				ch=getch();
				if(ch=='a'||ch=='A'
				   ||ch=='b'||ch=='B'
				   ||ch=='c'||ch=='C'
				   ||ch=='d'||ch=='D')
				
				{
					putchar(ch);
					break;
				}
			}

			switch(ch)//根据用户的选择进行处理。
			{
				case 'a':
				case 'A':
					{
						cout << endl;
						cout << "请输入坐标：" << endl;
						fflush(stdin);
						cin >> b[0] >> b[1] >> b[2] >> b[3];
						break;
					}
				case 'b':
			    case 'B':
					{
						Sort(a);
						break;
					}
				case 'c':
				case 'C':
					{
						flag=1;
						break;
					}
				case 'd':
				case 'D':
					{
						flag1=0;
						break;
					}
			}
			if(ch!='a'&&ch!='A')
				system("cls");
			else                 //若用户输入坐标，则进行判断
			{
				Judge(a,b);
				system("cls");
			}
	}while(flag1);
	cout << "游戏已退出！" << endl;
return 0;
}




void Initial(int a[8][8])//用以初始化数组存放的符号值
{
	
	int i,j,m=0,k=1;//k值表示符号类别，m表示每个符号必须出现以2的倍数出现，出现两次
	for(i=1;i<=6;i++)
		for(j=1;j<=6;j++)
		{
		   if(k>12)
			   k=k%12;//k值大于12后，符号类型循环，最多11种符号，0表示空
           a[i][j]=k;
		   m++;
		   if(m%2==0)//每种符号赋两个，
		      k++;
		}
	Sort(a);//进行随机重排。
}

int Output(int a[8][8])           /*输出，对应符号

   ☆ ★ ○ ● ◎ ◇ ■ ∷ ⊙ ﹫ ¤ ﹩
	
	 同时，判断是否胜利 */
{
	int i,j,flag1=0;//flag1用于记录输出的空格数，当flag1=64时，表示所有的都已消完，获胜。
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			switch(a[i][j])//根据二维数组a中的值输出相应的符号
			{
			   case 0:
				   flag1++;
				   cout << "  ";
				   break;
			   case 1:
				   cout << "☆";
				   break;				   
			   case 2:
				   cout << "★";
				   break;
			   case 3:
				   cout << "○";
				   break;
			   case 4:
				   cout << "●";
				   break;
			   case 5:
				   cout << "◎";
				   break;
			   case 6:
				   cout << "◇";
				   break;
			   case 7:
				   cout << "■";
				   break;
			   case 8:
				   cout << "∷";
				   break;
			   case 9:
				   cout << "⊙";
				   break;
			   case 10:
				   cout << "﹫";
				   break;
			   case 11:
				   cout << "¤";
				   break;
			   case 12:
				   cout << "﹩";
				   break;
			}
		}
		if(i>0&&i<7)
		{
			cout << '\t' << '\t';			
			for(j=1;j<=6;j++)
			{
				cout << "<" << i << "," << j << ">,";				
			}
		}
		cout << endl;		
	}
	if(flag1==64)
			return 0;
	cout << endl;
	cout << "选项：" << endl;
	cout << '\t' << '\t' << 'a' << '\t' << "输入坐标；" << endl;
	cout << '\t' << '\t' << 'b' << '\t' << "重排；" << endl;
	cout << '\t' << '\t' << 'c' << '\t' << "重新开始；" << endl;
	cout << '\t' << '\t' << 'd' << '\t' << "退出；" << endl;
	cout << endl;
	cout << "坐标输入格式：" << endl << "1 2" << endl << "3 6" << endl <<"然后按Enter。" << endl;
	cout << "选择：";
	return 1;
}




void Change(int a[8][8],int x,int y,int x1,int y1)/*交换*/
{
	int temp;
	temp=a[x][y];
	a[x][y]=a[x1][y1];
	a[x1][y1]=temp;
}

void Sort(int a[8][8])//对数组内的符号随机交换，打乱符号的位置，注意坐标必须是1-6之间
{
	int x1,y1,i,j;
	srand((unsigned)time(NULL));
	for(i=1;i<=6;i++)
		for(j=1;j<=6;j++)
		{
			x1=rand()%(6-1+1)+1;
			y1=rand()%(6-1+1)+1;
			//随机产生一个坐标（x1,y1）;
			Change(a,i,j,x1,y1);//将a(i,j)的值与a(x1,y1)的值交换
		}

}
void Judge(int a[8][8],int b[4])/*判断是否能够消除*/
{
	
   if(a[b[0]][b[1]]==a[b[2]][b[3]]&&!(b[0]==b[2]&&b[1]==b[3]))
   {
	   
	   if((b[0]==b[2]&&abs(b[3]-b[1])==1)
		   ||(b[1]==b[3]&&abs(b[0]-b[2])==1))/*判断两点紧邻*/
	   {	  
		   Zero(a,b);
	       return;
	   }
	   if((b[0]==b[2]&&(b[0]==1||b[0]==6))
		   ||(b[1]==b[3]&&(b[1]==6||b[1]==1)))/*判断两点在边界上*/
	   {
		   Zero(a,b);
		   return;
	   }
	   if(b[0]==b[2])                      /*两点在同一行上*/
	   {
		   int n,m;//n为两个数中较大的值，m为两数中较小的。
		   n=b[3]>b[1]?b[3]:b[1];
		   m=b[3]>b[1]?b[1]:b[3];
		   n=n-1;
		   while(n>m)
		   {
			   //从右往左依次查看，看在此行，两点之间是否均为空格
			   if(a[b[0]][n]==0)
				   n--;
			   else
				  break;
		   }
		   if(n==m)//在此行，两点之间均为空格。
		   {	  
			   Zero(a,b);
               return;
		   }
	   }
	   if(b[1]==b[3])        /*两点在同一列*/
	   {
		   int n,m;//n为两个数中较大的值，m为两数中较小的。
		   n=b[2]>b[0]?b[2]:b[0];
		   m=b[2]>b[0]?b[0]:b[2];
		   n=n-1;
		   while(n>m)
		   {
               //从下往上依次查看，看在此列，两点之间是否均为空格
			   if(a[n][b[1]]==0)
				   n--;
			   else
				   break;
		   }
		   if(n==m)//在此列，两点之间均为空格
		   {
			   Zero(a,b);
			   return;
		   }

	   }
	   if(1)//为了添加局部变量i，所以用if(1),优点：使变量i存在的时间尽可能短。
	   {
		   int i;//标记是否符合两条线的情况。i=1表示符合，
		   i=Two(a,b);
		   if(i==1)
		     return;
	   }
	   if(1)//为了添加局部变量f,w,e，所以用if(1),优点：使变量f,e,w存在的时间尽可能短。
	   {
		   //三条线的情况
		   int f,w;
		   int e;
		   char c1[5],c2[5],c3[5]="1111";
		   //检查(b[0],b[1]),(b[2],b[3])上、下、左、右的情况
		   Check(a,b[0],b[1],c1);
		   Check(a,b[2],b[3],c2);
		   if(strcmp(c1,c3)==0||strcmp(c2,c3)==0)//两点中只要有一点四周均不为空，两点就不能连通，即：不可消除。
			   return;
		   for(e=0;e<=3;e++)//比较两点四周的情况
		   {
			   int r[4];
			   //b数组中的值不可变化，因此用r数组接收b数组中的值
		       r[0]=b[0];
			   r[1]=b[1];
			   r[2]=b[2];
			   r[3]=b[3];
			   if(c1[e]==c2[e]&&c1[e]=='0')
			   {
				   switch(e)
				   {
				     case 0://两点上方均有空格
						   //依次检查(b[0],b[1])上方的点是否为空格（直到边界），若为空格则检查该点与(b[2],b[3])
						   //是否能通过两条线连通
						   while(r[0]>0)
						   {
							   r[0]=r[0]-1;
							   if(a[r[0]][r[1]]!=0)//只要不为空格就已说明不可连通
								   break;
							   if(Two(a,r)==1)
							   {   
								   Zero(a,b);
								   return;
							   }
						   }
						   break;
					 case 1://两点下方均有空格
						   //依次检查(b[0],b[1])下方的点是否为空格（直到边界），若为空格则检查该点与(b[2],b[3])
						   //是否能通过两条线连通
						   while(r[0]<8)
						   {
							   r[0]=r[0]+1;
							   if(a[r[0]][r[1]]!=0)//只要不为空格就已说明不可连通
								   break;
							   if(Two(a,r)==1)
							   {
								   Zero(a,b);
								   return;
							   }
						   }
				           break;
					 case 2:
						 //两点左边均有空格
						   //依次检查(b[0],b[1])左边的点是否为空格（直到边界），若为空格则检查该点与(b[2],b[3])
						   //是否能通过两条线连通
						   while(r[1]>0)
						   {
							   r[1]=r[1]-1;
							   if(a[r[0]][r[1]]!=0)//只要不为空格就已说明不可连通
								   break;
							   if(Two(a,r)==1)
							   {
								   Zero(a,b);
								   return;
							   }

						   }
						   break;
					 case 3:
						 //两点右边均有空格
						   //依次检查(b[0],b[1])右边的点是否为空格（直到边界），若为空格则检查该点与(b[2],b[3])
						   //是否能通过两条线连通
						   while(r[1]<8)
						   {
							   r[1]+=1;
							   if(a[r[0]][r[1]]!=0)//只要不为空格就已说明不可连通
								   break;
							   if(Two(a,r)==1)
							   {
								   Zero(a,b);
								   return;
							   }
						   }
                           break;
				   }
			   }
		   }

           f=b[2]-b[0];//f>0表示(b[2],b[3])在(b[0],b[1])下方，f<0表示(b[2],b[3])在(b[0],b[1])上方

		   w=b[3]-b[1];//w>0表示(b[2],b[3])在(b[0],b[1])右方，w<0表示(b[2],b[3])在(b[0],b[1])左方


		   if(f>0&&w>0)                        /*(b[2],b[3])在(b[0],b[1])右下*/
		   {
			   if(c2[0]=='0'&&c1[1]=='0') //(b[2],b[3])的上方为空格，(b[0],b[1])的下方为空格
			   { 
	              if(UpDown(a,b,1))
					   return;
			   }
               if(c2[2]=='0'&&c1[3]=='0')//(b[2],b[3])的左边为空格，(b[0],b[1])的右边为空格
			   {
				   if(LeftRight(a,b,1))
					   return;
			   }
		   }
		   if(f<0&&w>0)                       /*(b[2],b[3])在(b[0],b[1])右上*/
		   {
			   if(c2[1]=='0'&&c1[0]=='0')   //(b[2],b[3])的下方为空格，(b[0],b[1])的上方为空格
			   {
				   if(UpDown(a,b,0))
					   return;
			   }
			   if(c2[2]=='0'&&c1[3]=='0')//(b[2],b[3])的左边为空格，(b[0],b[1])的右边为空格
			   {
				   if(LeftRight(a,b,1))
					   return;
			   }
		   }
		   if(f>0&&w<0)                     /*(b[2],b[3])在(b[0],b[1])左下*/
		   {
			   if(c2[0]=='0'&&c1[1]=='0')//(b[2],b[3])的上方为空格，(b[0],b[1])的下方为空格
			   {
				    if(UpDown(a,b,1))
					   return;
			   }
               if(c2[3]=='0'&&c1[2]=='0')//(b[2],b[3])的右边为空格，(b[0],b[1])的左边为空格
			   {
				   if(LeftRight(a,b,0))
					   return;
			   }
		   }
		   if(f<0&&w<0)                    /*(b[2],b[3])在(b[0],b[1])左上*/
		   {
			   if(c2[1]=='0'&&c1[0]=='0') //(b[2],b[3])的下方为空格，(b[0],b[1])的上方为空格
			   {
				   if(UpDown(a,b,0))
					   return;
			   }
               if(c2[3]=='0'&&c1[2]=='0')//(b[2],b[3])的右边为空格，(b[0],b[1])的左边为空格
			   {
				   if(LeftRight(a,b,0))
					   return;
			   }

		   }

		   
		}

	}
	   

}
void Zero(int a[8][8],int b[4])/*设置为零*/
{
	a[b[0]][b[1]]=0;
	a[b[2]][b[3]]=0;
}
void Check(int a[8][8],int x,int y,char c[5])/*返回某点上下左右的情况*/
{
	//1 表示不为空格，0表示为空格，
	//c[0],c[1],c[2],c[3]分别表示某点上下左右的情况
     if(a[x-1][y]==0)//(x,y)上一格为空
		 c[0]='0';
	 else
		 c[0]='1';

     if(a[x+1][y]==0)//(x,y)下一格为空
		 c[1]='0';
	 else
		 c[1]='1';

	 if(a[x][y-1]==0)//(x,y)左一格为空
		 c[2]='0';
	 else
		 c[2]='1';

	 if(a[x][y+1]==0)//(x,y)右一格为空
		 c[3]='0';
	 else
		 c[3]='1';
	 c[4]='\0';
}
int Two(int a[8][8],int b[4])    /*两条线*/
{
	int m,n;
	int c,d; //(c,d)为可动检验点坐标

	n=b[2]-b[0];          /*行间距*/
	m=b[3]-b[1];         /*列间距*/
	d=b[2];
	c=b[3]-m;//b[1]
	while(c!=b[3])// 验证是否存在水平通道(b[2],b[3])到(b[2],b[1])。
	{
		if(a[d][c]==0)
			c+=(m/abs(m));
		else
			break;
	}
	if(c==b[3])//存在水平通道
	{
		c=b[3]-m;
		while(d!=b[0])//验证是否存在竖直通道(b[2],b[1])到(b[0],b[1])。
		{
			if(a[d][c]==0)
				d-=(n/abs(n));
			else
				break;
		}
		if(d==b[0])//存在竖直通道。
		{
			Zero(a,b);
			return 1;
		}
		
	}
	c=b[3];
	d=b[2]-n;
	while(d!=b[2])//验证是否存在竖直通道(b[2],b[3])到(b[0],b[3])。
	{
		if(a[d][c]==0)
			d+=(n/abs(n));
		else
			break;
	}
	if(d==b[2])//存在竖直通道
	{
		
		d=b[2]-n;
	    while(c!=b[1])// 验证是否存在水平通道(b[0],b[3])到(b[0],b[1])。
		{
			if(a[d][c]==0)
				c-=(m/abs(m));
			else
				break;
		}
		if(c==b[1])
		{
			Zero(a,b);
			return 1;
		}
		else
			return 0;
	}	
}
int  UpDown(int a[8][8],int b[4],int g)
{
	int r[4],i;
	for(i=0;i<4;i++)
		r[i]=b[i];
	//g=1表示(b[2],b[3])在(b[0],b[1])的下方，g=0表示(b[2],b[3])在(b[0],b[1])的上方
	if(g)
	{  
		 //依次检查(b[2],b[3])上边的点是否为空格（直到(b[0],b[3])下方紧邻点），若为空格则检查该点与(b[0],b[1])
		//是否能通过两条线连通
		r[0]=r[0]+1;
		while(r[2]>=r[0])
		{
           r[2]-=1;
		   if(Two(a,r)==1)
		   {
			Zero(a,b);
            return 1;
		   }
		}
	}
	else
	{
		 //依次检查(b[2],b[3])下边的点是否为空格（直到(b[0],b[3])上方紧邻点），若为空格则检查该点与(b[0],b[1])
		//是否能通过两条线连通
		r[0]=r[0]-1;
		while(r[2]<=r[0])
		{
           r[2]+=1;
		   if(Two(a,r)==1)
		   {
			Zero(a,b);
            return 1;
		   }
		}
	}
    return 0;
}

int LeftRight(int a[8][8],int b[4],int g)
{
	int r[4],i;
	for(i=0;i<4;i++)
		r[i]=b[i];
    //g=1表示(b[2],b[3])在(b[0],b[1])的右方，g=0表示(b[2],b[3])在(b[0],b[1])的左方
	if(g)
	{
        //依次检查(b[2],b[3])左边的点是否为空格（直到(b[2],b[1]右边紧邻的点），若为空格则检查该点与(b[0],b[1])
		//是否能通过两条线连通
		r[1]=r[1]+1;
		while(r[3]>=r[1])
		{
		   r[3]-=1;
		   if(Two(a,r)==1)
		   {
			   Zero(a,b);
			   return 1;
		   }
		}
	}
	else
	{
		//依次检查(b[2],b[3])右边的点是否为空格（直到(b[2],b[1]左边紧邻的点），若为空格则检查该点与(b[0],b[1])
		//是否能通过两条线连通
		r[1]-=1;
        while(r[3]<=r[1])
		{
		   r[3]+=1;
		   if(Two(a,r)==1)
		   {
			   Zero(a,b);
			   return 1;
		   }
		}

	}
	return 0;
}
