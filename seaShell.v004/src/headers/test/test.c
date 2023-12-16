#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void myBS();
int main(){
	/*FILE *file;
	file = fopen("config.sea", "r");
	if(file == NULL) exit(1);
	int maxLineLen = 128;
	char *lineBuffer = (char *)malloc(sizeof(char) * maxLineLen);
	if(lineBuffer == NULL) exit(1);
	char ch = getc(file);
	int count = 0;
	while(ch != EOF){
		if(count == maxLineLen){
			maxLineLen += 128;
			lineBuffer = realloc(lineBuffer, maxLineLen);
			if(lineBuffer == NULL) exit(1);
		}
		lineBuffer[count] = ch;
		printf("%d\t", count);
		count++;

		ch = getc(file);
	}
	lineBuffer[count] = '\0';
	char line[count + 1];
	strncpy(line, lineBuffer, (count + 1));
	free(lineBuffer);
	const char *constLine = line;
	printf("%s", constLine);*/
	myBS();
}
void myBS(){
	int line = 0, count = 0;
	int totalbytes;
	char check;
	char *buffer;
	FILE *file;
	file = fopen("config.sea", "r");
	if(file == NULL) exit(1);
	fseek(file, 0L, SEEK_END);
	totalbytes = ftell(file);
	rewind(file);
	for(int line; line < totalbytes; line++){
		printf("%d", count);
		if(line != 0) count ++;
		check = getc(file);
		if(check == EOF) break;
		while(check != '\n'){
			count++;
			check = getc(file);
		}
		buffer = (char *) malloc(count);
		fread(buffer, 1, count, file);
		printf("%s", buffer);
		free(buffer);
	}
	/*for(int line; line < totalbytes; line++){
		if(count != 0) count ++;
		check = getc(file);
		if(check == EOF) break;
		while(check != '\n'){
			count ++;
			check = getc(file);
		}
		count ++;
		buffer = malloc(count);
		fgets(buffer, count, file);
		printf("%s\n", buffer);
		free(buffer);
	}*/

	/*while(line != totalbytes){
		if(line != 0) count++;
		check = getc(file);
		while((check != '\n') && (check != EOF)){
			count ++;
			check = getc(file);
		}
		count ++;
		buffer = malloc(count);
		fgets(buffer, count, file);
		printf("%s\n", buffer);
		free(buffer);
	}*/
}

