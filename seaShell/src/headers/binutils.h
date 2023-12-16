#ifndef binutils_h
#define binutils_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const char* getBin(){
    char* buffer;
    FILE *binFile;
    if((binFile = fopen("../../etc/binLocation.sea", "r"))){
        fgets(buffer, 64, binFile);
        printf("%s\n", buffer); 
        return buffer;
    }else return "BIN NOT FOUND.";
}

#endif /* binutil_h */