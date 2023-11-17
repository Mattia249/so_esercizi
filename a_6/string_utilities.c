#include <stdio.h>
#include "./string_utilities.h"


int slength(char s[]) {
    int i = 0;
    while(s[i] != '\0') { 
        i++;
    }
    return i;
}

char *scut_last_word(char s[]) {
    int i = 0;
    int last_white_space = 0;

    while(s[i] != '\0') {
        if(s[i] == ' ') { 
            last_white_space = i;
        }
        i++;
    }
    s[last_white_space] = '\0';
    return s;
}

int string_is_empty(char s[]) {
    return s[0] == '\0';
}

int string_is_palindrome(char s[]) {
    int len = slength(s);
    int res = 1, i;

    for(i = 0; i < len / 2; i++) {
        if(s[i] != s[len-i-1]) {
            res = 0;
            break;
        }
        
    }
    return res;
}

int string_compare(char s1[], char s2[]) {
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if(s1[i] > s2[i]) {
            return 1;
        } else if(s1[i] < s2[i]) {
            return -1;
        }
        i++;
    }

    if(s1[i] == '\0' && s2[i] == '\0') {
        return 0;
    }

    if(s1[i] == '\0') {
        return -1;
    } else if(s2[i] == '\0') {
        return 1;
    }

    
    return 0;
}

/* Thanks to StackOverflow */
void string_wipe_whitespaces(char s[]) {
    int i, x;
    for(i=x=0; s[i]; ++i)
        if(!isspace(s[i]) || (i > 0 && !isspace(s[i-1])))
    
    s[x++] = s[i];
    s[x] = '\0';
}


int string_how_many(char c, char s[]) {
    int count = 0;
    int i = 0;
    while(s[i] != '\0') { 
        count += (s[i] == c);
        i++;
    }
    return count;
}