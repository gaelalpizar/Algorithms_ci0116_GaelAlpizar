#ifndef Ordenador_h
#define Ordenador_h

#include <iostream>
#include <string>

using namespace std;

class Ordenador{
	private:
    // Defina aqui los metodos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos metodos quiera.
	void merge(int *A, int p, int q, int r);
    void mergeSortRecursive(int *A, int p, int r);
    void maxHeapify(int *A, int i, int heap_size);
    void buildMaxHeap(int *A, int n);


    

	public:
	Ordenador(){};
	~Ordenador(){};
    string ImprimirDatosDeTarea();
	// Si piensa no implementar algunos de los metodos de ordenamiento, no los borre,
	// simplemente dejelos con el cuerpo vacio para evitar errores de compilacion, ya
	// que se va a ejecutar el mismo main para todas las tareas.
    // Implemente los algoritmos en este archivo  (no en un CPP aparte).
	void seleccion(int *A, int n);
	void insercion(int *A, int n);
	void mergesort(int *A, int n);
	void heapsort(int *A, int n);
	void quicksort(int *A, int n);
	void radixsort(int *A, int n);
};
#endif

/**
 * Ordena un arreglo de enteros utilizando el algoritmo de selección.
 * @param A: puntero al arreglo a ordenar.
 * @param n: tamaño del arreglo.
 */
void Ordenador::seleccion(int *A, int n){
    for (int i = 0; i < n - 1; i++) {
        int m = i; // Selecciona el índice actual como el mínimo
        // Encuentra el índice del mínimo en el resto del arreglo
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[m]) {
                m = j;
            }
        }
        // Intercambia los valores de A[i] y A[m]
        int temp = A[i];
        A[i] = A[m];
        A[m] = temp;
    }
}

/**
 * Ordena un arreglo de enteros utilizando el algoritmo de inserción.
 * @param A: puntero al arreglo a ordenar.
 * @param n: tamaño del arreglo.
 */
void Ordenador::insercion(int *A, int n){
    for (int i = 1; i < n; i++) {
        int key = A[i]; // Elemento a insertar
        int j = i - 1;
        // Mover elementos de A[0..i-1] que son mayores que key a una posición adelante de su posición actual
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key; // Insertar key en su posición correcta
    }
}

/**
 * Fusiona dos subarreglos ordenados en un arreglo ordenado.
 * @param A: puntero al arreglo que contiene los subarreglos.
 * @param p: índice inicial del primer subarreglo.
 * @param q: índice final del primer subarreglo.
 * @param r: índice final del segundo subarreglo.
 */
void Ordenador::merge(int *A, int p, int q, int r){
    int nL = q - p + 1; // Tamaño del subarreglo izquierdo
    int nR = r - q; // Tamaño del subarreglo derecho
    int *L = new int[nL]; // Arreglo temporal para el subarreglo izquierdo
    int *R = new int[nR]; // Arreglo temporal para el subarreglo derecho

    // Copiar elementos a los subarreglos L y R
    for (int i = 0; i < nL; i++)
        L[i] = A[p + i];
    for (int j = 0; j < nR; j++)
        R[j] = A[q + j + 1];

    int i = 0, j = 0, k = p;

    // Mezclar los subarreglos L y R en el arreglo A
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L (si hay alguno)
    while (i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R (si hay alguno)
    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }

    // Liberar memoria 
    delete[] L;
    delete[] R;
}


/**
 * Ordena recursivamente un arreglo de enteros utilizando el algoritmo de ordenamiento por fusión.
 * @param A: puntero al arreglo a ordenar.
 * @param p: índice inicial del subarreglo a ordenar.
 * @param r: índice final del subarreglo a ordenar.
 */
void Ordenador::mergeSortRecursive(int *A, int p, int r){
    if (p >= r)
        return;
    int q = (p + r) / 2;
    mergeSortRecursive(A, p, q); // Ordenar la mitad izquierda
    mergeSortRecursive(A, q + 1, r); // Ordenar la mitad derecha
    merge(A, p, q, r); // Fusionar las mitades ordenadas
}

/**
 * Ordena un arreglo de enteros utilizando el algoritmo de ordenamiento por fusión.
 * @param A: puntero al arreglo a ordenar.
 * @param n: tamaño del arreglo.
 */
void Ordenador::mergesort(int *A, int n){
    mergeSortRecursive(A, 0, n - 1);
}

/** 
 * Ajusta un elemento en el montículo máximo (Max Heap). 
 * @param A: puntero al arreglo que representa el montículo. 
 * @param i: índice del elemento a ajustar. 
 * @param heap_size: tamaño del montículo. 
 */
void Ordenador::maxHeapify(int *A, int i, int heap_size) {
    int l = 2 * i + 1; // índice del hijo izquierdo
    int r = 2 * i + 2; // índice del hijo derecho
    int largest = i;   // índice del mayor entre el nodo actual y sus hijos

    // Si el hijo izquierdo existe y es mayor que el nodo actual
    if (l < heap_size && A[l] > A[i])
        largest = l;
    // Si el hijo derecho existe y es mayor que el mayor hasta ahora
    if (r < heap_size && A[r] > A[largest])
        largest = r;

    // Si el mayor no es el nodo actual, se intercambia y se llama recursivamente a maxHeapify
    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, largest, heap_size);
    }
}

/** 
 * Construye un montículo máximo a partir de un arreglo dado. 
 * @param A: puntero al arreglo que contiene los elementos a convertir en un montículo máximo. 
 * @param n: tamaño del arreglo. 
 */
void Ordenador::buildMaxHeap(int *A, int n) {
    int heap_size = n; // Tamaño inicial del montículo
    // Comenzando desde el último nodo que tiene hijos, llamamos a maxHeapify para todos los nodos no hoja
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(A, i, heap_size);
}

/**
 * Ordena un arreglo usando el algoritmo de Heap Sort. 
 * @param A: puntero al arreglo que se va a ordenar. 
 * @param n: tamaño del arreglo. 
 */
void Ordenador::heapsort(int *A, int n) {
    // Construimos un montículo máximo inicialmente
    buildMaxHeap(A, n);
    int heap_size = n; // Tamaño del montículo
    // Empezamos desde el último elemento y repetimos hasta que sólo quede un elemento sin procesar
    for (int i = n - 1; i >= 1; i--) {
        // Intercambiamos el primer elemento (máximo) con el último elemento del montículo
        swap(A[0], A[i]);
        // Reducimos el tamaño del montículo en 1
        heap_size--;
        // Llamamos a maxHeapify en el nodo raíz para mantener la propiedad de montículo máximo
        maxHeapify(A, 0, heap_size);
    }
}



// Método para imprimir información de la tarea
string Ordenador::ImprimirDatosDeTarea(){
    return "c20270 Tarea 1 Etapa 2";
}