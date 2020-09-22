#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

#include <vector>

void integral_image(unsigned char* image, int width, int height, unsigned int* ii_image) 
{
    int j = 0, sum;
    for(int i=0; i<width*height; i++){
        sum = 0;
        j = i / width;
        for(int k=0; k<(i%width + 1); k++)
            sum += image[width*j+k];
        ii_image[i] = sum;
        if(i >= width)
            ii_image[i] += ii_image[i - width];
    }
}
int integral_image_sum_value(unsigned int* ii_image, int width, int height, int left, int top, int right, int bottom) 
{
    int topleft = width*(top-2) + (left-2);
    int topright = width*(top-2) + (right-1);
    int bottomleft = width*(bottom-1) + (left-2);
    int bottomright = width*(bottom-1) + (right -1);

    return ii_image[topleft] + ii_image[bottomright] - ii_image[topright] - ii_image[bottomleft];
}
int image_sum_value(unsigned char* image, int width, int height, int left, int top, int right, int bottom)
{
    int sum =0;
    for(int y = top-1; y < bottom; y++){
        for(int x = left-1 ; x < right; x++){
            sum += image[width*y+x];
        }
    }

    return sum;
}

#define WIDTH 640
#define HEIGHT 320
int main()
{
	unsigned char* image = new unsigned char[WIDTH*HEIGHT];
	unsigned int* ii_image = new unsigned int[WIDTH*HEIGHT];
	for(int i=0; i<WIDTH*HEIGHT; i++) image[i] = rand()%256;
	
    clock_t t1, t2, t3, t4, t5, t6;
    
    t1 = clock();
    integral_image(image, WIDTH, HEIGHT, ii_image);    
    t2 = clock();
    
    cout << "Elapsed time : " << (t2 - t1)/1000 << "s"<< endl;
    int n=1000; // 1 or 10 or 100 or 1000;
    int left, top;
    int sum1=0, sum2=0;
    double time1=0, time2=0;
   
    for(int i=0; i<n; i++) {
        left = rand()%(WIDTH-20);
        top = rand()%(HEIGHT-20);
        if(top < 2) top = 2;
        if(left < 2) left = 2;
        t3 = clock();
        sum1 += integral_image_sum_value(ii_image, WIDTH, HEIGHT, left, top, left+10, top+10);
        t4 = clock();
        t5 = clock();
        sum2 += image_sum_value(image, WIDTH, HEIGHT, left, top, left+10, top+10);
        t6 = clock();
        time1+=t4 -t3; time2+=t6 - t5;
    }
    printf("sum1: %d, time1: %.2lfms\n", sum1, time1);
    printf("sum2: %d, time2: %.2lfms\n", sum2, time2);
	
    return 0;
}