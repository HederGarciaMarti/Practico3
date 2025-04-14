#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MostrarPersonas.h"
int main(){
    char *v[5];  
    char aux[40], nombre[40];
    int numero, continuar = 1, id;
    while (continuar < 2)
    {
        fflush(stdin);
        for (int i = 0; i < 5; i++) 
        {
            printf("Ingrese el nombre numero %d: ", i + 1);
            fgets(aux, 100, stdin);
            int longitud = strlen(aux) + 1;
            v[i] = malloc(sizeof(char)*longitud);
            strcpy(v[i], aux);
        }
    
        mostrarNombres(v, 5);
        do
        {
            printf("Presione 1 o 2\n");
            printf("1-Buscar nombre por id\n2-Buscar nombre por clave\n");
            scanf("%d", &numero);
            
            if (numero == 1)
            {
                printf("Elija uno de los numeros para buscar el nombre\n");
                scanf("%d", &id);
                char *nombreBuscado = BuscaNombrePorId(v, 5, id);
                 if (nombreBuscado == NULL)
                {
                    printf("No se encontro el nombre\n");
                }else{
                    printf("El nombre encontrado es: %s\n", nombreBuscado);
                }
            }else{
                printf("Elija uno de los nombres para buscar\n");
                fflush(stdin);
                gets(nombre);
                if (numero == 2)
                {
                    char *resultadoNombre =  BuscaNombrePorPalabra(v, 5, nombre);
                    if (resultadoNombre == NULL)
                    {
                        printf("No se encontro el nombre:\n");
                    }else{
                        printf("El nombre encontrado es: %s\n", resultadoNombre);
                    }
                }else{
                    printf("Numero incorrecto");
                }
                
            }
        } while (!((numero == 1) || (numero == 2)));
        printf("Desea continuar con el programa presione\n1-si\n2-no\n");
        scanf("%d", &continuar);
    }
    
  
    
    liberarMemoria(v, 5);
    return 0;
}