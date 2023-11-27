#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void handle_signal(int signal) {
    if(signal == SIGALRM){
        printf("\nTempo scaduto, riprova un'altra volta.\n");
        exit(0);
    }
}

void init_handler() { 
    struct sigaction signal_action;
    sigset_t mask;
    
    memset (&signal_action, 0, sizeof(signal_action));
    sigemptyset(&mask);
    signal_action.sa_handler = &handle_signal;

    sigaction(SIGALRM, &signal_action, NULL);
}

int main(int argc, char* argv[]) {
    int max, seconds, num, target;
    
    max = atoi((*++argv));
    seconds = atoi((*++argv));
    
    srand(getpid());
    target = rand() % (max + 1);

    init_handler();
    alarm(seconds);
    while(1) { 
        printf("Inserisci un numero: ");
        scanf("%d", &num);
        if(num != target) { 
            printf("Riprova!\n");
        } else {
            printf("Numero indovinato :D\n");
            break;
        }
    }
}