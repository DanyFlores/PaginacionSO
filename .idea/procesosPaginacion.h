//
// Created by dany- on 02/06/2017.
//

#ifndef PAGINACION_PROCESOSPAGINACION_H
#define PAGINACION_PROCESOSPAGINACION_H

#include <iostream>
#include "../list.h"

using namespace std;
class procesosPaginacion {
private:
    int tamMemoria, tamUAM, ID;
    list *lista;

public:
    procesosPaginacion(int tamMemoria, int tamUAM){
        this->tamMemoria = tamMemoria;
        this->tamUAM = tamUAM;
        this->ID = 0;
        lista = new list();
        lista->insertarAlFinal(getTamMemoria(), ID, 0, 0, getTamMemoria() / getTamUAM(), getTamMemoria() % getTamUAM() + 1, 'h');
    }

    bool isMemoryFull(){
        int contador = 0;
        node *p = lista->getFirstNode();
        while(p != NULL){
            if(p->getTipo() == 'p'){
                contador += p->getUAMs();
            }
            p = p->getNext();
        }
        return (getTamMemoria() / getTamUAM()) <= contador;
    }

    void creaProcesos(){
        int tamano, UAM = 0, memoriaDesperdiciada;
        cout << "Cuanta memoria ocupa el proceso?: ";
        cin >> tamano;
        while(tamano != 0 && !isMemoryFull()){
            UAM = tamano / getTamUAM();
            if(tamano % getTamUAM() > 0){
                UAM++;
                memoriaDesperdiciada = getTamUAM() - (tamano % getTamUAM());
            } else {
                memoriaDesperdiciada = 0;
            }
            if(pa_EncontrarHueco()->getuAM()>= UAM){
                node *p;
                int total = 0;
                lista->insertarAlInicio(tamano, ID, 0, tamano / getTamUAM(), UAM, memoriaDesperdiciada, 'p');
                p = lista->getFirstNode();
                while(p != NULL){
                    p->
                }
            }
        }
    }

    int getTamMemoria() const {
        return tamMemoria;
    }

    void setTamMemoria(int tamMemoria) {
        procesosPaginacion::tamMemoria = tamMemoria;
    }

    int getTamUAM() const {
        return tamUAM;
    }

    void setTamUAM(int tamUAM) {
        procesosPaginacion::tamUAM = tamUAM;
    }

    int getID() const {
        return ID;
    }

    void setID(int ID) {
        procesosPaginacion::ID = ID;
    }
};



#endif //PAGINACION_PROCESOSPAGINACION_H
