#include<iostream>
using namespace std;
#define ARR_SIZE 5

//int main(){
//	int arr[ARR_SIZE];
//	int i,j;	//i:��ѭ������; j:������������
//	for(i = 0; i < ARR_SIZE; i++){
//		cin >> arr[i];
//	}
//	
//	//ð������
//	int xch;
//	for(i = 0; i <= ARR_SIZE-1; i++){
//		xch = 0;
//		
//		for(j = 0; j <= ARR_SIZE-1-i; j++){
//			if(arr[j] > arr[j+1]){
//				int tmp;
//				tmp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = tmp;
//				xch = 1;
//			}
//		}
//		
//		if( !xch ){	//�޽���--�����Ѿ�����
//			break;
//		}
//	}
//	
//	for(i = 0; i < ARR_SIZE; i++){
//		cout << arr[i] << " ";
//	}
//	
//	return 0;
//}
//
//void bubbleSort(int* arr,int len){
//	int i,j;
//	int xch;
//	for(i = 0; i < len - 1; i++){
//		xch = 0;
//		for(j=0; j < len - 1 -i; j++){
//			if(arr[j] < arr[j+1]){
//				int tmp;
//				tmp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = tmp;
//				xch = 1;
//			}
//		}
//		
//		if( !xch ){
//			return;
//		}
//	}
//}

//int main(){
//	int arr[ARR_SIZE];
//	
//	for(int i = 0; i < ARR_SIZE; i++){
//		cin >> arr[i];
//	}
//	
//	bubbleSort(arr,ARR_SIZE);
//	
//	for(int i = 0; i < ARR_SIZE; i++){
//		cout << arr[i] << " ";
//	}
//	
//	
//	return 0;
//}

void selSort(int* arr,int len){
	int i,j;
	for(i = 0; i < len-1; i++){
		int selI = i;	//selI:ѡ�������±�������λ����
		for(j = i+1; j < len; j++){
			if(arr[selI] > arr[j]){
				selI = j;
			}
		}
		
		//�����i��Ԫ�ز���Ŀ�� ��λ
		if(i != selI){
			int tmp; 
			tmp = arr[i];
			arr[i] = arr[selI];
			arr[selI] = tmp;
		}
	}	
}

int main(){
	int arr[ARR_SIZE];
	
	for(int i = 0; i < ARR_SIZE; i++){
		cin >> arr[i];
	}
	
	selSort(arr,ARR_SIZE);
	
	for(int i = 0; i < ARR_SIZE; i++){
		cout << arr[i] << " ";
	}
	
	return 0;
}
