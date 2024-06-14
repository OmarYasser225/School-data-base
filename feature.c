//
// Created by omarn on 11/2/2023.
//
#include "feature.h"

void setColor(int ForgC)
{

    //We will need this handle to get the current background attribute
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    //we use csbi for the wAttributes word.
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        //Mask out all but the background attribute
        //, and add in the foreground color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
