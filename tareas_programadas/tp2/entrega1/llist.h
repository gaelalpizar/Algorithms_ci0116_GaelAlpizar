//
//  llist.h
//

#ifndef llist_h
#define llist_h

#include <string>

/**
 * @brief Nodos de la lista.
 * 
 * @tparam T Tipo de dato almacenado en el nodo.
 */
template <typename T>
class llnode
{
private:
    T key; // Valor de la llave
    llnode<T> *next; // Nodo que apunta al siguiente nodo del actual

public:
    // Esta clase es usada por otras clases. 
    // Modifique los atributos para que sean privados y se accedan solo mediante métodos públicos de la clase.
    /**
     * @brief Constructor por omisión.
     */
    llnode() : next(nullptr) {
    };
    
    /**
     * @brief Inicialización de los datos miembro.
     * @param k Clave del nodo.
     * @param y Puntero al siguiente nodo (por defecto es nullptr).
     */
    llnode (const T& k, llnode<T> *y = nullptr):key(k), next(y)  {};
    
    /**
     * @brief Destructor de la clase llnode
     */
    ~llnode() {
    };

     /**
     * @brief Obtiene el valor de la llave.
     * @return El valor de la llave.
     */
    T getKey() const { return key; }

    /**
     * @brief Obtiene el puntero al siguiente nodo.
     * @return El puntero al siguiente nodo.
     */
    llnode<T>* getNext() const { return next; }

    /**
     * @brief Establece el valor de la llave.
     * @param k Clave del nodo.
     */
    void setKey(const T& k) { key = k; }

    /**
     * @brief Establece el puntero al siguiente nodo.
     * @param n Puntero al siguiente nodo.
     */
    void setNext(llnode<T>* n) { next = n; }
};

/**
 * @brief Lista enlazada con nodo centinela.
 * 
 * @tparam T Tipo de dato almacenado en los nodos de la lista.
 */
template <typename T>
class llist
{
private: 
    llnode<T> *nil;        // nodo centinela

public:
    // Esta clase es usada por otras clases. 
    // Modifique los atributos para que sean privados y se accedan solo mediante métodos públicos de la clase.

    /**
     * @brief Constructor (crea una lista vacía).
     */
    llist() {
        nil = new llnode<T>();
        nil->setNext(nil);  // El nodo centinela apunta a sí mismo
    };
    
    /**
     * @brief Destructor (borra la lista).
     */
    ~llist() {
        llnode<T>* current = nil->getNext();
        while (current != nil) {
            llnode<T>* next = current->getNext();
            delete current;  // Elimina el nodo actual
            current = next;  // Avanza al siguiente nodo
        }
        delete nil;  // Elimina el nodo centinela
    };
    

    /**
     * @brief Inserta el nodo x en la lista.
     * @param x Nodo a insertar.
     */
    void Insert(llnode<T>* x) {
        x->setNext(nil->getNext());  // El siguiente de x es el primero de la lista actual
        nil->setNext(x);  // El centinela ahora apunta a x
    };

    /**
     * @brief Busca la llave iterativamente. Si la encuentra, devuelve un apuntador al nodo que la contiene; sino, devuelve el nodo nil (el centinela).
     * @param k Clave a buscar.
     * @return Puntero al nodo que contiene la clave o al nodo centinela si no se encuentra.
     */
    llnode<T>* Search(const T& k) {
        llnode<T>* x = nil->getNext();  // Empieza desde el primer nodo
        while (x != nil && x->getKey() != k) {
            x = x->getNext();  // Avanza al siguiente nodo
        }
        return x;  // Devuelve el nodo encontrado o el nodo centinela
    };

    /**
     * @brief Saca de la lista la llave contenida en el nodo apuntado por x.
     * @param x Nodo a eliminar.
     */  
    void Delete(llnode<T>* x) {
        llnode<T>* current = nil;
        while (current->getNext() != nil && current->getNext() != x) {
            current = current->getNext();  // Encuentra el nodo anterior a x
        }
        if (current->getNext() == x) {
            current->setNext(x->getNext());  // Salta el nodo x
            delete x;  // Elimina el nodo x
        }

    };   

    // Método para imprimir información de la tarea
    string ImprimirDatosDeTarea(){
        return "c20270 Tarea 2 Etapa 1";
    } 
};

#endif /* llist_h */
