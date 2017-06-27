//
// Created by dany- on 31/05/2017.
//

#ifndef PAGINACION_LIST_H
#define PAGINACION_LIST_H

#include <iostream>
#include "node.h"
using namespace std;

class list {
private:
    node *first;
    node *actual;
public:
    //Prueba para saber si la lista est� vac�a
    bool isEmpty(){
        return(this->first == NULL);
    }
    list(){
        this->first = NULL;
        this->actual = NULL;
    }
    //M�todo para insertar nodos (procesos) a la lista
    void insertarAlFinal(int cantidadMemoria, int idProceso, int inicio, int fin, int UAMs, int desperdicio, char tipo){
        node *nuevo = new node(cantidadMemoria, idProceso, inicio, fin, UAMs, desperdicio, tipo); // Creaci�n de un nuevo nodo
        if(isEmpty()){ //Prueba para determinar si es el primer nodo o no
            this->first = nuevo; //De ser verdadera, el nodo se inserta al inicio
        } else {
            this->actual->next = nuevo; // De lo contrario, se inserta despu�s del �ltimo nodo insertado
        }
        this->actual = nuevo; //El nuevo nodo se vuelve el �ltimo insertado
    }

    void insertarAlInicio(int cantidadMemoria, int idProceso, int inicio, int fin, int UAMs, int desperdicio, char tipo){
        node *nuevo = new node(cantidadMemoria, idProceso, inicio, fin, UAMs, desperdicio, tipo);
        if(isEmpty()){
            this->first = nuevo;
        } else {
            nuevo->setNext(first);
            first = nuevo;
        }
    }

    void insertarEnMedio(int cantidadMemoria, int idProceso, int inicio, int fin, int UAMs, int desperdicio, char tipo, node *prev){
        node *nuevo = new node(cantidadMemoria, idProceso, inicio, fin, UAMs, desperdicio, tipo);
        nuevo->setNext(prev->getNext());
        prev->setNext(nuevo);
    }
    //M�todo para imprimir la lista despu�s de insertar los datos
    void imprimir(){
        node *p = this->first; //Inicializaci�n del nodo utilizado para recorrer la lista
        if(!isEmpty()){
            cout << "----------------------------------------------------------------------------------------" << endl;
            cout << "|  Tipo  |  ID  |  Memoria usada  |  UAMs ocupadas  |  Inicio  |  Fin  |  Desperdicio  |" << endl;
            cout << "----------------------------------------------------------------------------------------" << endl;
            do {
                p->mostrarDatos();
                p = p->next; //El nodo de recorrido avanza al siguiente nodo
            } while(p != NULL);
        } else {
            cout << "No existen procesos...";
        }
    }

    void eliminarProceso(int idProceso){
        node *p = this->first;
        //node *q;
        while(p->getIdProceso() != idProceso){
            p = p->next;
        }
        p->setTipo('h');
        p->setDesperdicio(0);
        p->setIdProceso(0);
    }

    int getLastNodeEnd(){
        if(this->first != NULL){
            node *p = this->first;
            node *q = p;
            while(p != NULL){
                p=p->next;
                if(p != NULL) q = p;
            }
            return q->fin;
        } else {
            return 0;
        }
    }

    node *getFinalNode(){
        node *p = this->first;
        node *o = p;
        while(p != NULL){
            o = p;
            p = p->getNext();
        }
        return o;
    }

    node *getFirstNode(){
        return this->first;
    }

    node *buscaNodoPorID(int id){
        node *p = this->first;
        while(p != NULL){
            if(p->getIdProceso() == id){
                return p;
            }
            p = p->getNext();
        }
    }

    void eliminar(int id){
        node *p, *q;
        bool wasIdFound = false;
        p = this->first;
        q = NULL;

        while(p != NULL && !wasIdFound){
            wasIdFound = (p->getIdProceso() == id);
            if(!wasIdFound){
                q = p;
                p = p->getNext();
            }
        }
        if(p != NULL){
            if(p == this->first){
                this->first = p->getNext();
            } else {
                q->setNext(p->getNext());
            }
            delete p;
        }
    }
};



#endif //PAGINACION_LIST_H
