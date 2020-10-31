#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int len) {
	
	for (int bound = 0; bound < len; bound++){
		for (int cur = len - 1; cur>bound; cur--){
			if (arr[cur - 1] > arr[cur]){
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
}

int main(){
	int arr[] = { 23, 4, 5, 21, 4, 56, 90, 67 };
	bubbleSort(arr, 8);
	system("pause");
	return 0;
}