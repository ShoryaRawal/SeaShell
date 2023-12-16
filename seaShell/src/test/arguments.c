#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
int main(){
    char *a[MAX_SIZE];
    char string[50];
    printf("Enter the command: ");
    fgets(string, 50, stdin);
    size_t size = 10;
    char *token = strtok(string, " ");
    int i;
    for(i = 0; i < 32; i++){
        if(token != NULL){
            a[i] = malloc(size * sizeof(char));
            a[i] = token;
            token = strtok(NULL, " ");
        }else{
            break;
        }
    }
    for(int j = 0; j < i; j++){
        printf("%s\n", a[j]);
    }
}