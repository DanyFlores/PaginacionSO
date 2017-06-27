#include <iostream>
#include <cstdlib>
#include "list.h"
#include "procesosPaginacion.h"

using namespace std;
int main() {
    int tamanoMemoria, tamanoUAM, opcion, procesoT, tamano;
    cout << "tamano de la memoria: ";
    cin >> tamanoMemoria;
    cout << "tamano de la UAM: ";
    cin >> tamanoUAM;
    procesosPaginacion *pP = new procesosPaginacion (tamanoMemoria, tamanoUAM);
    cout << "**** Para terminal la creacion de la lista ****" << endl
         << "**** y todos los demas procedimientos escriba -1 ****" << endl;
    pP->crearLista();
    cout << "Procesos creados de forma satisfactoria" << endl;
    cout << "La Lista:" << endl;
    pP->l->recorreLista();
    do {
        cout << "Introduce una opcion: "
             << endl;
        cout << "1.- Mostrar Lista" << endl;
        cout << "2.- Terminar Procesos" << endl;
        cout << "* Metodos de asignacion de memoria *" << endl;
        cout << "3.- Primer Ajuste" << endl;
        cout << "4.- Siguiente Ajuste" << endl;
        cout << "5.- Mejor Ajuste" << endl;
        cout << "6.- Peor Ajuste" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "La Lista:" << endl;
                pP->l->recorreLista();
                break;
            case 2:
                do {
                    cout << "Introduce el ID del proceso a terminar: ";
                    cin >> procesoT;
                    pP->terminarProceso(procesoT);
                    pP->l->recorreLista();
                } while (procesoT != -1);
                break;
            case 3:
                do {
                    cout << "Introduce el tamano del proceso:" << endl;
                    cin >> tamano;
                    pP->PrimerAjuste(tamano);
                } while (tamano != -1);
                break;
            case 4:
                do {
                    cout << "Introduce el tamaño del proceso:" << endl;
                    cin >> tamano;
                    pP->siguienteAjuste(tamano);
                } while (tamano != -1);
                break;
            case 5:
                do {
                    cout << "Introduce el tamaño del proceso:" << endl;
                    cin >> tamano;
                    pP->mejorAjuste(tamano);
                } while (tamano != -1);
                break;
            case 6:
                do {
                    cout << "Introduce el tamaño del proceso:" << endl;
                    cin >> tamano;
                    pP->peorAjuste(tamano);
                } while (tamano != -1);
                break;
        }
    } while ((opcion < 7) & (opcion > 0));
}
/*#include <iostream>
#include <stdlib.h>
#include "list.h"

using namespace std;

int id = 0, tamUAM = 0, tamMemoria = 0, memoriaUsada = 0;
list * lista;
void imprimeMenu(){
    cout << ".:Administracion de memoria:." << endl
         << "�Que metodo quiere utilizar: " << endl
         << "1.-Primer ajuste" << endl
         << "2.-Siguiente ajuste" << endl
         << "3.-Mejor ajuste" << endl
         << "4.-Peor ajuste" << endl
         << "5.-Salir" << endl
         << "Elige una opci�n: ";
}
//M�todo para insertar procesos en las distintas listas creadas
void crearProcesosPrimerAjuste(){
    char sel;
    int cantidadMemoria; //Variables para almacenar los datos a insertar en los nodos
    lista = new list; //Declaraci�n de la lista a utilizar
    cout << endl << "Creacion de procesos" << endl;
    do {
        cout << endl << "Inserte cantidad de memoria requerida por el proceso (en Kb): ";
        cin >> cantidadMemoria; //Almacena el tiempo del proceso
        id++;
        int usado = cantidadMemoria;
        if(usado < tamUAM){
            usado = 1;
        } else if(usado % tamUAM != 0){
            usado = usado / tamUAM + 1;
        } else {
            usado /= tamUAM;
        }
        lista->insertarAlFinal(cantidadMemoria, id, lista->getLastNodeEnd(), lista->getLastNodeEnd() + usado, usado, usado * tamUAM - cantidadMemoria, 'p'); //Crea un nuevo nodo, insertando los datos almacenados previamente
        cout << "Continuar agregando procesos? (s/n): "; //Pregunta si se desea continuar agregando nodos (procesos) a la lista
        cin >> sel;
    } while(sel != 'n');
    memoriaUsada = lista->getLastNodeEnd() * tamUAM;
    //cout << memoriaUsada << endl << tamMemoria << "Memoria disponible: " << tamMemoria - memoriaUsada << endl << "Memoria ocupada: " << memoriaUsada;
    lista->insertarAlFinal(0, 000, lista->getLastNodeEnd(), lista->getLastNodeEnd() + ((tamMemoria - memoriaUsada)/tamUAM), (tamMemoria - memoriaUsada) / tamUAM, 0, 'h');
    lista->eliminarProceso(2);
    lista->imprimir(); //Imprime la lista de procesos despu�s de finalizar la captura

}

int main(){
    int opc;
    cout << "Que tamano de memoria (en Kb) requiere cada UAM?: ";
    cin >> tamUAM; //Almacena el tiempo del proceso
    cout << "Que tamano tiene la memoria en total (en Kb)?:";
    cin >> tamMemoria;
    do {
        imprimeMenu(); //Imprime el men� de opciones
        cin >> opc; //Almacena la opci�n deseada
        switch(opc){ //Comienza la ejecuci�n del men� de acuerdo a la opci�n seleccionada
            case 1: crearProcesosPrimerAjuste(); break; //Comienza la captura de procesos
            case 2: crearProcesosPrimerAjuste(); break;
            case 3: crearProcesosPrimerAjuste(); break;
            case 4: crearProcesosPrimerAjuste(); break;
            case 5: cout << "Saliendo..." << endl; break; //Termina la ejecuci�n del programa, adem�s de eliminar las listas utilizadas para limpiar la memoria
            default: cout << "Opci�n no v�lida, intente de nuevo"; break; //De seleccionar una opci�n no v�lida, imprime un mensaje indicando que no es una opci�n v�lida
        }
    } while(opc != 5);
    return 0;
}*/