//
//  bstree.h
//

#ifndef bstree_h
#define bstree_h

#include <iostream>

/**
 * @brief Clase de un nodo en un árbol binario de búsqueda.
 * @tparam T Tipo de dato de la clave en el nodo.
 */
template <typename T>
class bstnode
{
private:
    T key;                  ///< Clave del nodo.
    bstnode<T> *left;       ///< Puntero al hijo izquierdo.
    bstnode<T> *right;      ///< Puntero al hijo derecho.
    bstnode<T> *p;          ///< Puntero al nodo padre.
public:
    // Esta clase es usada por otras clases. 
    // Modifique los atributos para que sean privados y se accedan solo mediante métodos públicos de la clase.
    
    /**
     * @brief Constructor por omisión que inicializa un nodo vacío.
     */
    bstnode(): key(0), p(nullptr), left(nullptr), right(nullptr) {
    };
    
    /**
     * @brief Inicialización de datos miembro
     * @param k Clave del nodo.
     * @param w Puntero al nodo padre.
     * @param y Puntero al nodo hijo izquierdo.
     * @param z Puntero al nodo hijo derecho.
     */
    bstnode(const T& k, bstnode<T> *w = nullptr, bstnode<T> *y = nullptr, bstnode<T> *z = nullptr):key(k), p(w), left(y), right(z) {};
    
    /**
     * @brief Destructor de la clase bstnode.
     */
    ~bstnode() {
    };
};

/**
 * @brief Clase de un árbol binario de búsqueda.
 * @tparam T Tipo de dato de las claves en los nodos.
 */
template <typename T>
class bstree
{
private:
    bstnode<T> *root;    // raíz del árbol
public:
    // Esta clase es usada por otras clases. 
    // Modifique los atributos para que sean privados y se accedan solo mediante métodos públicos de la clase.
    

    // Constructor (crea un árbol vacío)
    bstree() : root(nullptr) { };
    
    ~bstree() {
        // Destructor (borra el árbol)
    };
    
    void Insert(bstnode<T>* z) {
        // Inserta el nodo z en la posición que le corresponde en el árbol.
    };
    
    void InorderWalk(bstnode<T> *x) {
        // Recorre en orden el subárbol con raíz x, imprimiendo la llave de cada nodo en en una nueva línea de la salida estándar después de recorrido el subárbol izquierdo y antes de recorrer el subárbol derecho.
    };
    
    bstnode<T>* Search(bstnode<T> *x, const T& k) {
        // Busca la llave k recursivamente en el subárbol con raíz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve nullptr.
    };
    
    bstnode<T>* IterativeSearch(bstnode<T> *x, const T& k) {
        // Busca la llave k iterativamente en el subarbol con raíz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve nullptr.
    };
    
    bstnode<T>* Minimum(bstnode<T> *x) {
        // Devuelve el nodo que tiene la llave menor. Si el árbol está vacío, devuelve nullptr.
    };
    
    bstnode<T>* Maximum(bstnode<T> *x) {
        // Devuelve el nodo que tiene la llave mayor. Si el árbol esta vacío devuelve nullptr.
    };
    
    bstnode<T>* Successor(bstnode<T> *x) {
        // Devuelve el nodo cuya llave es la que le sigue a la del nodo x. Si no existe el nodo, devuelve nullptr.
    };
    
    void Delete(bstnode<T>* z) {
        // Saca del árbol la llave contenida en el nodo apuntado por z.
    };  
};

#endif /* bstree_h */

