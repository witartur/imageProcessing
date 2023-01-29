
#include "fileManager.h"

static char getImageStandard(FILE *file)
{
    char standard[2] = {};
    fscanf(file, "%s\n", standard);

    if (standard[1] == '2' || standard[1] == '5')
    {
        return standard[1];
    }
    else
    {
        printf("Wrong image file standard.");
        return '0';
    }
}

void loadImage(imageFile *allImages, imageFile *selectImage, int imageAmount )
{
    while (1)
    {

        FILE* file;
        char fileName[50];
        char path[60] = {"Images\\"};
        int width = 0;
        int height = 0;

        printf("Type the the name of the image to upload:\r\n");
        scanf("%s", fileName);
        strcat(path, fileName);
        strcat(path, ".pgm");

        *selectImage->name = fileName;

        file = fopen(path, "r");

        if (file == NULL)
        {
            printf("Cannot open %s.pgm file.\n", fileName);
            continue;
        }

        char standard[2] = {'P', getImageStandard(file)};
        if (standard[1] != '0')
        {
            *selectImage->standard = standard;
        }






    }
}
