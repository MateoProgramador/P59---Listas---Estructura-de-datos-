#include <iostream>
using namespace std;
struct Nodo{
    int dato;
    Nodo *siguiente;
};

void insertarNodo(Nodo *&primero, Nodo *&ultimo, int dato){
    Nodo *nuevoNodo= new Nodo(); //nodo
    nuevoNodo->dato=dato;
    if(primero==NULL){
        primero=nuevoNodo;
        primero->siguiente=nuevoNodo;
        ultimo=primero;
    }else{
        ultimo->siguiente=nuevoNodo;
        nuevoNodo->siguiente=primero;
        ultimo=nuevoNodo;
    }
    cout<<"\n"<<dato<<"Dato ingresado\n";
};
void mostrarLista(Nodo *primero){
    Nodo *actual= new Nodo();
    actual=primero;
    if (primero!=NULL){
        do{
            cout<<actual->dato<<" ";
            actual= actual->siguiente;
        }while(actual!=primero);
    }else{
        cout<<"\nLista vacia\n";
    }

};

void buscarNodo(Nodo *primero, int datoBuscado){
    Nodo *actual= new Nodo();
    actual=primero;
    int encontrado=0;
    if (primero!=NULL){
        do{
            if (actual->dato==datoBuscado){
                cout<<"\n"<<datoBuscado<<" encontrado\n";
                encontrado=1;
            }
            actual=actual->siguiente;
        }while(actual!=primero && encontrado!=1);
        if (encontrado==0){
            cout<<"\n"<<datoBuscado<<" no encontrado\n";
        }
    }else{
        cout<<"\nlista vacia\n";
    }
};

void buscarNodo2(Nodo *primero, int datoBuscar){
    Nodo *actual = primero;
    bool flag = false;
    if(primero == NULL){
        cout<<"\nLa lista esta vacia"<<endl;
    }else{
        do{
            if(actual->dato==datoBuscar){
                flag=true;
            }
            actual = actual->siguiente;
        }while(actual!=primero && flag!=true);
    }

    if(flag){
        cout<<"Dato encontrado ["<<datoBuscar<<"]"<<endl;
    }else{
        cout<<"Dato No encontrado ["<<datoBuscar<<"]"<<endl;
    }
}
void reemplazarNodo(Nodo *&primero, int dr, int dn){
    Nodo *actual = new Nodo();
    actual = primero;
    bool flag = false;
    if(primero == NULL){
        cout<<"\nLa lista esta vacia"<<endl;
    }else{
        do{
            if(actual->dato==dr){
                actual->dato = dn;
                cout<<"Dato reemplazado con exito!"<<endl;
                flag=true;
            }
            actual = actual->siguiente;
        }while(actual!=primero && flag!=true);

        if(!flag){
            cout<<"Dato No encontrado dentro de la lista ["<<dr<<"]"<<endl;
        }
    }
}
//       primero=7         ultimo=3    nuevoNodo=3  actual=
//       7->2->3->primero
//
// 7,2,3
// buscar
int main()
{
    cout <<"\n--TEST 2-RAMIREZ MATEO--\n" << endl;
    Nodo *primero=NULL;
    Nodo *ultimo=NULL;
    int op, dato, nuevodato,datoBuscar,dn;
    do{
        cout<<"\n1.- Ingreso de datos\n";
        cout<<"2.- Mostrar datos\n";
        cout<<"3.- Buscar dato\n";
        cout<<"4.- Reemplazar dato\n";
        cout<<"5.- salir\n";
        cout<<"Ingresa la opcion:\n";
        cin>>op;
        switch (op) {
            case 1: cout<<"\n ingreso de información\n";
                    cout<<"ingrse el dato\n";
                    cin>>dato;
                    insertarNodo(primero, ultimo, dato);
                    break;
            case 2: cout<<"\ndatos Ingresados\n";
                    mostrarLista(primero);
                    break;
            case 3: cout<<"\nBuscar dato en la lista\n";
                    cout<<"Ingrese el dato a buscar\n";
                    cin>>dato;
                    buscarNodo2(primero,dato);
                    break;
            case 4: cout<<"\nReemplazar datos\n";
                    cout <<"\nIngrese el dato a remplazar\n";
                    cin >> datoBuscar;
                    cout <<"\nIngrese el nuevo dato\n";
                    cin>>dn;

                    reemplazarNodo(primero,datoBuscar,dn);


            break;
            case 5:
            break;
            default: cout<<"\n    Error....!!!";
                     break;
        }
    }while(op!=5);
    cout <<endl;
    return 0;
}
