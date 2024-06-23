//
//  chtable.h
//

#ifndef chtable_h
#define chtable_h

#include <list>
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
        
    // Destructor (borra la tabla)
    ~chtable() {
    };
    
    // Inserta el elemento en la tabla
    void Insert(const T& k) {
    };
    
    // Retorna un puntero a la llave o nullptr si no se encuentra
    T* Search(const T& k) {
    };
    
    
private:
    // Número de entradas en la tabla
    int size;
    
    // La tabla es un vector de listas de STL
    std::vector<std::list<T> > table;
};

#endif /* chtable_h */
