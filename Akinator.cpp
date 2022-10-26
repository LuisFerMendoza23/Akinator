//#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Nodo{ //Parametros de cada uno de los nodos
public: //Se pueden usar en otras clases 
    string dato;
    Nodo *izq = nullptr;
    Nodo *der = nullptr;
    //Destructor
    ~Nodo(){
        delete izq;
        delete der;
    }
};
//
class Arbol{ 
public:  //parametros para otras clases
    //ATRIBUTOS
    Nodo *raiz; //apunta a vacio 
    char pregunta[40];  
    char respuesta[40];
    string respAux;
    int resp_PR;
    int loop;

    Arbol(){
        raiz= NULL;
        insertarNodos("Estas pensando en GODKU", raiz); //Queremos que se inicialize primero la raiz
    }
    ~Arbol(){
        delete raiz;
    }

    //METOOS
    Nodo *crearNodos(string PregResp){ //son esos parametros por que se modifican y pasan al programa
        Nodo *nuevo_nodo = new Nodo(); //crea un nodo
        nuevo_nodo->dato = PregResp; //donde se guardan las Preg o Resp
        nuevo_nodo->izq = NULL; //no apunta a nada
        nuevo_nodo->der = NULL;
        return nuevo_nodo;
    }
    
    Nodo *insertarNodos(string PregResp, Nodo *&arbol){  //El amperson lo ocupo para que ahi se almacene la raiz y de ahi empiece 
        //Creamos el nodo raiz
            Nodo *nuevo_nodo = crearNodos(PregResp);
            arbol = nuevo_nodo; //Se crea la raiz en la direccion del arbol
            preguntas(arbol);
    }

    void preguntas(Nodo *&arbol){ //Recibe la ubicacion 
        if(arbol->izq == NULL && arbol->der == NULL){ //Si son hojas (ultimos) 
            system("cls");
            cout<<arbol->dato<<"?  o.O "<<endl;
            cout<<"1)SI\t2)NO"<<endl;
            cin>>resp_PR;
            cout<<endl;

            if(resp_PR == 1){ //SI Y ES HOJA
                cout<<"Genial lo adivine!!\n"<<endl;
                cout<<"Deseas jugar de nuevo[reiniciar] ?\n"<<endl;
                cout<<"1)Si   2)No"<<endl;
                cin>>loop;

                if(loop == 1){ //Se debe de reiniciar con los valores ingresados
                    //Si se reinicia, debe de mostrar desde primera respuesta
                    //Arbol *a = new Arbol();
                    preguntas(raiz);
                }
                else{
                    cout<<"\nGracias por probar el juego :DD"<<endl;
                    system("pause");
                    cout<<"\nRecuerda adelantar las cosas que puedas y no dejar"<<endl;
                    cout<<"Todo para el ultimo como tu servidor."<<endl;
                    cout<<endl;
                    cout<<"\nBy: LUIS MENDOZA"<<endl;
                }

            }

            else{ //No [Logica de preguntar en que estas pensando, diferencia y logica de agregar]
                cout<<"Rayos!! pense que ya lo tenia... >:("<<endl;
                //cout<<"\nQue tiene de diferencia o.o?"<<endl;
                cout<<"-->Ingresa la pregunta caracteristica?: "<<endl; //Pregunta
                fflush(stdin);
                cin.getline(pregunta, 40);
                cout<<"-->Ingresa la respuesta: "<<endl; //Respuesta
                fflush(stdin);
                cin.getline(respuesta,40);

                string respAux = arbol->dato;
                Nodo *nodoDer = crearNodos(respuesta);
                arbol->der = nodoDer; //se crea el nodo a la izquierda

                arbol->dato = pregunta;

                Nodo *nodoIzq = crearNodos(respAux);
                arbol->izq = nodoIzq; //Se crea el nodo a la derechaa
                preguntas(raiz); //pasamos a la siguiente funcion, hace recursividad

                //Mensajes para probar que si nos funcionan las variables
                // std::cout << "\narbol izq" << arbol->izq->dato << std::endl;
                // std::cout << "\narbol der" << arbol->der->dato << std::endl;
                // std::cout << "\narbol dato\n" << arbol->dato << std::endl;
                //system("pause");         
            }

        }
        else{ //AQUI DETECTA SI ES UNA RAMA
            system("cls");
            cout<<arbol->dato<<endl;
            cout<<"1)SI\t2)NO"<<endl;
            cin>>resp_PR; 
            cout<<endl;

            if(resp_PR == 1){ //SI
                preguntas(arbol->der); //DERECHA ->> SI
            }
            else{ //NO
                preguntas(arbol->izq); //IZQUIERDA ->>NO
            }
        }
    }
};

int main()
{
    cout<<"\t.:AK_INATOR:."<<endl;
    //Manera diferente de instanciar el objeto
    //llama al constructor
    Arbol *a = new Arbol();
    return 0;
}