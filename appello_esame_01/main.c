#include <stdio.h>
#include <stdlib.h>
/* Sia data la seguente definizione utilizzata per rappresentare dei vettori di numeri interi:
 */
struct vector { 
    int *vls; /* ELEMENTI DEL VETTORE */
    int  n;   /* NUMERO DI ELEMENTI DEL VETTORE */
};

/* 
 * dove vls è il puntatore al primo elemento di una sequenza di n interi già allocato in memoria.
 *
 * Definire la funzione addr_of_maxsum dal seguente prototipo:
 */
 
struct vector * addr_of_maxsum(struct vector a_vector[], const int length);

/*
 * la quale:
 * 1. ha due argomenti:
 *   - a_vector[]: un array di length elementi di tipo struct vector;
 *   - length: il numero di elementi dell'array 'a_vector[]';
 * 2. restituisce il puntatore al vettore di a_vector che ha la massima somma dei suoi elementi.
 * In caso ci siano vettori con somma degli elementi massima identica allora è sufficiente
 * restituire l'indirizzo del primo.
 *   
 * Ad esempio se:
 *
 *    a_vector -> { {{4,-2,3,0,8},5}, {{20,2},2}, {{1,8,-2,0,4},5}, {{7,-2},2} }
 *
 * allora la chiamata addr_of_maxsum(a_vector, 4) restituisce l'indirizzo
 *
 *     a_vector+1
 *
 * perché la somma dei valori memorizzati nel vettore a_vector[1] ha valore massimo pari a 22.
 */

struct vector new_vector(int arr[], int len) { 
    struct vector vect;
    vect.vls = arr;
    vect.n = len;
    return vect;
}

void vector_to_string(struct vector arr) {
    int i;
    printf("Len: %d\n",arr.n);
    printf("{");
    for(i = 0; i < arr.n; i++) {
        printf("%d, ", *(arr.vls));
        arr.vls++;
    }
    printf("}\n");
}

int vector_sum(struct vector arr){
    int i;
    int sum = 0;

    for(i = 0; i < arr.n; i++) {
        sum += *(arr.vls);
        arr.vls++;
    }
    return sum;
}

struct vector *addr_of_maxsum(struct vector a_vector[], const int length) {
    int i;
    int sum;
    struct vector* last_max = NULL;

    if(length > 0) {
        last_max = &a_vector[0];
        int max = vector_sum(*last_max);
            
        for(i = 0; i < length; i++) {
            sum = vector_sum(a_vector[i]);
            if(sum > max) {
                max = sum;
                last_max = &a_vector[i];
            }
        }
    } 
    
    return last_max;
}

int main() { 
    int vect_1[] = {4,2,3,0,8,2};   /* 19 */
    int vect_2[] = {6,2,8};         /* 16 */
    int vect_3[] = {4,2,19,5};      /* 30 */
    int vect_4[] = {4,2,3,-12,8};   /* 16 */
    
    /*
    vector_to_string(new_vector(vect_1, 6));
    vector_to_string(new_vector(vect_2, 3));
    vector_to_string(new_vector(vect_3, 4));
    vector_to_string(new_vector(vect_4, 5));

    printf("\n");

    */

    struct vector arr_1 = new_vector(vect_1, 6);
    struct vector arr_2 = new_vector(vect_2, 3);
    struct vector arr_3 = new_vector(vect_3, 4);
    struct vector arr_4 = new_vector(vect_4, 5);
    
    struct vector* result;
    
    struct vector arr[4];
    arr[0] = arr_1;
    arr[1] = arr_2;
    arr[2] = arr_3;
    arr[3] = arr_4;

    
    result = addr_of_maxsum(arr, 4);
    vector_to_string(*result);
    /*
    printf("vect_1: %d\n", vector_sum(new_vector(vect_1, 6)));
    printf("vect_2: %d\n", vector_sum(new_vector(vect_2, 3)));
    printf("vect_3: %d\n", vector_sum(new_vector(vect_3, 4)));
    printf("vect_4: %d\n", vector_sum(new_vector(vect_4, 5)));
    */
}