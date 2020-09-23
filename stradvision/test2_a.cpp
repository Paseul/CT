#include <time.h>
#include<iostream>
#include <stdlib.h>

using namespace std;
#define INFINITE 100000

int main(int argc, char** argv)
{
    int initial_index = 0;
    int final_index;
    
    int thisSum = 0;
    int temp = 0;
	int maxSum = -INFINITE;
    clock_t begin, end;

    srand(time(NULL));
    int A[5000];
    for (int i = 0; i < 5000; i ++){
        temp = rand()%256;
        if(temp % 2 == 1) A[i] = temp;
        else A[i] = -temp;
    }

    int arrsize = (sizeof(A) / sizeof(A[0]));
    temp = 0;

	begin = clock();
    
	for (int i = 0; i < arrsize; i++) {
		if (maxSum < thisSum + A[i]) {
			maxSum = thisSum + A[i];
            initial_index = temp;
            final_index = i;
		}
		thisSum += A[i];
		if (thisSum < 0){
            thisSum = 0;
            temp = i+1;
        } 
	}
    end = clock();

    cout << "incremental\n" << "Max sum : " << maxSum << "\nfrom:" << initial_index+1 << "\tto:" << final_index+1 << endl;
	cout << "Elapsed time : " << (end - begin) << "ms" << endl;
 
    return 0;
}
