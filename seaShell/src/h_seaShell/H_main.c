#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//components
#include "comp/basic.h"

char *splitCommand[4];
char *buffer;
void args(char command[32]);
void seaindex();
int main(){
	char command[32];
	char *check;
	seaindex();
	while(1){
		printf("_> ");
		scanf("%[^\n]%*c", command);
		args(command);
		if(strcmp(command, "exit") == 0) break;
		else{
			check = strstr(buffer, command);
			if(check != NULL) printf("PLACEHOLDER.\n");
			else printf("COMMAND DOES NOT EXIST.\n");
		}
	}
	return 0;
}
void seaindex(){
	FILE *file;
	long bytes;
	if((file = fopen("comp/index.sea", "r"))){
		fseek(file, 0L, SEEK_END);
		bytes = ftell(file);
		fseek(file, 0L, SEEK_SET);
		buffer = (char*)calloc(bytes, sizeof(char));
		if(buffer == NULL) printf("INDEX EMPTY.");
		else{
			fread(buffer, sizeof(char), bytes, file);
		}
		fclose(file);
	}else printf("INDEX DOES NOT EXIST.");
}
void args(char command[32]){
	for(int i = 0; i < 4; i++)
		splitCommand[i] = NULL;
	char *token = strtok(command, " ");
	for(int j = 0; j < 4; j++){
		if(token != NULL){
			splitCommand[j] = malloc(8);
			splitCommand[j] = token;
			token = strtok(NULL, " ");
		} else break;
	}
}