//
//  chtable.h
//

#ifndef chtable_h
#define chtable_h

#include "dllist.h"
#include <vector>

template <typename T>

// Tabla de dispersión con encadenamiento
class chtable {
public:

    /**
     * @brief Constructor que especifica el tamaño de la tabla
     * @param sz Tamaño de la tabla
     */
    chtable(int sz) {
        size = sz;
        table.resize(size);
    };
        
    /**
     * @brief Destructor (borra la tabla)
     */
    ~chtable() {
    };
    
    /**
     * @brief Inserta el elemento en la tabla
     * @param k Elemento a insertar.
     */
    void Insert(const T& k) {
        int index = hash(k);
        llnode<T>* newNode = new llnode<T>(k);
        table[index].Insert(newNode);
    };
    
    /**
     * @brief Retorna un puntero a la llave o nullptr si no se encuentra.
     * @param k Elemento a buscar.
     * @return Puntero al elemento o nullptr si no se encuentra.
     */
    T* Search(const T& k) {
        int index = hash(k);
        llnode<T>* node = table[index].Search(k);
        if (node == nullptr) {
            return nullptr;
        } else {
            return &(node->getKey());
        }
    };

    /**
     * @brief Elimina el elemento de la tabla.
     * @param k Elemento a eliminar.
     */
    void Delete(const T& k) {
        int index = hash(k);
        llnode<T>* node = table[index].Search(k);
        if (node != nullptr) {
            table[index].Delete(node);
        }
    }
    
    
private:
    // Número de entradas en la tabla
    int size;
    
    // La tabla es un vector de listas de STL
    std::vector<dllist<T> > table;

    /**
     * @brief Función de dispersión
     * @param k Clave a dispersar.
     * @return Índice de la tabla.
     */
    int hash(const T& k) const {
        return k % size;
    }


};

#endif /* chtable_h */
