#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
}typedef Producto;
struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef Cliente;
void cargarDatos(Cliente *clientes, int n);
void mostrarClientes(Cliente *clientes, int n);
float costoProducto(Producto produc);
void totalPagar(Cliente *clientes, int n);
void liberarMemoria(Cliente *clientes, int n);
int main(){
    int cantidad_clientes;
    printf("Ingrese la cantidad de clientes entre 1 a 5\n");
    scanf("%d", &cantidad_clientes);
    fflush(stdin);
    Cliente *clientes = malloc(sizeof(Cliente)*cantidad_clientes);
    cargarDatos(clientes, cantidad_clientes);
    mostrarClientes(clientes, cantidad_clientes);
    totalPagar(clientes, cantidad_clientes);
    liberarMemoria(clientes, cantidad_clientes);
    
}
void cargarDatos(Cliente *clientes, int n){
    char aux[40];
    int longitud;
    for (int i = 0; i < n; i++)
    {
        clientes[i].ClienteID = i + 1;
        printf("Ingrese el nombre del cliente numero %d:\n", i + 1);
        gets(aux);
        longitud = strlen(aux) + 1;
        clientes[i].NombreCliente = malloc(sizeof(char)*longitud);
        strcpy(clientes[i].NombreCliente, aux);
        clientes[i].CantidadProductosAPedir = 1 + rand()% 5;
        clientes[i].Productos = malloc(sizeof(Producto) * clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = 1 + rand()% 10;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = 10 + rand() % 91; 
        }
    }
}
void mostrarClientes(Cliente *clientes, int n) {
    for (int i = 0; i < n; i++) {
        printf("Cliente %d\n", clientes[i].ClienteID);
        printf("Nombre: %s\n", clientes[i].NombreCliente);
        printf("Cantidad de productos: %d\n", clientes[i].CantidadProductosAPedir);
        printf("\n");
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            
            printf("Producto %d:\n", clientes[i].Productos[j].ProductoID);
            printf("Tipo: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("Precio unitario: $%.2f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("\n");
        }
    }
}
float costoProducto(Producto produc){
    float result;
    result = produc.Cantidad * produc.PrecioUnitario;
    return result;
}
void totalPagar(Cliente *clientes, int n){
    float result, suma = 0;
    for (int i = 0; i < n; i++)
    {
        printf("\t Cliente numero %d\n", i + 1);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            Producto p = clientes[i].Productos[j];
            result = costoProducto(p);
            suma = suma + result;
        }
        printf("Total a pagar: %.2f\n", suma);
        suma = 0;
    }
    
}
void liberarMemoria(Cliente *clientes, int n){
    for (int i = 0; i < n; i++)
    {
        free(clientes[i].NombreCliente); 
        free(clientes[i].Productos); 
    }
    free(clientes);
}