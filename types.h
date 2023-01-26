#ifndef TYPES_H
#define TYPES_H

typedef struct
{
    char name[50];
    char standard[2];
    int height;
    int width;
    int maxWidth;
    int **array;        //2D array
} imageFile;


#endif      //TYPES_H