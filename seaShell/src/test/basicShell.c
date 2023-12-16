#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *argumentList[];
char *splitSource[8];

void split(char path[32]);
int main(){
    char binpath[64] = "../bin/";
    char command[32];
    while(0<1){
	printf("_> ");
	scanf("%[^/n]%*c", command);
	if(strcmp(command, "exit") == 0) break;
	else{
	    strcat(binpath, command);
	    printf("%s", binpath);
	    split(binpath);
	    printf("%s", splitSource[0]);
	}
	strcpy(binpath, "../bin/");
	strcpy(command, "");
    }
}

void split(char path[32]){
    char *token = strtok(path, " ");
    for(int i = 0; i < 8; i++){
	if(token != NULL){
	    splitSource[i] = malloc(64);
	    splitSource[i] = token;
	    token = strtok(NULL, " ");
	} else break;
    }
    for(int j = 0; j < 8; j++){
	argumentList[j] = splitSource[j+1];
    }
}

