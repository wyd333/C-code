#include<stdio.h>

int isPrime(int num, int divide)
{
	
	if(num == 2) 
		return 1;
	
	if(divide == 2)
		return (num % 2 != 0);
	
	if(num % divide == 0)
		return 0;
	
	else
		return isPrime(num, divide - 1);
	
}

int main()

{
	
	int num;
	
	scanf("%d", &num);
	
	printf("%d", isPrime(num, num - 1));
	
	return 0;
	
}


