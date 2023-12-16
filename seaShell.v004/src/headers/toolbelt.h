#ifndef toolbelt_h
#define toolbelt_h
#include<stdlib.h>
void strip(char *str){
    int i, j;
    int len = sizeof(str);
    for(i = 0; i < len; i++){
        if(str[i] == ' '){
            for(j = i; j < len; j++){
                str[j] = str[j+1];
            }
            len--;
        }
    }
}
int filesize(FILE *file){
   int size;
   fseek(file, 0l, SEEK_END);
   return ftell(file);
   rewind(file);
}
#endif /* toolbelt_h */
