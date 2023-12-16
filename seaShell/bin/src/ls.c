#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>
#include<unistd.h>

#define PATH_MAX 128

int main(){
    DIR *d;
    struct dirent *dir;
    int i = 0;
    char cwd[PATH_MAX];
    d = opendir(getcwd(cwd, PATH_MAX));
    printf("\n");
    if(d){
        while((dir = readdir(d)) != NULL){
            if(strcmp(dir->d_name, ".") == 0) continue;
            else if(strcmp(dir->d_name, "..") == 0) continue;
            else printf("%d\t%s\n", i, dir->d_name);
            i++;
        }
        closedir(d);
    }
    return 0;
}