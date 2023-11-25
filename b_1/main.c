#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

void child_callback(FILE *file) { 
    if(file != NULL) {
        fprintf(file, "Ciao mamma sono in tv!");
        fclose(file);
    } else {
        printf("Il file non è stato trovato!\n");
    }
    exit(0);
}

void parent_callback(FILE *file) {
    char buffer[BUFFER_SIZE];
    int bytes = 0;
    fseek(file, 0, SEEK_SET);
    if(file != NULL) {
        while(!feof(file)) {
            bytes = fread(buffer, sizeof(buffer), BUFFER_SIZE, file);
            printf("%s", buffer);
        }
        printf("\n");
    } else {
        printf("Il file non è stato trovato!\n");
    }
    fclose(file);
}


int main() {
    FILE *file = fopen("./file.txt", "w+");

    int pid = fork();
    if(pid == -1) return 0;
    if(!pid) {
        child_callback(file);
    } else {
        wait(NULL);
        parent_callback(file);
    }
}