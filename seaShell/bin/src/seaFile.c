#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void readFile(FILE *filepath);
int main(int argc, char* argv[]){
    FILE *filename;
    char buffer[10];
    char mode;
    if((filename = fopen("UwU.sea", "r"))){
        fgets(buffer, 10, filename);
        printf("%s", buffer);
        if(strcmp(buffer, "#sea v0.1") == 0){
            readFile(filename);
            printf("%s", buffer);
            strcpy(buffer, "");
        } else printf("ERROR NOT A SEA FILE.");
    } else printf("ERROR, FILE DOES NOT EXIST.");
    fclose(filename);
    return 0;
}
void readFile(FILE *filepath){
    char *text;
    long numBytes;
    fseek(filepath, 0L, SEEK_END);
    numBytes = ftell(filepath);
    fseek(filepath, 0L, SEEK_SET);
    text = (char*)calloc(numBytes, sizeof(char));
    if(text == NULL) 
        printf("THE FILE IS EMPTY.");
    else{
        fread(text, sizeof(char), numBytes, filepath);
        printf("%s", text);
    }
}

void readLine(FILE *file){
    int line = 0, count = 0;
    int totalBytes;
    char *buffer;
    
}
