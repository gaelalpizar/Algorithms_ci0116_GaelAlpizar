#include "Ordenador.h"
#include <chrono>
#include <fstream>

using namespace std::chrono;

void generarArregloAleatorio(int *A, int n) {
    for (int i = 0; i < n; ++i) {
        A[i] = rand() % 1000; // Números aleatorios entre 0 y 999
    }
}

int main() {
     Ordenador ordenador;

    int tamanos[] = {50000, 100000, 150000, 200000};

    // Número de ejecuciones por arreglo
    const int num_ejecuciones = 3;

    // Abrir archivo de texto para escribir los resultados
    ofstream resultados("resultados.txt");

    for (int tam : tamanos) {
        resultados << "Tamaño del arreglo: " << tam << endl;
        
        int *arreglo = new int[tam];

        // Ejecutar cada algoritmo varias veces
        for (int i = 0; i < num_ejecuciones; ++i) {

            // Generar arreglo aleatorio
            generarArregloAleatorio(arreglo, tam);

            // // Ejecutar y medir el tiempo de ejecución para cada algoritmo
            // // Hay que hacerlo cada uno por separado (Se comentan todos y solo se descomenta
            // // el de un algoritmo)
            // auto start_seleccion = high_resolution_clock::now();
            // ordenador.seleccion(arreglo, tam);
            // auto stop_seleccion = high_resolution_clock::now();
            // auto duration_seleccion = duration<double, std::milli>(stop_seleccion - start_seleccion);

            // auto start_insercion = high_resolution_clock::now();
            // ordenador.insercion(arreglo, tam);
            // auto stop_insercion = high_resolution_clock::now();
            // auto duration_insercion = duration<double, std::milli>(stop_insercion - start_insercion);


            // auto start_mergesort = high_resolution_clock::now();
            // ordenador.mergesort(arreglo, tam);
            // auto stop_mergesort = high_resolution_clock::now();
            // auto duration_mergesort = duration<double, std::milli>(stop_mergesort - start_mergesort);


            // auto start_heapsort = high_resolution_clock::now();
            // ordenador.heapsort(arreglo, tam);
            // auto stop_heapsort = high_resolution_clock::now();
            // auto duration_heapsort = duration<double, std::milli>(stop_heapsort - start_heapsort);
            

            // auto start_quicksort = high_resolution_clock::now();
            // ordenador.quicksort(arreglo, tam);
            // auto stop_quicksort = high_resolution_clock::now();
            // auto duration_quicksort = duration<double, std::milli>(stop_quicksort - start_quicksort);

            auto start_radixsort = high_resolution_clock::now();
            ordenador.radixsort(arreglo, tam);
            auto stop_radixsort= high_resolution_clock::now();
            auto duration_radixsort = duration<double, std::milli>(stop_radixsort - start_radixsort);
            // Imprimir y escribir los tiempos de ejecución en el archivo de resultados
            //resultados << "Tiempo de ejecución (seleccion): " << duration_seleccion.count() << " ms" << endl;
            //resultados << "Tiempo de ejecución (insercion): " << duration_insercion.count() << " ms" << endl;
            //resultados << "Tiempo de ejecución (mergesort): " << duration_mergesort.count() << " ms" << endl;
            //resultados << "Tiempo de ejecución (heapsort): " << duration_heapsort.count() << " ms" << endl;
            //resultados << "Tiempo de ejecución (quicksort): " << duration_quicksort.count() << " ms" << endl;
            resultados << "Tiempo de ejecución (radixsort): " << duration_radixsort.count() << " ms" << endl;
        }

        // Liberar memoria del arreglo
        delete[] arreglo;
    }

    // Cerrar archivo de resultados
    resultados.close();

   

    // // Verificar si se ordena correctamente:
    // // Arreglo de prueba
    // int A[] = {12, 5, 8, 3, 9, 20, 15, 7};
    // int n = sizeof(A) / sizeof(A[0]);

    // // Prueba del algoritmo de selección
    // ordenador.seleccion(A, n);
    // cout << "Seleccion: ";
    
    // for (int i = 1; i < n; i++){
    //     if(A[i] < A[i-1]){
    //         cout << "Error-" << ImprimirDatosDeTarea();
    //     } else {
    //         cout << A[i] << ", ";
    //     }
    // }
    // cout << endl;

    // // Arreglo de prueba
    // int A2[] = {12, 5, 8, 3, 9, 20, 15, 7};

    // // Prueba del algoritmo de insercion
    // ordenador.insercion(A2, n);
    // cout << "Insercion: ";
    
    // for (int i = 1; i < n; i++){
    //     if(A2[i] < A2[i-1]){
    //         cout << "Error-" << ImprimirDatosDeTarea();
    //     } else {
    //         cout << A2[i] << ", ";
    //     }
    // }
    // cout << endl;

    // // Arreglo de prueba
    // int A3[] = {12, 5, 8, 3, 9, 20, 15, 7};

    // // Prueba del algoritmo mergesort
    // ordenador.mergesort(A3, n);
    // cout << "Merge Sort: ";
    
    // for (int i = 1; i < n; i++){
    //     if(A3[i] < A3[i-1]){
    //         cout << "Error-" << ImprimirDatosDeTarea();
    //     }else {
    //         cout << A3[i] << ", ";
    //     }
    // }

  return 0;
}