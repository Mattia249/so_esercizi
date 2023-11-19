#include <stdio.h>

#define MAX_LENGTH 20

int is_whitespace(char ch) {
    return 
    ch == ' ' || 
    ch == '\n' ||
    ch == '\t' || 
    ch == '\r'; 
}

int main() {
    char* str;
    int i = 0;
    int count = 0;

    /*
        Conta tutti i caratteri != ' ' azzera quando si presenta uno ' ' o '\0'
    */

    while(fgets(str, MAX_LENGTH, stdin) != NULL){

        while(*str != '\0') {
            if(!is_whitespace(*str)) { 
                count++;
            } else {
                printf("conto: %d\n", count);
                count = 0;
            }
            str++;
        }

        count = 0;

    }

   

}