#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "types.h"

void loadImage(imageFile *allImages, imageFile *selectImage, int *imageAmount );
void allocate2D(int ***array, int height, int width);
void release2D(int ***array, int height, int width);

#endif

