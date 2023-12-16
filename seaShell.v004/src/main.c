#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include "headers/toolbelt.h"
//#include<sys/types.h>
//#include<sys/wait.h>

#define PATH_MAX 200
#define ARRAY_LEN 4
#define ARGUMENT_SIZE 64
#define CLIPBOARD_SIZE 64

char *splitPath[ARRAY_LEN];
char *argumentList[1];
char *clipboard;
char binPath[64] = "/bin/";
char program[64];

void engine(char path[64]);
void arguments(char path[64]);
void ls(char path[64]);
void clip(char mode);
int main(){
    char command[32];
    char cwd[PATH_MAX];
    FILE *file, *h_file;
    h_file = fopen("../etc/histfile", "a+");
    if(h_file == NULL){
        fclose(h_file);
        h_file = fopen("../etc/histfile", "w+");
    }
    while(1){
        getcwd(cwd, PATH_MAX);
        printf("\x1b[36m");
        printf("%s $ ", cwd);
        printf("\x1b[0m");
        scanf("%[^\n]%*c", command);
        arguments(command);
        strcat(binPath, program);
        if(strcmp(command, "exit") == 0) break;
        else if(strcmp(command, "clear") == 0) printf("\e[1;H\e[2J");
        else if(strcmp(program, "clip") == 0) clip('f');
        else if(strcmp(program, "cd") == 0) chdir(argumentList[0]);
        else if(strcmp(program, "ls") == 0){
            if(argumentList[0] == NULL) ls(cwd);
            else ls(argumentList[0]);
        }else{
            if((file = fopen(binPath, "r"))) engine(program);
            else printf("%s: Not Found.\n", program);
        }
        strcat(command, "\n");
        fputs(command, h_file);
        strcpy(binPath, "/bin/");
        strcpy(command, "");
    }
    fclose(h_file);
}
void engine(char path[64]){
    pid_t pid = fork();
    if(pid == 0) execv(binPath, argumentList);
    else waitpid(pid, 0, 0);
}
void arguments(char path[64]){
    for(int h = 0; h < ARRAY_LEN; h++){
        splitPath[h] = NULL;
        argumentList[h] = NULL;
    }
    char *token = strtok(path, " ");
    for(int i = 0; i < ARRAY_LEN; i++){
        if(token == NULL) break;
        splitPath[i] = malloc(ARGUMENT_SIZE);
        splitPath[i] = token;
        token = strtok(NULL, " ");
    }
    strcpy(program, splitPath[0]);
    for(int j = 0; j < ARRAY_LEN; j++) argumentList[j] = splitPath[j+1];
}
void ls(char path[64]){
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if(d){
        while((dir = readdir(d)) != NULL){
            if(strcmp(dir->d_name, ".") == 0) continue;
            else if(strcmp(dir->d_name, "..") == 0) continue;
            else printf("%s\n", dir->d_name);
        }
    }
}
void clip(char mode){
    int temp_size = 0;
    if(mode == 'f'){
        for(int i = 0; i < ARRAY_LEN; i++)
            if(argumentList[i] != NULL) temp_size += (int) sizeof(argumentList[i]);
        printf("%d", temp_size);
        clipboard = (char *)malloc(temp_size);
        printf("clipboard: %lu\n", sizeof(clipboard));
        for(int j = 0; j < ARRAY_LEN; j++)
            (j == 0) ? strcpy(clipboard, argumentList[j]) : strcat(clipboard, argumentList[j]);
    }else{
        strcpy(clipboard, " ");
        free(clipboard);
    }
    /*Try:
    FILE *file = fopen("config.sea", "r");
    int temp = 0, lineSize = 0;
    char buffer_c, *buffer;
    while(1){
        buffer_c = getc(file);
        if(buffer_c == EOF) break;
        else{
            if(buffer_c == '\n'){
                temp = lineSize;
                lineSize = ftell(file);
                lineSize -= temp;
                printf("%d\n", lineSize);
            }
        }
    }*/
}