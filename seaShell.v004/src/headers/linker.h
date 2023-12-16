#ifndef linker_h
#define linker_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void readFile(char filename[32]){
    FILE *file = fopen(filename, "r");
    int count;
    char buffer_c, *buffer;
    while(1){
        buffer_c = getc(file);
        if(buffer_c == EOF) break;
        if(buffer_c == '\n') count = 0;
        else count++;
        printf("%d", count);
    }
}

#endif /* linker_h */