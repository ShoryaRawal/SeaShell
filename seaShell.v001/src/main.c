#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define PATH_MAX 200
#define ARRAY_LEN 4
#define ARGUMENT_SIZE 64

char *arguementList[ARRAY_LEN];

void arguments(char path[64]);
//void engine(char path[64]);
int main(){
	char command[32], pwd[64];
	char binPath[64] = "../bin/";
	char cwd[PATH_MAX];
	FILE *file;
	while(0<1){
		getcwd(cwd, PATH_MAX);
		printf("%s _> ", cwd);
		scanf("%s", command);
		if(strcmp(command, "exit") == 0) break;
		else{
			strcat(binPath, command);
			arguments(binPath);
			/*if((file = fopen(binPath, "r"))){
				//engine(binPath);
				arguments(binPath);
			}else{
				printf("Command not found in bin\n");
			}*/
		}
		strcpy(command, "");
		strcpy(binPath, "../bin/");
	}
}

/*void engine(char path[64]){
	pid_t pid = fork();
	if(pid == 0){
		static char *argv[] = {NULL};
		execv(path, argv);
	}else{
		waitpid(pid, 0, 0);
	}
}*/

void argument(char path[64]){
	int i, j;
	char *token = strtok(path, " ");
	for(i = 0; i < ARRAY_LEN; i++){
		if(token != NULL){
			arguementList[i] = malloc(ARGUMENT_SIZE);
			arguementList[i] = token;
			token = strtok(NULL, " ");
		}else{
			break;
		}
	}
	for(j = 0; j < ARRAY_LEN; j++) printf("%s\n", arguementList[i]);
}