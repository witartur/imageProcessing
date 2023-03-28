#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fileManager.h"

char getImageStandard(FILE *file)
{
    char standard[3] = {0};
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

static void getImageDimensions(FILE* file, int *width, int *height, int *colorDepth)
{
    int i;
    int w;
    int h;
    int c;

    do {
        i = fscanf(file, "%d ", &w);
        if (i == 0)
        {
            fseek(file, 1, SEEK_CUR);
        }
    } while (i != 1);

    do {
        i = fscanf(file, "%d\n", &h);
        if (i == 0)
        {
            fseek(file, 1, SEEK_CUR);
        }
    } while (i != 1);

    do {
        i = fscanf(file, "%d\n", &c);
        if (i == 0)
        {
            fseek(file, 1, SEEK_CUR);
        }
    } while (i != 1);
    
    *width = w;
    *height = h;
    *colorDepth = c;

}

void loadImage(imageFile *allImages, imageFile *selectImage, int *imageAmount )
{
    FILE* file;
    do
    {
        char fileName[50] = {""};
        char path[60] = {"Images\\"};
        printf("Type the name of the image to upload:\r\n");
        scanf("%s", fileName);
        strcat(path, fileName);
        strcat(path, ".pgm");

        strncpy(allImages->name, fileName, 50);

        file = fopen(path, "r");

        if (file == NULL)
        {
            printf("Cannot open %s.pgm file.\n", fileName);
            fclose(file);
            continue;
        }

        char stand[3] = {0};
        stand[0] = 'P';
        stand[1] = getImageStandard(file);
        stand[2] = '\0';

        if (stand[1] != '0')
        {
            strncpy(allImages->standard, stand, 2);
        }

        int width = 0;
        int height = 0;
        int colorDepth= 0;
        getImageDimensions(file, &width, &height, &colorDepth);

        allImages->height = height;
        allImages->width = width;
        allImages->colorDepth = colorDepth;

        int **array;
        allocate2D(&array, height, width);

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                while (fscanf(file, "%d\n", &array[i][j]) == 0)
                {
                    fseek(file, 1, SEEK_CUR);
                }
            }
        }

        allocate2D(&allImages->array, height, width);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                allImages->array[i][j] = array[i][j];
            }
        }

        
        release2D(&array, height, width);

    } while(file == NULL);

    *selectImage = *allImages;
    *imageAmount ++;
    fclose(file);
    
}

void allocate2D(int ***array, int height, int width)
{
    *array = malloc(height * sizeof(**array));

    if (*array == NULL)
    {
        printf("Allocation error");
		free(*array);
        return;
    }

    for (int i = 0; i < height; i++)
    {
        (*array)[i] = malloc(width * sizeof(int));

        if ((*array)[i] == NULL)
        {
            printf("Allocation error");
            
            for (int j = 0; i < height; j++)        //realeasing allocated memory in case of error
            {
                free((*array)[i]);
            }

            return;
        }
    }
}

void release2D(int ***array, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        free((*array)[i]);
    }
    free(*array);
}