//
// Created by dany- on 31/05/2017.
//

#ifndef PAGINACION_NODE_H
#define PAGINACION_NODE_H

#include <iostream>
using namespace std;

class node {
private: //Declaraci�n del contenido de los nodos como privados
    int cantMemoria, idProceso, inicio, fin, UAMs, desperdicio;
    char tipo;
    node *next;
public:
    node(int cantidadMemoria, int idProceso, int inicio, int fin, int UAMs, int desperdicio, char tipo, node *nxt = NULL){ //Constructor de un nodo que recibe los par�metros necesarios para la creaci�n del nodo
        this->cantMemoria = cantidadMemoria; //Almacena la cantidad de memoria necesaria
        this->idProceso = idProceso; //Almacena el identificador del proceso
        this->inicio = inicio;
        this->fin = fin;
        this->UAMs = UAMs;
        this->tipo = tipo;
        this->desperdicio = desperdicio;
        this->next = nxt; //Establece que el nodo apunta a NULL, mientras no se modifique
    }

    int getCantMemoria() const;

    void setCantMemoria(int cantMemoria);

    int getIdProceso() const;

    void setIdProceso(int idProceso);

    int getInicio() const;

    void setInicio(int inicio);

    int getFin() const;

    void setFin(int fin);

    int getUAMs() const;

    void setUAMs(int UAMs);

    int getDesperdicio() const;

    void setDesperdicio(int desperdicio);

    char getTipo() const;

    void setTipo(char tipo);

    node *getNext() const;

    void setNext(node *next);


    void mostrarDatos(){
        cout << "    " << this->tipo << "\t    " << this->idProceso << "\t\t" << this->cantMemoria << "\t\t" << this->UAMs << "\t\t" << this->inicio << "\t  " << this->fin << "\t\t" << this->desperdicio << endl;
    }

    friend class list; //Declara la clase list como clase amiga, con el fin de que esta pueda utilizar sus m�todos.
};
#endif //PAGINACION_NODE_H
