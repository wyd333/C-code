#include<iostream>
using namespace std;

void fun(int n, int* zeroCount, int* maxDigit){
	*zeroCount = 0;
	*maxDigit = -1;
	while(n!=0){
		int d = n%10;
		if(d == 0){
			(*zeroCount)++;
		}
		if(d > *maxDigit){
			*maxDigit = d;
		}
		n = n/10;
	}
}

int main(){
	int n;
	cout << "Please input an integer:";
	cin >> n;
	int zc, md;
	fun(n, &zc, &md);
	cout << n << " has " << zc << " zero(s), the max digit is " << md << endl;
}
