#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define ITERATIONS 10
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
    int i;
    int num;

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
        
        while (read(file_descriptors[READ], &num, sizeof(int)) > 0) {
            printf("%d\n", num);
        }

        if(close(file_descriptors[READ]) == -1) {
            printf("Errore nella chiusura del file descriptor READ\n");
            return 0;
        }
    } else {
        close_file(file_descriptors[READ]);
        
        srand(getpid());
        for(i = 0; i < ITERATIONS; i++) { 
            num = (rand() % 100) + 1;
            write(file_descriptors[WRITE], &num, sizeof(int));
        }
        
        if(close(file_descriptors[WRITE]) == -1) {
            printf("Errore nella chiusura del file descriptor WRITE\n");
            return 0;
        }
    }
}