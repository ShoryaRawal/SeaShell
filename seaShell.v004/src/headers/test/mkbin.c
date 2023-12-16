#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char buffer[16];
    FILE *file;
    file = fopen("mkdir.txt", "w");
    printf("_>> ");
    scanf("%[^\n]%*c", buffer);
    fprintf(file, "%s", buffer);
}