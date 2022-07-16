#include<stdio.h>

int myMax(int x,int y) {
	return x>y? x:y;
}

int main(){
	printf("%d ",myMax(10,20));
	return 0;
}

