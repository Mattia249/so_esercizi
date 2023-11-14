#include <stdio.h>

int main() {
    int voti, voto, i, somma;
    int res;
    printf("Inserisci il numero di voti da leggere: ");
    res = scanf("%d", &voti);
    if(res != 0 && voti > 0) {
        for(i = 1, somma = 0; i <= voti; i++){
            printf("Inserisci il %d° voto: ", i);
            res = scanf("%d", &voto);
            if(res != 0 && voti >= 0){
                somma += voto;
            } else {
                printf("Inserisci un numero non negativo\n");
                return 1;
            }
        }

        printf("La media dei %d voti è : %f\n", voti, (somma / (double) voti));
    } else {
        printf("Qualcosa è andato storto\n");
        return 1;
    }
    
    return 0;
   
}