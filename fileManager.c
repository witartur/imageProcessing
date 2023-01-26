
#include "fileManager.h"


void loadImage(imageFile *allImages, imageFile selectimage )
{
    FILE* file;
    char fileName[50];
    char path[60] = {"Images\\"};



    printf("Type the the name of the image to upload:\r\n");
    scanf("%s", fileName);
    strcat(path, fileName);    
    strcat(path, ".pgm");  



}