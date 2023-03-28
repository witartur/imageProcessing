#ifndef TYPES_H
#define TYPES_H

typedef struct
{
    char name[50];
    char standard[3];
    int height;
    int width;
    int colorDepth;
    int **array;
} imageFile;


#endif      //TYPES_H