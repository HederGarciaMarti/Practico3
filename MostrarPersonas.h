#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarNombres(char *persona[], int n){
    printf("\nNombres ingresados:\n");
    for (int i = 0; i < n; i++) {
        printf("%s", persona[i]);
    }
}
void liberarMemoria(char *persona[], int n){
    for (int i = 0; i < n; i++)
    {
        free(persona[i]);
    }
}
