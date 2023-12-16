#include "binutils.h"
#include<stdio.h>
int main(){
	const char* binLocation;
	binLocation = getBin();
	printf("%s", binLocation);
}
