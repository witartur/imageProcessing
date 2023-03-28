#ifndef USERCOMMUNICATION_H
#define USERCOMMUNICATION_H

#include "types.h"

void PrintMenu(int option, int imageAmount, int imageChoice);
void ScreenClean();
int loadInt(int *number);
void protectionInt(int number);
void printImageList(int imageAmount, int imageChoice);


#endif