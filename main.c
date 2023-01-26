#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "userCommunication.c"
#include "fileManager.c"
#include "imageMod.c"
#include "types.h"

int main()
{
    imageFile *allImages;         //for all read and made images
    imageFile selectImage;     //for selected image to mod
    int firstUserChoice = 0;
    int imageChoice = 0;
    int modChoice = 0;
    int modChoice = 0;
    int imageAmount = 0;

    allImages = (imageFile*)malloc(1*sizeof(imageFile));


    do
    {
        // system("cls");
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout); fflush(stdout); // alt for clearing terminal in VSC
        printf("*****     IMAGE MODIFICATOR    *****\r\n\n");
        printf("Choose an option:\r\n1)   Load new image\r\n2)   Save image\n3)   Select image for modification\n4)   Mofify selected image\n");
        printf("   I choose:  ");
        printImageList(imageAmount, imageChoice);
        scanf("%d", &firstUserChoice);

        switch (firstUserChoice)
        {
        case 1:
            printf("\r\nPicked load image");
            sleep(0.5); 
            loadImage();
            if (loadImage == 1)
            {
                imageAmount ++;
            }
            
            break;
        
        case 2:
            printf("\r\nPicked save image");
            sleep(0.5); 
            break;
        
        case 3:
            printf("\r\nPicked select image for modification");
            sleep(0.5); 
            // system("cls");
            fputs("\x1b[H\x1b[2J\x1b[3J", stdout); fflush(stdout); // alt for clearing terminal in VSC
            printf("*****     IMAGE MODIFICATOR    *****\r\n\n");
            printf("Choose image for modification:\r\n");
            printImageList(imageAmount, imageChoice);
            printf("   I choose:  ");
            scanf("%d", &imageChoice);
            //imageActivation();

            break;
        
        case 4:
            printf("\r\nPicked mofify selected image");
            sleep(0.5);
            
            if (imageAmount == 0)
            {
                printf("No loaded image. Load image first\r\n");
                sleep(1);
                break;
            }

             // system("cls");
            fputs("\x1b[H\x1b[2J\x1b[3J", stdout); fflush(stdout); // alt for clearing terminal in VSC
            printf("*****     IMAGE MODIFICATOR    *****\r\n\n");
            printf("Choose modification:\r\n");
            printf("   I choose:  ");
            scanf("%d", &modChoice);
            
            // do
            // {
            //     /* code */
            // } while (/* condition */);
            
            // {
            //     /* code */
            // }
            
            
            break;

        case 5:
            printf("\r\nPicked EXIT");
            sleep(0.5); 
            break;
        
        default:
            printf("\r\nChoose an option by entering the number from menu\r\n");
            sleep(2);
            break;
        }

    } while (firstUserChoice != 5);

    // free()
    // free()

    return 0;
}