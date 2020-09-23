#include<iostream>
#include<time.h>
#define INFINITE 100000
using namespace std;

int determineMax(int a, int b, int c=-INFINITE) {
	if (a > b) {
		if (a > c) return a;
		else return c;
	}
	else { 
		if (b > c) return b;
		else return c;
	}
}
int crossMaxSum(int* arr, int start, int mid, int end) {
	int tempSum = 0;
	int leftMaxSum = -INFINITE;
	int rightMaxSum = -INFINITE;

	for (int i = mid; i >= start; i--) {
		tempSum += arr[i];
		if (tempSum > leftMaxSum) leftMaxSum = tempSum;
	}

	tempSum = 0;
	for (int i = mid + 1; i <= end; i++) {
		tempSum += arr[i];
		if (tempSum > rightMaxSum) rightMaxSum = tempSum;
	}
	return (leftMaxSum + rightMaxSum);
}

int divide_conquer(int* arr,int start, int end) { 
	if (start == end) return arr[start];
	else {
		int mid = (start + end) / 2;
		int leftMaxSum = divide_conquer(arr, start, mid);
		int rightMaxSum = divide_conquer(arr, mid + 1, end);
		int CrossMaxSum = crossMaxSum(arr, start, mid, end);
		return determineMax(leftMaxSum, rightMaxSum, CrossMaxSum);
	}
}

int main()
{
	int temp = 0;
	srand(time(NULL));
    int arr[5000];
	for (int i = 0; i < 5000; i ++){
        temp = rand()%256;
        if(temp % 2 == 1) arr[i] = temp;
        else arr[i] = -temp;
    }

	int arrsize = sizeof(arr)/sizeof(arr[0]);
	int sum;
	clock_t begin, end;

	begin = clock();
	sum = divide_conquer(arr, 0, arrsize - 1);
	end = clock();
	cout << "divide&conquer\n" << "Max sum : " << sum << endl;
	cout << "Elapsed time : " << (end - begin) << "ms" << endl;

	return 0;
}