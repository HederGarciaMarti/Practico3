#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MostrarPersonas.h"
int main(){
    char *v[5];  
    char aux[40];
    for (int i = 0; i < 5; i++) 
    {
        printf("Ingrese el nombre numero %d: ", i + 1);
        fgets(aux, 100, stdin);
        int longitud = strlen(aux) + 1;
        v[i] = malloc(sizeof(char)*longitud);
        strcpy(v[i], aux);
    }

    mostrarNombres(v, 5);


    liberarMemoria(v, 5);
    return 0;
}