//
//  rbtree.h
//

#ifndef rbtree_h
#define rbtree_h

#include <iostream>
#include <string>

enum colors {RED, BLACK};

// Nodos del árbol:
template <typename T>
class rbtnode
{
public:
    // Esta clase es usada por otras clases. 
    // Modifique los atributos para que sean privados y se accedan solo mediante métodos públicos de la clase.
    T key;
    rbtnode<T> *p, *left, *right;
    enum colors color;
    
    /**
     * @brief Constructor por omisión que inicializa un nodo vacío.
     */
    rbtnode() {
        this->left = nullptr;
        this->right = nullptr;
        this->p =nullptr;
        this->key = 0;
        this->color = RED;
    };
    
    /**
     * @brief Inicialización de datos miembro
     * @param k Clave del nodo.
     * @param w Puntero al nodo padre.
     * @param y Puntero al nodo hijo izquierdo.
     * @param z Puntero al nodo hijo derecho.
     * @param c Color del nodo
     */
    rbtnode (const T& k, rbtnode<T> *w = nullptr, rbtnode<T> *y = nullptr, rbtnode<T> *z = nullptr, enum colors c = RED): key(k), p(w), left(y), right(z), color(c) {};
    
    /**
     * @brief Destructor de la clase rbtnode.
     */
    ~rbtnode() {
    };
};

// Arbol rojinegro:
template <typename T>
class rbtree {
private:

     /**
     * @brief Realiza una rotación a la izquierda sobre el nodo x.
     * 
     * @param x Nodo sobre el cual se realiza la rotación
     */
    void LeftRotate(rbtnode<T>* x) {
        rbtnode<T>* y = x->right;
        x->right = y->left;
        if (y->left != nil) {
            y->left->p = x;
        }
        y->p = x->p;
        if (x->p == nil) {
            root = y;
        } else if (x == x->p->left) {
            x->p->left = y;
        } else {
            x->p->right = y;
        }
        y->left = x;
        x->p = y;
    }

    /**
     * @brief Realiza una rotación a la derecha sobre el nodo x.
     * 
     * @param x Nodo sobre el cual se realiza la rotación
     */
    void RightRotate(rbtnode<T>* x) {
        rbtnode<T>* y = x->left;
        x->left = y->right;
        if (y->right != nil) {
            y->right->p = x;
        }
        y->p = x->p;
        if (x->p == nil) {
            root = y;
        } else if (x == x->p->right) {
            x->p->right = y;
        } else {
            x->p->left = y;
        }
        y->right = x;
        x->p = y;
    }

    /**
     * @brief Corrige las violaciones de las propiedades del árbol rojo-negro después de una inserción.
     * 
     * @param z Nodo insertado
     */
    void InsertFixup(rbtnode<T>* z) {
        while (z->p->color == RED) {
            if (z->p == z->p->p->left) {
                rbtnode<T>* y = z->p->p->right;
                if (y->color == RED) {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                } else {
                    if (z == z->p->right) {
                        z = z->p;
                        LeftRotate(z);
                    }
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    RightRotate(z->p->p);
                }
            } else {
                rbtnode<T>* y = z->p->p->left;
                if (y->color == RED) {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                } else {
                    if (z == z->p->left) {
                        z = z->p;
                        RightRotate(z);
                    }
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    LeftRotate(z->p->p);
                }
            }
        }
        root->color = BLACK;
    }

        /**
     * @brief Corrige las violaciones de las propiedades del árbol rojo-negro después de una eliminación.
     * 
     * @param x Nodo que se va a corregir
     */
    void DeleteFixup(rbtnode<T>* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->p->left) {
                rbtnode<T>* w = x->p->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->p->color = RED;
                    LeftRotate(x->p);
                    w = x->p->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->p;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        RightRotate(w);
                        w = x->p->right;
                    }
                    w->color = x->p->color;
                    x->p->color = BLACK;
                    w->right->color = BLACK;
                    LeftRotate(x->p);
                    x = root;
                }
            } else {
                rbtnode<T>* w = x->p->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->p->color = RED;
                    RightRotate(x->p);
                    w = x->p->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->p;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        LeftRotate(w);
                        w = x->p->left;
                    }
                    w->color = x->p->color;
                    x->p->color = BLACK;
                    w->left->color = BLACK;
                    RightRotate(x->p);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    /**
     * @brief Reemplaza el subárbol u con el subárbol v.
     * 
     * @param u Subárbol a ser reemplazado
     * @param v Subárbol que reemplaza a u
     */
    void Transplant(rbtnode<T>* u, rbtnode<T>* v) {
        if (u->p == nil) {
            root = v;
        } else if (u == u->p->left) {
            u->p->left = v;
        } else {
            u->p->right = v;
        }
        v->p = u->p;
    }


    /**
     * @brief Borra todos los nodos del árbol
     * 
     * @param x Raíz del subárbol a borrar
     */
    void clear(rbtnode<T>* x) {
        if (x != nil) {
            clear(x->left);
            clear(x->right);
            delete x;
        }
    }

public:
    rbtnode<T> *root;    // raíz del árbol
    rbtnode<T> *nil;     // nodo nil (hoja) del árbol
    
    /**
     * @brief Constructor (crea un árbol vacío).
     * Inicializa un árbol rojinegro con un nodo nil negro.
     */
    rbtree() {
        // Crear el nodo nil
        nil = new rbtnode<T>();
        nil->color = BLACK;
        nil->left = nullptr;
        nil->right = nullptr;
        nil->p = nullptr;
        
        // Inicializar la raíz del árbol como nil
        root = nil;
       
    };
    
    /**
     * @brief Destructor (borra el árbol).
     */
    ~rbtree() {
        clear(root);
        delete nil;
    };
    
    /**
     * @brief Inserta el nodo z en la posición que le corresponde en el árbol.
     * 
     * @param z Puntero al nodo que se va a insertar
     */
    void Insert(rbtnode<T>* z) {
        rbtnode<T>* y = nil;
        rbtnode<T>* x = root;
        while (x != nil) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->p = y;
        if (y == nil) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
        z->left = nil;
        z->right = nil;
        z->color = RED;
        InsertFixup(z);
    };
    
    void InorderWalk(rbtnode<T> *x) {
        // Recorre en orden el subarbol con raíz x, imprimiendo la llave de cada nodo en en una nueva linea de la salida estandar despues de recorrido el subarbol izquierdo y antes de recorrer el subarbol derecho.
    };
    
    rbtnode<T>* Search(rbtnode<T> *x, const T& k) {
        // Busca la llave k iterativamente en el subarbol con raíz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve el nodo nil.
    };
    
    rbtnode<T>* IterativeSearch(rbtnode<T> *x, const T& k) {
        // Busca la llave k iterativamente en el subarbol con raíz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve el nodo nil.
    };
    
    rbtnode<T>* Minimum(rbtnode<T> *x) {
        // Devuelve el nodo que tiene la llave menor. Si el árbol esta vacío, devuelve el nodo nil.
    };
    
    rbtnode<T>* Maximum(rbtnode<T> *x) {
        // Devuelve el nodo que tiene la llave mayor. Si el árbol esta vacío devuelve el nodo nil.
    };
    
    rbtnode<T>* Successor(rbtnode<T> *x) {
        // Devuelve el nodo cuya llave es la que le sigue a la del nodo x. Si no existe el nodo, devuelve el nodo nil.
    };
};

#endif /* rbtree_h */
