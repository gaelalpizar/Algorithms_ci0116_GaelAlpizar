#ifndef dllist_h
#define dllist_h

#include <string>

/**
 * @brief Nodos de la lista doblemente enlazada.
 * 
 * @tparam T Tipo de dato almacenado en el nodo.
 */
template <typename T>
class llnode {
private:
    T key; // Valor de la llave
    llnode<T>* next; // Puntero al siguiente nodo
    llnode<T>* prev; // Puntero al nodo anterior

public:
    /**
     * @brief Constructor por omisión.
     */
    llnode() : next(nullptr), prev(nullptr) {}

    /**
     * @brief Inicialización de los datos miembro.
     * @param k Clave del nodo.
     * @param n Puntero al siguiente nodo (por defecto es nullptr).
     * @param p Puntero al nodo anterior (por defecto es nullptr).
     */
    llnode(const T& k, llnode<T>* n = nullptr, llnode<T>* p = nullptr)
        : key(k), next(n), prev(p) {}

    /**
     * @brief Destructor de la clase llnode.
     */
    ~llnode() {}

    /**
     * @brief Obtiene el valor de la llave.
     * @return El valor de la llave.
     */
    T getKey() const { return key; }

    T& getKeyReference() { return key; }

    /**
     * @brief Obtiene el puntero al siguiente nodo.
     * @return El puntero al siguiente nodo.
     */
    llnode<T>* getNext() const { return next; }

    /**
     * @brief Obtiene el puntero al nodo anterior.
     * @return El puntero al nodo anterior.
     */
    llnode<T>* getPrev() const { return prev; }

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

    /**
     * @brief Establece el puntero al nodo anterior.
     * @param p Puntero al nodo anterior.
     */
    void setPrev(llnode<T>* p) { prev = p; }
};

/**
 * @brief Lista doblemente enlazada con nodo centinela.
 * 
 * @tparam T Tipo de dato almacenado en los nodos de la lista.
 */
template <typename T>
class dllist {
private:
    llnode<T>* nil; // Nodo centinela

public:
    /**
     * @brief Constructor (crea una lista vacía).
     */
    dllist() {
        nil = new llnode<T>();
        nil->setNext(nil);
        nil->setPrev(nil);
    }

    /**
     * @brief Destructor (borra la lista).
     */
    ~dllist() {
        llnode<T>* current = nil->getNext();
        while (current != nil) {
            llnode<T>* next = current->getNext();
            delete current;
            current = next;
        }
        delete nil;
    }

    llnode<T>* getSentinel(){ return this->nil; }
     
    

    /**
     * @brief Inserta el nodo x en la lista.
     * @param x Nodo a insertar.
     */
    void Insert(llnode<T>* x) {
        x->setNext(nil->getNext());
        x->setPrev(nil);
        nil->getNext()->setPrev(x);
        nil->setNext(x);
    }

    /**
     * @brief Busca la llave iterativamente. Si la encuentra, devuelve un apuntador al nodo que la contiene; sino, devuelve el nodo nil (el centinela).
     * @param k Clave a buscar.
     * @return Puntero al nodo que contiene la clave o al nodo centinela si no se encuentra.
     */
    llnode<T>* Search(const T& k) {
        llnode<T>* x = nil->getNext();
        while (x != nil && x->getKey() != k) {
            x = x->getNext();
        }
        return x;
    }

    /**
     * @brief Elimina el nodo apuntado por x de la lista.
     * @param x Nodo a eliminar.
     */
    void Delete(llnode<T>* x) {
        if (x != nil) {
            x->getPrev()->setNext(x->getNext());
            x->getNext()->setPrev(x->getPrev());
            delete x;
        }
    }

    /**
     * @brief Método para imprimir información de la tarea.
     * @return Cadena con información de la tarea.
     */
    std::string ImprimirDatosDeTarea() {
        return "c20270 Tarea 2 Etapa 1";
    }
};

#endif /* dllist_h */
