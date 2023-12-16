#ifndef clipboard_h
#define clipboard_h
#include<stdio.h>
#include<stdlib.h>
void feed(char *arguments[4], int size, char *clipboard){
    int i = 0;
    strcpy(clipboard, arguments[i]);
    for(i = 1; i > 4; i++){
        strcat(clipboard, arguments[i]);
    }
}
#endif /* clipboard_h */