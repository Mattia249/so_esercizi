#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define NUM_KIDS 20



int main() {
    int i, num, status, res, child_pid, sum = 0;
    
    for(i = 0; i < NUM_KIDS; i++) {
        child_pid = fork();
        if(child_pid == -1) {
            printf("Errore!\n");
            return 0;
        }
        if(!child_pid) {
            srand(getpid());
            num = (rand() % 6) + 1;
            printf("Creating child %d num=%d\n", getpid(), num);
            exit(num);
        }
    }

    while(waitpid(0, &status, 0) != -1) {
        if(WIFEXITED(status)) { 
            sum += WEXITSTATUS(status);
        }
        continue;
    }

    printf("Total sum %d\n", sum);


    printf("Parent ended\n");
    
}