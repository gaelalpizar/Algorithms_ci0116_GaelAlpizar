#include "Ordenador.h"



int main() {
    Ordenador ordenador;

    // Verificar si se ordena correctamente:
    // Arreglo de prueba
    int A[] = {12, 5, 8, 3, 9, 20, 15, 7};
    int n = sizeof(A) / sizeof(A[0]);

    // Prueba del algoritmo de selección
    ordenador.seleccion(A, n);
    cout << "Seleccion: ";
    
    for (int i = 1; i < n; i++){
        if(A[i] < A[i-1]){
            cout << "Error-" << ImprimirDatosDeTarea();
        } else {
            cout << A[i] << ", ";
        }
    }
    cout << endl;

    // Arreglo de prueba
    int A2[] = {12, 5, 8, 3, 9, 20, 15, 7};

    // Prueba del algoritmo de insercion
    ordenador.insercion(A2, n);
    cout << "Insercion: ";
    
    for (int i = 1; i < n; i++){
        if(A2[i] < A2[i-1]){
            cout << "Error-" << ImprimirDatosDeTarea();
        } else {
            cout << A2[i] << ", ";
        }
    }
    cout << endl;

    // Arreglo de prueba
    int A3[] = {12, 5, 8, 3, 9, 20, 15, 7};

    // Prueba del algoritmo mergesort
    ordenador.mergesort(A3, n);
    cout << "Merge Sort: ";
    
    for (int i = 1; i < n; i++){
        if(A3[i] < A3[i-1]){
            cout << "Error-" << ImprimirDatosDeTarea();
        }else {
            cout << A3[i] << ", ";
        }
    } 


    
    return 0;

}