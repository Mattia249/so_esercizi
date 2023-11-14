#include <stdio.h>

#define TOTAL_CHARS ('z' - 'a') + 1 + 1
#define MAX_ISTOGRAM_LENGTH 40

void init_array(unsigned long arr[], int len) {
    int i = 0;
    for(; i < len; i++){
        arr[i] = 0;
    }
}

int is_letter_or_whitespace(char ch) {
    return 
    (ch >= 'a' && ch <= 'z') ||
    (ch >= 'A' && ch <= 'Z') ||
    ch != ' ' || 
    ch != '\n' ||
    ch != '\t' || 
    ch != '\r'; 
}

char to_lowercase(char ch) {
    return ch >= 'A' && ch <= 'Z' ? ch + ('a'-'A') : ch;
}

int as_index(char ch) {
    if(!is_letter_or_whitespace(ch) ){
        return -1;
    } else {
        return ch != ' ' && ch != '\n' && ch != '\t' && ch != '\r' ? to_lowercase(ch) - 'a' : TOTAL_CHARS - 1;
    }
}

char as_char(int index) {
    return index != TOTAL_CHARS - 1 ? (char)index + 'a' : ' ';
}

unsigned long max_of(unsigned long arr[], int len) {
    int i = 0;
    unsigned long max = arr[0];
    
    for(;i < len; i++){
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int result, index, occurrence, units, i, j;
    unsigned long chars[TOTAL_CHARS];
    char ch;
    unsigned long max;
    float unit_per_char;

    init_array(chars, TOTAL_CHARS);
    
    while((ch = getchar()) != EOF){
        index = as_index(ch);
        if(index != -1){
            occurrence = chars[index];
            chars[index] = occurrence + 1;
        }
    }

    max = max_of(chars, TOTAL_CHARS - 1);

    unit_per_char = (float) MAX_ISTOGRAM_LENGTH / max;
    printf("unit per char: %f\n", unit_per_char);
    
    for(i = 0; i < TOTAL_CHARS - 1; i++) {
        occurrence = chars[i];
        units = (unit_per_char * occurrence);
        printf("'%c': ", as_char(i));
        for(j = 0; j < units; j++) {
            printf("*");
        }
        printf("\n");
    }
}