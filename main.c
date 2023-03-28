#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


#include "userCommunication.h"
#include "fileManager.h"
#include "imageMod.h"
#include "types.h"

int main()
{
    imageFile *allImages;         //for all read and made images
    imageFile selectImage;     //for selected image to mod
    int firstUserChoice = 0;
    int imageChoice = 0;
    int modChoice = 0;
    int imageAmount = 0;

    allImages = malloc(1*sizeof(imageFile));


    while (1)
    {
        firstUserChoice = 0;
        PrintMenu(firstUserChoice, imageAmount, imageChoice);
        scanf("%d", &firstUserChoice);

        switch (firstUserChoice)
        {
        case 1:
            PrintMenu(firstUserChoice, imageAmount, imageChoice);
            loadImage(allImages, &selectImage, &imageAmount);
            break;
        
        case 2:
            PrintMenu(firstUserChoice, imageAmount, imageChoice);
            break;
        
        case 3:
            PrintMenu(firstUserChoice, imageAmount, imageChoice);
            scanf("%d", &imageChoice);
            //imageActivation();

            break;
        
        case 4:
            PrintMenu(firstUserChoice, imageAmount, imageChoice);
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
            PrintMenu(firstUserChoice, imageAmount, imageChoice);
            
            // free()
            // free()
            exit;
        default:
            PrintMenu(firstUserChoice, imageAmount, imageChoice);
            break;
        }

    }

    return 0;
}