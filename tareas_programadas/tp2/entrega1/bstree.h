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

    /**
     * @brief Obtiene la clave del nodo.
     * @return Clave del nodo.
     */
    T getKey() const { return key; }

    /**
     * @brief Establece la clave del nodo.
     * @param k Clave del nodo.
     */
    void setKey(const T& k) { key = k; }

    /**
     * @brief Obtiene el puntero al nodo padre.
     * @return Puntero al nodo padre.
     */
    bstnode<T>* getParent() const { return p; }

    /**
     * @brief Establece el puntero al nodo padre.
     * @param w Puntero al nodo padre.
     */
    void setParent(bstnode<T> *w) { p = w; }

    /**
     * @brief Obtiene el puntero al hijo izquierdo.
     * @return Puntero al hijo izquierdo.
     */
    bstnode<T>* getLeft() const { return left; }

    /**
     * @brief Establece el puntero al hijo izquierdo.
     * @param y Puntero al hijo izquierdo.
     */
    void setLeft(bstnode<T> *y) { left = y; }

    /**
     * @brief Obtiene el puntero al hijo derecho.
     * @return Puntero al hijo derecho.
     */
    bstnode<T>* getRight() const { return right; }

    /**
     * @brief Establece el puntero al hijo derecho.
     * @param z Puntero al hijo derecho.
     */
    void setRight(bstnode<T> *z) { right = z; }
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

    /**
     * @brief Destruye el árbol y libera la memoria.
     * @param node Puntero a la raíz del subárbol a destruir.
     */
    void destroyTree(bstnode<T>* node) {
        if (node != nullptr) {
            destroyTree(node->getLeft()); // Destruye el subárbol izquierdo.
            destroyTree(node->getRight()); // Destruye el subárbol derecho.
            delete node; 
        }
    }
  
public:
    // Esta clase es usada por otras clases. 
    // Modifique los atributos para que sean privados y se accedan solo mediante métodos públicos de la clase.
    
    /**
     * @brief Constructor (crea un árbol vacío)
     */
    bstree() : root(nullptr) { };
    
    /**
     * @brief Destructor (borra el árbol)
     */
    ~bstree() {
        // Llama a destroyTree para liberar toda la memoria usada por los nodos del árbol.
        destroyTree(root);
    };
    
    /**
     * @brief Inserta el nodo z en la posición que le corresponde en el árbol.
     * @param z Puntero al nodo que se va a insertar.
     */
    void Insert(bstnode<T>* z) {
        bstnode<T> *y = nullptr; // y será el nodo padre del nodo z.
        bstnode<T> *x = root;    // Comenzamos desde la raíz.

        // Recorre el árbol para encontrar la posición correcta para z.
        while (x != nullptr) {
            y = x; // y sigue el rastro de x.
            if (z->getKey() < x->getKey()) {
                x = x->getLeft(); // Moverse al subárbol izquierdo.
            } else {
                x = x->getRight(); // Moverse al subárbol derecho.
            }
        }

        z->setParent(y); // Establece el nodo encontrado como padre de z.

        // Si el árbol estaba vacío, z se convierte en la raíz.
        if (y == nullptr) {
            root = z;
        } else if (z->getKey() < y->getKey()) {
            y->setLeft(z); // z se convierte en el hijo izquierdo de y.
        } else {
            y->setRight(z); // z se convierte en el hijo derecho de y.
        }
    };

    /**
     * @brief Recorre en orden el subárbol con raíz x, imprimiendo la llave de cada nodo en en una nueva línea de la salida estándar después de recorrido el subárbol izquierdo y antes de recorrer el subárbol derecho.
     * @param x Puntero a la raíz del subárbol.
     */
    void InorderWalk(bstnode<T> *x) {
        if (x != nullptr) {
            InorderWalk(x->getLeft());          // Recorre el subárbol izquierdo.
            std::cout << x->getKey() << std::endl; // Imprime la clave del nodo.
            InorderWalk(x->getRight());         // Recorre el subárbol derecho.
        }
    };
    
    /**
     * @brief Busca la llave k recursivamente en el subárbol con raíz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve nullptr.
     * @param x Puntero a la raíz del subárbol.
     * @param k Clave que se busca.
     * @return Puntero al nodo que contiene la clave o nullptr si no se encuentra.
     */
    bstnode<T>* Search(bstnode<T> *x, const T& k) {
        if (x == nullptr || k == x->getKey()) {
            return x; // Si x es nulo o la clave de x es k, retorna x.
        }
        if (k < x->getKey()) {
            return Search(x->getLeft(), k); // Busca en el subárbol izquierdo.
        } else {
            return Search(x->getRight(), k); // Busca en el subárbol derecho.
        }
    };
    
    /**
     * @brief Busca la llave k iterativamente en el subarbol con raíz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve nullptr.
     * @param x Puntero a la raíz del subárbol.
     * @param k Clave que se busca.
     * @return Puntero al nodo que contiene la clave o nullptr si no se encuentra.
     */
    bstnode<T>* IterativeSearch(bstnode<T> *x, const T& k) {
        while (x != nullptr && k != x->getKey()) {
            if (k < x->getKey()) {
                x = x->getLeft(); // Moverse al subárbol izquierdo.
            } else {
                x = x->getRight(); // Moverse al subárbol derecho.
            }
        }
        return x; // Retorna x, que puede ser nullptr si no se encontró la clave.
    };

    /**
     * @brief Devuelve el nodo que tiene la llave menor. Si el árbol está vacío, devuelve nullptr.
     * @param x Puntero a la raíz del subárbol.
     * @return Puntero al nodo con la clave menor.
     */
    bstnode<T>* Minimum(bstnode<T> *x) {
        while (x->getLeft() != nullptr) {
            x = x->getLeft(); // Moverse continuamente al hijo izquierdo.
        }
        return x; // El nodo más a la izquierda es el mínimo.
    };
    
    /**
     * @brief Devuelve el nodo que tiene la llave mayor. Si el árbol esta vacío devuelve nullptr.
     * @param x Puntero a la raíz del subárbol.
     * @return Puntero al nodo con la clave mayor.
     */
    bstnode<T>* Maximum(bstnode<T> *x) {
        while (x->getRight() != nullptr) {
            x = x->getRight(); // Moverse continuamente al hijo derecho.
        }
        return x; // El nodo más a la derecha es el máximo.
    };
    
    bstnode<T>* Successor(bstnode<T> *x) {
        // Devuelve el nodo cuya llave es la que le sigue a la del nodo x. Si no existe el nodo, devuelve nullptr.
    };
    
    void Delete(bstnode<T>* z) {
        // Saca del árbol la llave contenida en el nodo apuntado por z.
    };  
};

#endif /* bstree_h */

