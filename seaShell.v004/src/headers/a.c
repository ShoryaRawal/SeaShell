#include<stdio.h>
#include "toolbelt.h"
int main(){
    FILE *file = fopen("history.h", "r");
    printf("%d", filesize(file));
    return 0;
}