#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 0;
    while(*argv != NULL) { 
        printf("%s\n", *(argv));
        argv++;
    }
}