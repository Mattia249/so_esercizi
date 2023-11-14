#include <stdio.h>

char to_lowercase(char ch) {
    return ch >= 'A' && ch <= 'Z' ? ch + ('a'-'A') : ch;
}

int main() {
    char *str = "Hello WoRLd! Today’s temperature is 34C";
    while(*str != '\0') {
        putchar(to_lowercase(*str));
        str++;
    }
    printf("\n");
}