#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    if(pid == -1) { 
        printf("Errore!");
        return 0;
    }
    if(!pid) { 
        execlp("./saluta_persone", "Mario", "Olivia", NULL);
        exit(0);
    }

    while(wait(NULL) != -1) {
        continue;
    }

}