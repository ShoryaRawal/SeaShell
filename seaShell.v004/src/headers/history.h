#ifndef history_h
#define history_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_HIST 2048

char PATH[32] = "../../etc/histfile";
char *h_buffer;
int h_bufferSize;

void clrhist(){
    FILE *h_file = fopen(PATH, "w");
    fclose(h_file);
}

#endif /* history_h */