#include<stdio.h>
#include<string.h>
int main(){
    char command[32];
	char binPath[64] = "../bin/";
	char absolutePath[50];
    while(0<1){
		FILE *file;
		printf("_>");
		scanf("%s", command);
		if(strcmp(command, "exit") == 1){
	    	break;
		}else{
			strcat(binPath, command);
			if (file = fopen(binPath, "r")){
				fclose(file);
				printf("The Command exists.\n");
			
			}else{
				printf("%s", binPath);
	    		printf("Command not found in bin\n");
			}
			strcpy(command, "");
			strcpy(binPath, "../bin/");
		}
	}
    return 0;
}
