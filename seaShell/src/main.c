#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/wait.h>

#define PATH_MAX 200
#define ARRAY_LEN 16
#define ARGUMENT_SIZE 64

char *splitPath[ARRAY_LEN];
char *argumentList[1];
char binPath[128];
char binLocation[64] = "/bin/";
char program[32];

void engine(char path[64]);
void arguments(char path[64]);
void mkbin(char path[64]);
void ls(char path[64]);
void run(char path[64]);
int main(){
	char command[32];
	char cwd[PATH_MAX];
	char buffer[32];
	char execCommand[64];
	FILE *file, *binFile;
	if((binFile = fopen("../etc/binLocation.sea", "r"))){
		fgets(buffer, 50, binFile);
		if(strcmp(buffer, "\0")) strcpy(binLocation, buffer);
		else printf("bin not set, set a bin with mkbin.\n");
		fclose(binFile);
	} else printf("bin not set, set a bin with mkbin.\n");
	printf("Bin set: %s\n", binLocation);
	while(0<1){
		strcpy(binPath, binLocation);
		getcwd(cwd, PATH_MAX);
		printf("\x1b[36m");
		printf("%s _> ", cwd);
		printf("\x1b[0m");
		scanf("%[^\n]%*c", command);
		arguments(command);
		strcat(binPath, program);
		if(strcmp(command, "exit") == 0) break;
		else if(strcmp(command, "clear") == 0) printf("\e[1;1H\e[2J");
		else if(strcmp(command, "mkbin") == 0) mkbin(cwd);
		else if(strcmp(program, "cd") == 0) chdir(argumentList[0]);
		else if(strcmp(program, "ls") == 0){
			if(argumentList[0] == NULL) ls(cwd);
			else ls(argumentList[0]);
		}else{
			strcat(binLocation, program);	
			printf("%s\n", program);
			if((file = fopen(binPath, "r"))){
				engine(binPath);
			}else{
				printf("%s: Not found.\n", program);
			}
		}
		strcpy(binLocation, "");
		strcpy(binPath, binLocation);
		strcpy(command, "");
	}
}
void engine(char path[64]){
	pid_t pid = fork();
	if(pid == 0){
		execv(path, argumentList);
	} else waitpid(pid, 0, 0);
}
void arguments(char path[64]){
	for(int h = 0; h < ARRAY_LEN; h++){ 
		splitPath[h] = NULL;
		argumentList[h] = NULL;
	}
	char *token = strtok(path, " ");
	for(int i = 0; i < ARRAY_LEN; i++){
		if(token != NULL){
			splitPath[i] = malloc(ARGUMENT_SIZE);
			splitPath[i] = token;
			token = strtok(NULL, " ");
		} else break;
	}
	strcpy(program, splitPath[0]);
	for(int j = 0; j < 4; j++) argumentList[j] = splitPath[j+1];
}

void mkbin(char path[64]){
	FILE *tmp = fopen("../etc/binLocation.sea", "w");
	fputs(path, tmp);
	fclose(tmp);
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