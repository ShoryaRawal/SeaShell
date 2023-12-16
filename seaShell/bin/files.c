#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *buffer;

void writeFile(FILE *file);
void readFile(FILE *file);
void newFile(FILE *file);
void flushFile(FILE *file);
int main(int argc, char* argv[]){
    if(argc != 2) printf("AYO WTF NO.\n");
    else{
        printf("%s", argv[0]);
    }
}
void readFile(FILE *file){
    long numBytes;
    fseek(file, 0L, SEEK_END);
    numBytes = ftell(file);
    fseek(file, 0L, SEEK_SET);
    buffer = (char*)calloc(numBytes, sizeof(char));
    if(buffer == NULL) printf("ERROR, THE FILE IS");
}