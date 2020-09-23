#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
	integral_image(image, WIDTH, HEIGHT, ii_image);
	int sum1 = integral_image_sum_value(ii_image, WIDTH, HEIGHT, 10, 20, 50, 100);
	int sum2 = image_sum_value(image, WIDTH, HEIGHT, 10, 20, 50, 100);
    if(sum1 != sum2) printf("error");
    printf("sum1 = %d, sum2 = %d", sum1, sum2);
	delete[] image;
	delete[] ii_image;
    return 0;
}