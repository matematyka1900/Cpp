#ifndef SORTING_FUNCTION_H
#define SORTING_FUNCTION_H

#include "BinaryHeapS.h"
#include <vector>

void countingSort(int *arr, int n, int m) {
	int* counterArray = new int[m];
	
	for (int i = 0; i < m; i++) {
		counterArray[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		++counterArray[arr[i]];
	}

	int arrCounter = 0;

	for (int i = 0; i < m; i++) {
		while (counterArray[i] > 0) {
			arr[arrCounter++] = i;

			--counterArray[i];
		}
	}

	delete[] counterArray;
}

//void CountingSort(int *arr,int n,int m){
//
//	int count[10] = { 0 };
//
//	for (int i = 0; i < m; i++) {
//		count[i] = 0;
//	}
//
//    for(int i=0;i<n;i++)
//		++count[(arr[i]/m)%10];
//    
//    for(int i=1;i<m;i++)
//    count[i]=count[i-1]+count[i];
//    
//   
//	unsigned int* out = new unsigned int[n];
//    for(int i=n-1;i>=0;i--){
//        out[count[(arr[i] / m) % 10]-1]=arr[i];
//        --count[(arr[i] / m) % 10];
//    }
//    
//    for(int i=0;i<n;i++)
//    arr[i]=out[i];
//}

//int ExtractMax(int* arr, int n) {
//	int max = 0;
//	for (int i = 0; i < n; i++) {
//		if (arr[i] > max) {
//			max = arr[i];
//		}
//	}
//	return max;
//}

void bucketSort(int* arr, int n, int m) {

}

template<typename T>
void bucketSort(T* arr, int n, double m) {
	/*vector<T> b[n];

	for (int i = 0; i < n; i++) {
		int bi = n * arr[i];
		b[bi].push_back(arr[i]);
	}

	for (int i = 0; i < n; i++)
		insertionSort(b[i]);


	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];*/
}


//void insertionSort(vector<int>arr) {
//	int j;
//	for (int i = 2; i <= arr.size(); i++) {
//		auto key = arr[i];
//		j = i - 1;
//		while ((j > 0) && (arr[j] > key))
//		{
//			arr[j + 1] = arr[j];
//			j--;
//		}
//		arr[j + 1] = key;
//	}
//}



#endif