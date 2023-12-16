#include<stdio.h>
#include<stdlib.h>
void OwO(char buffer_ar[32], int index);
int main(){
    FILE *file = fopen("config.sea", "r");
    int lineLen, lineSize = 0, index = 0;
    char buffer_c, buffer_ar[32];
    fseek(file, 0l, SEEK_END);
    int fileSize = ftell(file);
    rewind(file);
    for(lineLen = 0 ; lineLen <= fileSize; lineLen++){
        buffer_c = getc(file);
        index = 0;
        while(1){
            if(buffer_c == '\n') break;
            index++;
            buffer_ar[index] = buffer_c; /*Mf is dying here*/
        }
        OwO(buffer_ar, index);
    }
    fclose(file);
}
void OwO(char buffer_ar[32], int index){
    printf("%d\n", index);
    char *buffer;
    int i;
    buffer = (char *) malloc(index);
    for(i = 0; i <= index; i++){
        buffer[i] = buffer_ar[i];
    }
    printf("%s", buffer);
    free(buffer);
}
