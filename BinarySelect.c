#include<stdio.h>
#define ARR_SIZE 10
//二分查找


void bubbleSort(int* arr,int len){
	int xch;
	for(int i=0; i < len-1; i++){
		xch = 0;
		for(int j=0; j < len -1 -i; j++){
			if(arr[j] > arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				xch = 1;
			}
		}
		if( !xch ){
			return;
		}
	}
}

int binSelect(int*arr,int left,int right,int key){
	while(left <= right){
		int mid = (right+left)/2;
		if(arr[mid] < key){
			left = mid + 1;
		}else if(arr[mid] > key){
			right = mid - 1;
		}else{
			return mid;
		}
	}
	return -1;
}

int main(){
	int arr[ARR_SIZE];
	//输入任意数组
	for(int i=0; i<ARR_SIZE; i++){
		scanf("%d",&arr[i]);
	}
	//Sort
	bubbleSort(arr,ARR_SIZE);
	for(int i=0; i<ARR_SIZE; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	//select
	int key;
	int left = 0;
	int right = sizeof(arr)/sizeof(arr[0]) - 1;
	printf("Please enter the number you want to select:>\n");
	scanf("%d",&key);
	int selI = binSelect(arr,left,right,key);
	if(selI == -1){
		printf("Can't find it!");
	}else{
		printf("Find it! Index of %d is %d",key,selI);
	}

}
