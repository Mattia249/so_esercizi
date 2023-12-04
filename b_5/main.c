#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

void close_file(int file_descriptor) {
    if(close(file_descriptor) == -1) {
        printf("Errore nella chiusura del file descriptor %d\n", file_descriptor);
    }
}

int main() { 
    int file_descriptors[2];
    pid_t pid;
    char string[24] = "ciao mamma sono in tv!";
    char buffer[64];

    if(pipe(file_descriptors) == -1) { 
        printf("Pipe non creata\n");
        return 0;
    }

    pid = fork();
    if(pid == -1) {
        printf("Errore\n");
        /* Ti copio */
        if(close(file_descriptors[READ]) + close(file_descriptors[WRITE] < 0)) {
            printf("Errore nella chisura\n");
        }
        return 0;
    }
    
    if(!pid) {
        close_file(file_descriptors[WRITE]);
        
        printf("Reading\n");
        read(file_descriptors[READ], buffer, sizeof(buffer));
        printf("%s\n", buffer);
        
        if(close(file_descriptors[READ]) == -1) {
            printf("Errore nella chiusura del file descriptor READ\n");
            return 0;
        }
    } else {
        close_file(file_descriptors[READ]);

        write(file_descriptors[WRITE], string, sizeof(string));
        
        if(close(file_descriptors[WRITE]) == -1) {
            printf("Errore nella chiusura del file descriptor WRITE\n");
            return 0;
        }
    }
}