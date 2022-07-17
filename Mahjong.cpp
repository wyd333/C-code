#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

void Initial(int a[8][8]);/*��ʼ��*/
int Output(int a[8][8]);/*���*/
void Sort(int a[8][8]);/*����*/
void Change(int a[8][8],int x,int y,int x1,int y1);/*����������������Եķ���ֵ*/
void Judge(int a[8][8],int b[4]);/*�ж��Ƿ��ܹ�����*/
void Zero(int a[8][8],int b[4]);/*����Ϊ�㣬��������*/

int Two(int a[8][8],int b[4]);/*������*/

void Check(int a[8][8],int x,int y,char c[5]);/*����ĳ���������ҵ����*/

int  UpDown(int a[8][8],int b[4],int g);
int  LeftRight(int a[8][8],int b[4],int g);

int main()
{
	int flag=1,flag1=1;
	//flag���ڱ���Ƿ��Ѿ���ʼ����flag=1��ʾδ��ʼ����flag1����û��Ƿ�ѡ�����˳���flag1=1��ʾδѡ��
	int a[8][8]={0};//0 ��ʾ�ո�ʹ������a[8][8]��ŷ���ֵ�����н������±�1-6.
	int b[4];/*��������*/
	char ch;
	do 
	{
		    int o;//���ڱ���Ƿ��Ѿ���ʤ��
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
				cout << "���Ѿ���ʤ������Enter��ȷ����" << endl;
				while(1)//ȷ���û����� ����Enter��
				{
					ch=getch();
					if(ch==13)
						break;
				}
				flag=1;//���Ϊδ��ʼ����
				system("cls");
				continue;//��������ѭ������ʼ�µ�һ�֡�				
			}


			while(1)//ȷ���û����������Ҫ��
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

			switch(ch)//�����û���ѡ����д���
			{
				case 'a':
				case 'A':
					{
						cout << endl;
						cout << "���������꣺" << endl;
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
			else                 //���û��������꣬������ж�
			{
				Judge(a,b);
				system("cls");
			}
	}while(flag1);
	cout << "��Ϸ���˳���" << endl;
return 0;
}




void Initial(int a[8][8])//���Գ�ʼ�������ŵķ���ֵ
{
	
	int i,j,m=0,k=1;//kֵ��ʾ�������m��ʾÿ�����ű��������2�ı������֣���������
	for(i=1;i<=6;i++)
		for(j=1;j<=6;j++)
		{
		   if(k>12)
			   k=k%12;//kֵ����12�󣬷�������ѭ�������11�ַ��ţ�0��ʾ��
           a[i][j]=k;
		   m++;
		   if(m%2==0)//ÿ�ַ��Ÿ�������
		      k++;
		}
	Sort(a);//����������š�
}

int Output(int a[8][8])           /*�������Ӧ����

   �� �� �� �� �� �� �� �� �� �� �� ��
	
	 ͬʱ���ж��Ƿ�ʤ�� */
{
	int i,j,flag1=0;//flag1���ڼ�¼����Ŀո�������flag1=64ʱ����ʾ���еĶ������꣬��ʤ��
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			switch(a[i][j])//���ݶ�ά����a�е�ֵ�����Ӧ�ķ���
			{
			   case 0:
				   flag1++;
				   cout << "  ";
				   break;
			   case 1:
				   cout << "��";
				   break;				   
			   case 2:
				   cout << "��";
				   break;
			   case 3:
				   cout << "��";
				   break;
			   case 4:
				   cout << "��";
				   break;
			   case 5:
				   cout << "��";
				   break;
			   case 6:
				   cout << "��";
				   break;
			   case 7:
				   cout << "��";
				   break;
			   case 8:
				   cout << "��";
				   break;
			   case 9:
				   cout << "��";
				   break;
			   case 10:
				   cout << "��";
				   break;
			   case 11:
				   cout << "��";
				   break;
			   case 12:
				   cout << "��";
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
	cout << "ѡ�" << endl;
	cout << '\t' << '\t' << 'a' << '\t' << "�������ꣻ" << endl;
	cout << '\t' << '\t' << 'b' << '\t' << "���ţ�" << endl;
	cout << '\t' << '\t' << 'c' << '\t' << "���¿�ʼ��" << endl;
	cout << '\t' << '\t' << 'd' << '\t' << "�˳���" << endl;
	cout << endl;
	cout << "���������ʽ��" << endl << "1 2" << endl << "3 6" << endl <<"Ȼ��Enter��" << endl;
	cout << "ѡ��";
	return 1;
}




void Change(int a[8][8],int x,int y,int x1,int y1)/*����*/
{
	int temp;
	temp=a[x][y];
	a[x][y]=a[x1][y1];
	a[x1][y1]=temp;
}

void Sort(int a[8][8])//�������ڵķ���������������ҷ��ŵ�λ�ã�ע�����������1-6֮��
{
	int x1,y1,i,j;
	srand((unsigned)time(NULL));
	for(i=1;i<=6;i++)
		for(j=1;j<=6;j++)
		{
			x1=rand()%(6-1+1)+1;
			y1=rand()%(6-1+1)+1;
			//�������һ�����꣨x1,y1��;
			Change(a,i,j,x1,y1);//��a(i,j)��ֵ��a(x1,y1)��ֵ����
		}

}
void Judge(int a[8][8],int b[4])/*�ж��Ƿ��ܹ�����*/
{
	
   if(a[b[0]][b[1]]==a[b[2]][b[3]]&&!(b[0]==b[2]&&b[1]==b[3]))
   {
	   
	   if((b[0]==b[2]&&abs(b[3]-b[1])==1)
		   ||(b[1]==b[3]&&abs(b[0]-b[2])==1))/*�ж��������*/
	   {	  
		   Zero(a,b);
	       return;
	   }
	   if((b[0]==b[2]&&(b[0]==1||b[0]==6))
		   ||(b[1]==b[3]&&(b[1]==6||b[1]==1)))/*�ж������ڱ߽���*/
	   {
		   Zero(a,b);
		   return;
	   }
	   if(b[0]==b[2])                      /*������ͬһ����*/
	   {
		   int n,m;//nΪ�������нϴ��ֵ��mΪ�����н�С�ġ�
		   n=b[3]>b[1]?b[3]:b[1];
		   m=b[3]>b[1]?b[1]:b[3];
		   n=n-1;
		   while(n>m)
		   {
			   //�����������β鿴�����ڴ��У�����֮���Ƿ��Ϊ�ո�
			   if(a[b[0]][n]==0)
				   n--;
			   else
				  break;
		   }
		   if(n==m)//�ڴ��У�����֮���Ϊ�ո�
		   {	  
			   Zero(a,b);
               return;
		   }
	   }
	   if(b[1]==b[3])        /*������ͬһ��*/
	   {
		   int n,m;//nΪ�������нϴ��ֵ��mΪ�����н�С�ġ�
		   n=b[2]>b[0]?b[2]:b[0];
		   m=b[2]>b[0]?b[0]:b[2];
		   n=n-1;
		   while(n>m)
		   {
               //�����������β鿴�����ڴ��У�����֮���Ƿ��Ϊ�ո�
			   if(a[n][b[1]]==0)
				   n--;
			   else
				   break;
		   }
		   if(n==m)//�ڴ��У�����֮���Ϊ�ո�
		   {
			   Zero(a,b);
			   return;
		   }

	   }
	   if(1)//Ϊ����Ӿֲ�����i��������if(1),�ŵ㣺ʹ����i���ڵ�ʱ�価���̡ܶ�
	   {
		   int i;//����Ƿ���������ߵ������i=1��ʾ���ϣ�
		   i=Two(a,b);
		   if(i==1)
		     return;
	   }
	   if(1)//Ϊ����Ӿֲ�����f,w,e��������if(1),�ŵ㣺ʹ����f,e,w���ڵ�ʱ�価���̡ܶ�
	   {
		   //�����ߵ����
		   int f,w;
		   int e;
		   char c1[5],c2[5],c3[5]="1111";
		   //���(b[0],b[1]),(b[2],b[3])�ϡ��¡����ҵ����
		   Check(a,b[0],b[1],c1);
		   Check(a,b[2],b[3],c2);
		   if(strcmp(c1,c3)==0||strcmp(c2,c3)==0)//������ֻҪ��һ�����ܾ���Ϊ�գ�����Ͳ�����ͨ����������������
			   return;
		   for(e=0;e<=3;e++)//�Ƚ��������ܵ����
		   {
			   int r[4];
			   //b�����е�ֵ���ɱ仯�������r�������b�����е�ֵ
		       r[0]=b[0];
			   r[1]=b[1];
			   r[2]=b[2];
			   r[3]=b[3];
			   if(c1[e]==c2[e]&&c1[e]=='0')
			   {
				   switch(e)
				   {
				     case 0://�����Ϸ����пո�
						   //���μ��(b[0],b[1])�Ϸ��ĵ��Ƿ�Ϊ�ո�ֱ���߽磩����Ϊ�ո�����õ���(b[2],b[3])
						   //�Ƿ���ͨ����������ͨ
						   while(r[0]>0)
						   {
							   r[0]=r[0]-1;
							   if(a[r[0]][r[1]]!=0)//ֻҪ��Ϊ�ո����˵��������ͨ
								   break;
							   if(Two(a,r)==1)
							   {   
								   Zero(a,b);
								   return;
							   }
						   }
						   break;
					 case 1://�����·����пո�
						   //���μ��(b[0],b[1])�·��ĵ��Ƿ�Ϊ�ո�ֱ���߽磩����Ϊ�ո�����õ���(b[2],b[3])
						   //�Ƿ���ͨ����������ͨ
						   while(r[0]<8)
						   {
							   r[0]=r[0]+1;
							   if(a[r[0]][r[1]]!=0)//ֻҪ��Ϊ�ո����˵��������ͨ
								   break;
							   if(Two(a,r)==1)
							   {
								   Zero(a,b);
								   return;
							   }
						   }
				           break;
					 case 2:
						 //������߾��пո�
						   //���μ��(b[0],b[1])��ߵĵ��Ƿ�Ϊ�ո�ֱ���߽磩����Ϊ�ո�����õ���(b[2],b[3])
						   //�Ƿ���ͨ����������ͨ
						   while(r[1]>0)
						   {
							   r[1]=r[1]-1;
							   if(a[r[0]][r[1]]!=0)//ֻҪ��Ϊ�ո����˵��������ͨ
								   break;
							   if(Two(a,r)==1)
							   {
								   Zero(a,b);
								   return;
							   }

						   }
						   break;
					 case 3:
						 //�����ұ߾��пո�
						   //���μ��(b[0],b[1])�ұߵĵ��Ƿ�Ϊ�ո�ֱ���߽磩����Ϊ�ո�����õ���(b[2],b[3])
						   //�Ƿ���ͨ����������ͨ
						   while(r[1]<8)
						   {
							   r[1]+=1;
							   if(a[r[0]][r[1]]!=0)//ֻҪ��Ϊ�ո����˵��������ͨ
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

           f=b[2]-b[0];//f>0��ʾ(b[2],b[3])��(b[0],b[1])�·���f<0��ʾ(b[2],b[3])��(b[0],b[1])�Ϸ�

		   w=b[3]-b[1];//w>0��ʾ(b[2],b[3])��(b[0],b[1])�ҷ���w<0��ʾ(b[2],b[3])��(b[0],b[1])��


		   if(f>0&&w>0)                        /*(b[2],b[3])��(b[0],b[1])����*/
		   {
			   if(c2[0]=='0'&&c1[1]=='0') //(b[2],b[3])���Ϸ�Ϊ�ո�(b[0],b[1])���·�Ϊ�ո�
			   { 
	              if(UpDown(a,b,1))
					   return;
			   }
               if(c2[2]=='0'&&c1[3]=='0')//(b[2],b[3])�����Ϊ�ո�(b[0],b[1])���ұ�Ϊ�ո�
			   {
				   if(LeftRight(a,b,1))
					   return;
			   }
		   }
		   if(f<0&&w>0)                       /*(b[2],b[3])��(b[0],b[1])����*/
		   {
			   if(c2[1]=='0'&&c1[0]=='0')   //(b[2],b[3])���·�Ϊ�ո�(b[0],b[1])���Ϸ�Ϊ�ո�
			   {
				   if(UpDown(a,b,0))
					   return;
			   }
			   if(c2[2]=='0'&&c1[3]=='0')//(b[2],b[3])�����Ϊ�ո�(b[0],b[1])���ұ�Ϊ�ո�
			   {
				   if(LeftRight(a,b,1))
					   return;
			   }
		   }
		   if(f>0&&w<0)                     /*(b[2],b[3])��(b[0],b[1])����*/
		   {
			   if(c2[0]=='0'&&c1[1]=='0')//(b[2],b[3])���Ϸ�Ϊ�ո�(b[0],b[1])���·�Ϊ�ո�
			   {
				    if(UpDown(a,b,1))
					   return;
			   }
               if(c2[3]=='0'&&c1[2]=='0')//(b[2],b[3])���ұ�Ϊ�ո�(b[0],b[1])�����Ϊ�ո�
			   {
				   if(LeftRight(a,b,0))
					   return;
			   }
		   }
		   if(f<0&&w<0)                    /*(b[2],b[3])��(b[0],b[1])����*/
		   {
			   if(c2[1]=='0'&&c1[0]=='0') //(b[2],b[3])���·�Ϊ�ո�(b[0],b[1])���Ϸ�Ϊ�ո�
			   {
				   if(UpDown(a,b,0))
					   return;
			   }
               if(c2[3]=='0'&&c1[2]=='0')//(b[2],b[3])���ұ�Ϊ�ո�(b[0],b[1])�����Ϊ�ո�
			   {
				   if(LeftRight(a,b,0))
					   return;
			   }

		   }

		   
		}

	}
	   

}
void Zero(int a[8][8],int b[4])/*����Ϊ��*/
{
	a[b[0]][b[1]]=0;
	a[b[2]][b[3]]=0;
}
void Check(int a[8][8],int x,int y,char c[5])/*����ĳ���������ҵ����*/
{
	//1 ��ʾ��Ϊ�ո�0��ʾΪ�ո�
	//c[0],c[1],c[2],c[3]�ֱ��ʾĳ���������ҵ����
     if(a[x-1][y]==0)//(x,y)��һ��Ϊ��
		 c[0]='0';
	 else
		 c[0]='1';

     if(a[x+1][y]==0)//(x,y)��һ��Ϊ��
		 c[1]='0';
	 else
		 c[1]='1';

	 if(a[x][y-1]==0)//(x,y)��һ��Ϊ��
		 c[2]='0';
	 else
		 c[2]='1';

	 if(a[x][y+1]==0)//(x,y)��һ��Ϊ��
		 c[3]='0';
	 else
		 c[3]='1';
	 c[4]='\0';
}
int Two(int a[8][8],int b[4])    /*������*/
{
	int m,n;
	int c,d; //(c,d)Ϊ�ɶ����������

	n=b[2]-b[0];          /*�м��*/
	m=b[3]-b[1];         /*�м��*/
	d=b[2];
	c=b[3]-m;//b[1]
	while(c!=b[3])// ��֤�Ƿ����ˮƽͨ��(b[2],b[3])��(b[2],b[1])��
	{
		if(a[d][c]==0)
			c+=(m/abs(m));
		else
			break;
	}
	if(c==b[3])//����ˮƽͨ��
	{
		c=b[3]-m;
		while(d!=b[0])//��֤�Ƿ������ֱͨ��(b[2],b[1])��(b[0],b[1])��
		{
			if(a[d][c]==0)
				d-=(n/abs(n));
			else
				break;
		}
		if(d==b[0])//������ֱͨ����
		{
			Zero(a,b);
			return 1;
		}
		
	}
	c=b[3];
	d=b[2]-n;
	while(d!=b[2])//��֤�Ƿ������ֱͨ��(b[2],b[3])��(b[0],b[3])��
	{
		if(a[d][c]==0)
			d+=(n/abs(n));
		else
			break;
	}
	if(d==b[2])//������ֱͨ��
	{
		
		d=b[2]-n;
	    while(c!=b[1])// ��֤�Ƿ����ˮƽͨ��(b[0],b[3])��(b[0],b[1])��
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
	//g=1��ʾ(b[2],b[3])��(b[0],b[1])���·���g=0��ʾ(b[2],b[3])��(b[0],b[1])���Ϸ�
	if(g)
	{  
		 //���μ��(b[2],b[3])�ϱߵĵ��Ƿ�Ϊ�ո�ֱ��(b[0],b[3])�·����ڵ㣩����Ϊ�ո�����õ���(b[0],b[1])
		//�Ƿ���ͨ����������ͨ
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
		 //���μ��(b[2],b[3])�±ߵĵ��Ƿ�Ϊ�ո�ֱ��(b[0],b[3])�Ϸ����ڵ㣩����Ϊ�ո�����õ���(b[0],b[1])
		//�Ƿ���ͨ����������ͨ
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
    //g=1��ʾ(b[2],b[3])��(b[0],b[1])���ҷ���g=0��ʾ(b[2],b[3])��(b[0],b[1])����
	if(g)
	{
        //���μ��(b[2],b[3])��ߵĵ��Ƿ�Ϊ�ո�ֱ��(b[2],b[1]�ұ߽��ڵĵ㣩����Ϊ�ո�����õ���(b[0],b[1])
		//�Ƿ���ͨ����������ͨ
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
		//���μ��(b[2],b[3])�ұߵĵ��Ƿ�Ϊ�ո�ֱ��(b[2],b[1]��߽��ڵĵ㣩����Ϊ�ո�����õ���(b[0],b[1])
		//�Ƿ���ͨ����������ͨ
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
