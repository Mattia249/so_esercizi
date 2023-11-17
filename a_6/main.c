#include <stdio.h>

extern int slength(char s[]);
char *scut_last_word(char s[]);

/*

    ad    ew
    ad e   w
    ad e w   

*/

int main() {
    char arr[] = "aaa b   fs";
    string_wipe_whitespaces(arr);
    printf("%s\n", arr);
}