#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

int close_file(int file_descriptor) {
    if(close(file_descriptor) == -1) {
        printf("Errore nella chiusura del file descriptor %d\n", file_descriptor);
        return 1;
    }
    return 0;
}

void print_errors(int errors) { 
    printf("Total errors %d\n", errors);
}


int main() { 
    int i, status;
    int pid_test;
    pid_t pid;
    int pipe_fd[2];
    char string[24] = "Ciao mamma sono in tv";
    char buffer[64];
    int errors = 0;

    if(pipe(pipe_fd) == -1) { 
        printf("Pipe non creata\n");
        return 0;
    }

    for(i = 0; i < 2; i++) { 
        pid = fork();
        switch(pid) { 
            case -1:
                printf("Errore nel fork!\n");
                if(close(pipe_fd[READ]) + close(pipe_fd[WRITE] < 0)) {
                    printf("Errore nella chisura dei file\n");
                }
                break;
            case 0:
                if(!i) {
                    errors += close_file(pipe_fd[WRITE]);
                    while (read(pipe_fd[READ], buffer, sizeof(buffer)) > 0) {
                       printf("%s\n", buffer);
                    }
                    
                    errors += close_file(pipe_fd[READ]);
                } else {
                    errors += pipe_fd[READ];
                    
                    write(pipe_fd[WRITE], string, sizeof(string));
                    errors += close_file(pipe_fd[WRITE]);
                }
                exit(0);
                break;
            default:
                break;
        }
    }

    errors += close_file(pipe_fd[WRITE]);
    errors += close_file(pipe_fd[READ]);

    while((pid_test = waitpid(0, NULL, 0)) != -1) {
        printf("Process: %d exited\n", pid_test);
        continue;
    }


    printf("Total errors %d\n", errors);
    
}