#include <stdio.h>

int is_letter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
}

int is_number(char ch) {
    return ch >= '0' && ch <= '9';
}


int main() {
    char ch;
    int result;
    printf("Insert a random character: ");
    result = scanf("%c", &ch);
    if(result != 0) {
        if(is_letter(ch)){
            printf("Char is a letter\n");
        } else if(is_number(ch)){
            printf("Char is number\n");
        } else {
            printf("Char is not alphanumeric\n");
        }
    } else {
        printf("Something went wrong\n");
    }
}