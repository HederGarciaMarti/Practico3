#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarNombres(char *persona[], int n){
    printf("\nNombres ingresados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d- %s", i, persona[i]);
    }
}
char *BuscaNombrePorId(char *persona[], int n, int indice){
    for (int i = 0; i < n; i++)
    {
        if (i == indice)
        {
            return persona[i];
        }
        
    }
    return NULL;
}
char * BuscaNombrePorPalabra(char *persona[], int n, char *nombre){
    for (int i = 0; i < n; i++)
    {
        if (strstr(persona[i], nombre))
        {
            return persona[i];
        }
        
    }
    return NULL;
}
void liberarMemoria(char *persona[], int n){
    for (int i = 0; i < n; i++)
    {
        free(persona[i]);
    }
}
