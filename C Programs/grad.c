/*
* Project: Draw Gradient to BMP
* Author: Alexander Aigner
* Creation Date: -
*
* Description: Gradient sample.
*
* Creates a Color gradient, saves the result to a BMP file and opens
* the file in the default image viewer.
*
*/
 
 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
// RGB Parameter Struct
typedef struct {
double r;
double g;
double b;
} COLOR_RGB_PARAMS;
 
// RGB Holder
typedef struct {
unsigned char r;
unsigned char g;
unsigned char b;
} COLOR_RGB;
 
 
// Fills an array with RGB values for a gradient
int make_color_gradient(COLOR_RGB buffer[], COLOR_RGB_PARAMS *frequency, COLOR_RGB_PARAMS *phase, int center, int width, int len) {
int i = 0;
 
if (!(center && width && len))
return 0;
 
for (i = 0; i < len; ++i) {
 
buffer[i].r = (unsigned char)(sin(frequency->r*i + phase->r) * width + center);
buffer[i].g = (unsigned char)(sin(frequency->g*i + phase->g) * width + center);
buffer[i].b = (unsigned char)(sin(frequency->b*i + phase->b) * width + center);
}
 
return 1;
}
 
// Safes Gradient to a bmp file
int gradient_to_file(unsigned char * filename, COLOR_RGB buffer[], int len, int width, int height) {
 
FILE *f = NULL; // File handle
unsigned char *img = NULL; // Image data holder
int datasize = sizeof(COLOR_RGB)*width*height; // Data size
int filesize = 54 + datasize; // Image file size
int color = 0; // Color Index
double blocksize = (double)len/width;
// Image data buffer
img = (unsigned char *)malloc(datasize);
memset(img, 0, datasize);
// Current Pixel
COLOR_RGB *cpix;
// Return variable
int rtVar = 0;
 
// Writting Data
int x, y;
for (y = 0; y < height; ++y) {
 
for (x = 0; x < width; ++x) {
 
color = (int)(double)x*blocksize;
cpix = img + (y*width + x)*sizeof(COLOR_RGB);
cpix->r = buffer[color].r;
cpix->b = buffer[color].b;
cpix->g = buffer[color].g;
}
}
 
// Creating Header
unsigned char bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
unsigned char bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
unsigned char bmppad[3] = {0, 0, 0};
 
bmpfileheader[2] = (unsigned char)(filesize);
bmpfileheader[3] = (unsigned char)(filesize >> 8);
bmpfileheader[4] = (unsigned char)(filesize >> 16);
bmpfileheader[5] = (unsigned char)(filesize >> 24);
bmpinfoheader[4] = (unsigned char)(width);
bmpinfoheader[5] = (unsigned char)(width >> 8);
bmpinfoheader[6] = (unsigned char)(width >> 16);
bmpinfoheader[7] = (unsigned char)(width >> 24);
bmpinfoheader[8] = (unsigned char)(height);
bmpinfoheader[9] = (unsigned char)(height>> 8);
bmpinfoheader[10] = (unsigned char)(height >> 16);
bmpinfoheader[11] = (unsigned char)(height >> 24);
 
// Writing Image
if (!fopen_s(&f, filename, "wb")) {
 
// Header ....
fwrite(bmpfileheader, 1, 14, f);
fwrite(bmpinfoheader, 1, 40, f);
 
// ... and data with padding
for (int i = 0; i < height; i++) {
 
fwrite(img + (width*(height - i - 1) * 3), 3, width, f);
fwrite(bmppad, 1, (4 - (width * 3) % 4) % 4, f);
}
rtVar = 1; // Success!
fclose(f);
}
 
// frees image data buffer
free(img);
 
return rtVar;
}
 
int main(int argc, char *argv[]) {
// define image file name:
unsigned char *filename = "test.bmp";
 
// image size:
int img_width = 500;
int img_height = 50;
 
 
// Gradient - Parameters:
COLOR_RGB_PARAMS freq, phase;
int center, width, len;
 
// Play arround to create different color gradients
center = 128;
width = 127;
len = 50;
 
freq.r = 0.1;
freq.g = 0.1;
freq.b = 0.1;
 
phase.r = 0;
phase.g = 2;
phase.b = 4;
 
// Creating gradient buffer
COLOR_RGB *result = (COLOR_RGB *)calloc(len, sizeof(COLOR_RGB));
 
// Calculating data
if (make_color_gradient(result, &freq, &phase, center, width, len)) {
 
// Saving gradient to file
if (gradient_to_file(filename, result, len, img_width, img_height)) {
 
printf("Success, open BMP in default viewer ...\n");
// Opens file in default viewer
system(filename);
}
 
}
 
return 0;
}