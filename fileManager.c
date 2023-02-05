#include "fileManager.h"

#include <string.h>

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

static void getImageDimensions(FILE* file, int *width, int *height, int *maxWidth)
{
    int i;
    int w;
    int h;
    int m;

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
        i = fscanf(file, "%d\n", &maxWidth);
        if (i == 0)
        {
            fseek(file, 1, SEEK_CUR);
        }
    } while (i != 1);
    
    *width = w;
    *height = h;
    *maxWidth = m;

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

        strncpy(selectImage->name, fileName, 50);

        file = fopen(path, "r");

        if (file == NULL)
        {
            printf("Cannot open %s.pgm file.\n", fileName);
            fclose(file);
            continue;
        }

        char stand[3] = {""};
        // stand[0] = 'P';          // co tu sie odjebuje?
        stand[1] = getImageStandard(file);
        stand[0] = 'P';
        stand[2] = '\0';


        printf("%d", sizeof(stand)/sizeof(char));
        printf("%d", sizeof(selectImage->standard)/sizeof(char));
        printf("The string is: %s", stand);

        if (stand[1] != '0')
        {
            strncpy(selectImage->standard, stand, 2);
        }

        int width = 0;
        int height = 0;
        int maxWidth= 0;
        getImageDimensions(file, &width, &height, &maxWidth);

        selectImage->height = height;
        selectImage->width = width;
        selectImage->maxWidth = maxWidth;

        int **array;
        allocate2D(&array, height, width);

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                while (fscanf(file, "%d", &array[i][j]))
                {
                    fseek(file, 1, SEEK_CUR);
                }
            }
        }

        allocate2D(&selectImage->array, height, width);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                selectImage->array[i][j] = array[i][j];
            }
        }

        
        release2D(&array, height, width);

    } while(file == NULL);

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
        *(array+i) = malloc(width * sizeof(int));

        if (*(array+i) == NULL)
        {
            printf("Allocation error");
            
            for (int j = 0; i < height; j++)        //realeasing allocated memory in case of error
            {
                free(*(array+i));
            }

            return;
        }
    }
}

void release2D(int ***array, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        free(*(array+i));
    }
    free(*array);
}