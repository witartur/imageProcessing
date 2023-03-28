#include "userCommunication.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



void PrintMenu(int option, int imageAmount, int imageChoice)
{
    ScreenClean();
    printf("*****     IMAGE MODIFICATOR    *****\r\n\n");

    switch (option)
    {
    case 0:
        printf("Choose an option:\r\n1)   Load new image\r\n2)   Save image\n3)   Select image for modification\n4)   Mofify selected image\n");
        printf("   I choose:  ");
        break;
    case 1:
        printf("\r\nPicked load image\r\n");
        system("pause");
        ScreenClean();
        break;
    case 2:
        printf("\r\nPicked save image\r\n");
        system("pause");
        break;
    case 3:
        printf("\r\nPicked select image for modification\r\n");
        system("pause");
        ScreenClean();
        printf("*****     IMAGE MODIFICATOR    *****\r\n\n");
        printf("Choose image for modification from the list below:\r\n");
        printImageList(imageAmount, imageChoice);
        printf("   I choose:  ");
        break;
    case 4:
        printf("\r\nPicked mofify selected image\r\n");
        system("pause");
        if (imageAmount == 0)
            {
                printf("No loaded image. Load image first\r\n");
                system("pause");
                break;
            }

            ScreenClean();
            printf("*****     IMAGE MODIFICATOR    *****\r\n\n");
            printf("Choose modification:\r\n");
            printf("   I choose:  ");
        break;
    case 5:
        printf("\r\nPicked EXIT");
        sleep(1);
        break;
    default:
        printf("\r\nChoose an option by entering the number from menu\r\n");
        system("pause");
    }
   
    
}

void ScreenClean()
{
    system("cls");
    // fputs("\x1b[H\x1b[2J\x1b[3J", stdout); fflush(stdout); // alt for clearing terminal in VSC
}

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
    while (loadInt(&number) != 1)
    {
        printf("Incorrect input number. Number must be integer\r\n");
    }
}

void printImageList(int imageAmount, int imageChoice, imageFile *allImages)
{
    printf("\r\n#n___List of images:___\r\n");

    for (int i = 1; i <= imageAmount; i++)
    {

        printf("%d)  %s   ", i, *allImages[i].name);
        
        if (i == imageChoice)
        {
            printf("<-- selected image");
        }
        else
        {
            printf("\r\n");
        }

        printf("\r\n");
    }
}