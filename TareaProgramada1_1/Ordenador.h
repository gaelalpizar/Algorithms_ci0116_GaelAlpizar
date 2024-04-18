#ifndef Ordenador_h
#define Ordenador_h

class Ordenador{
	private:
    // Defina aqui los metodos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos metodos quiera.
	void merge(int *A, int p, int q, int r);
    void mergeSortRecursive(int *A, int p, int r);

	public:
	Ordenador(){};
	~Ordenador(){};
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

void Ordenador::seleccion(int *A, int n){
	for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[m]) {
                m = j;
            }
        }
        // swap(A[i], A[m])
        int temp = A[i];
        A[i] = A[m];
        A[m] = temp;
    }
}

void Ordenador::insercion(int *A, int n){
	for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

void Ordenador::merge(int *A, int p, int q, int r){
    int nL = q - p + 1;
    int nR = r - q;
    int *L = new int[nL];
    int *R = new int[nR];

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

void Ordenador::mergeSortRecursive(int *A, int p, int r){
    if (p >= r)
        return;
    int q = (p + r) / 2;
    mergeSortRecursive(A, p, q);
    mergeSortRecursive(A, q + 1, r);
    merge(A, p, q, r);
}