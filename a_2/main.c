#include <stdio.h>

int main() {
    unsigned int num;
    unsigned int sum = 0;
    int count = 0;

    int result;

    while((result = scanf("%u", &num)) != EOF) {
        if(num > 0 && result != 0) {
            if(num != 0) {
                count++;
                sum+=num;
            } else {
                break;
            }
        } else {
            printf("Qualcosa è andato storto D:\n");
            break;
        }
    }

    printf("Valori totali inseriti: %d\n", count);
    printf("Somma dei valori totali: %u\n", sum);
    printf("Media dei valori totali: %f\n", (sum/(double)count));
}