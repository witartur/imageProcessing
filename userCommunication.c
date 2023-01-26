#include <stdio.h>

#include "userCommunication.h"

int loadInt(int *number)
{
    int tempVar;
    
    if (scanf("%d", &tempVar) != 1)
    {
        scanf("%*s");
        return 0;
    }
    else
    {
        *number = tempVar;
    }
}

void protectionInt(int number)
{
    while (loadInt(number) != 1)
    {
        printf("Incorrect input number. Number must be integer\r\n");
    }
}

void printImageList(int imageAmount, int imageChoice)
{
    printf("\r\n#n___List of images:___\r\n");

    // for (int i = 1; i <= imageAmount; i++)
    // {

    //     printf("%d)  %s   ", i, /*nazwa obrazu*/);
        
    //     if (i == imageChoice)
    //     {
    //         printf("<-- selected image");
    //     }

    //     printf("\r\n");
    // }
}