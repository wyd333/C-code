#include<stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef int ElemType;
typedef struct
{ 
ElemType data[MaxSize];
int length;
}SqList; 

bool InitList(SqList *L); 
void InputListData(SqList *L, ElemType arr[], int n); 
bool ListEmpty(SqList *L);
void DisplayListData(SqList *L);
int ListLength(SqList *L);


void CreatList_Sq(SqList*L,ElemType arr[],int n)
{int i;
L=(SqList*)malloc(sizeof(SqList));
for(i=0;i<n;i++)
L->data[i]=arr[i];
L->length=n;
 } 
 
 int main()
 { 
 	SqList *L;
 	int arr[5]={0,1,2,3,4};
 	
 	if (!InitList(L))
    {
        printf("Create SqList fail, bye\n");
        return 1;
    }
    
    

    if (ListEmpty(L))
        printf("Now SqList is Empty\n");
    else
        printf("Now SqList is not Empty\n");
 	
 	
 	
 	
 	

 	InputListData(L,arr,5);
 	DisplayListData(L);
 	
 	
 	
printf("Now SqList length is %d\n", ListLength(L));
 }
 bool InitList(SqList *L)
{
    L=(SqList*)malloc(sizeof(SqList));
    if (L==NULL)
        return false;
    else
    {
        L->length = 0;
        return true;
    }
}
 void InputListData(SqList *L, ElemType arr[], int n){
  int i;
   for(i=0; i<n; i++)
   {
       L->data[L->length]=arr[i];
       L->length++;
   }
}
 
void DisplayListData(SqList *L){
	int i;
    for(i=0; i<L->length; i++)
        printf("data[%d]=%c\n", i+1, L->data[i]);	

}
bool ListEmpty(SqList *L)
{
    return (L->length==0);
}

int ListLength(SqList *L)
{
	return (L->length);

}

 
