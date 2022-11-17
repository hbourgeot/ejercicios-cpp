/*
========================================================================
*                                                                      *
*   #####  #### ##### #   # ####  # ##### #     # ####  ##### #     #  *
*   #     #       #   #   # #   # # #   # ##    # #   # #     #     #  *
*   #     #       #   #   # #   # # #   # # #   # #   # #     #     #  *
*   ###    ###    #   #   # #   # # ##### #  #  # #   # ###   #     #  *
*   #         #   #   #   # #   # # #   # #   # # #   # #      #   #   *
*   #         #   #   #   # #   # # #   # #    ## #   # #       # #    *
*   ##### ####    #    ###  ####  # #   # #     # ####  #####    #     *
*                                                                      *
========================================================================

  Ejercicio: Manipulando una lista enlazada simple
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

struct nodo{
  int nro;
  struct nodo *next;
};

typedef struct nodo *Tlista;

// funcion para insertar al inicio de la lista
void insertarIn(Tlista &lista, int valor){
  Tlista q = new(struct nodo); // definimos un nuevo nodo
  
  // asignamos valores a los elementos del nodo
  q->nro= valor;
  q->next= lista;
  lista = q;
}

// funcion para insertar al final de la lista
void insertarFi(Tlista &lista, int valor){
  Tlista t, q = new(struct nodo);

  // asignamos valores a los elementos del nodo
  q->nro = valor;
  q->next = NULL; //al establecer el puntero en NULL, se indica que ese es el último elemento de la lista

  if(lista==NULL) lista = q;
  else{
    t = lista;
    while(t->next!=NULL){
      t = t->next;
    }

    t->next = q;
  }
}

// funcion para insertar elementos antes o despues
int insertarAntDes(){
  int _op, band;
  cout<<endl;

  //menu para saber en que posicion insertar el elemento
  cout<<"\t1. Antes de la posicion"<<endl;
  cout<<"\t2. Despues de la posicion"<<endl;
  
  cout<<"\n\t Opcion: "; cin>>_op;

  if(_op==1) band = -1;
  else band = 0;

  return band;
}

//funcion para insertar elementos en una posicion dada.
void insertarElemento(Tlista &lista, int valor, int pos){
  Tlista q, t;
  int i;

  q = new(struct nodo);
  q->nro = valor;

  if(pos==1){
    q->next = NULL;
    lista = q;
  } else{
    int x = insertarAntDes();
    t = lista;

    for(i=1;t!=NULL;i++){
      if(i==pos+x){ // si se encuentra la posición buscada mas el valor retornado de la funcion
        q->next = t->next;
        t->next = q;
        return;
      }
      t = t->next;
    }
  }
  // si no se consigue la posición
  cout<<"Error... posicion no encontrada.."<<endl;
}

void buscarElemento(Tlista lista, int valor){
  Tlista q = lista;
  int i = 0; int band = 0;

  while(q!=NULL){
    if(q->nro==valor){ // si encontramos el valor esperado
      cout<<endl<<"Encontrada en la posicion "<<i<<endl;
      band = 1;
    }
    q = q->next;
    i++;
  }

  if(band==0)cout<<"\n\nNumero no encontrado"<<endl;
}

//funcion para imprimir la lista
void reportarLista(Tlista lista){
  int i = 0;

  while(lista!=NULL){
    cout<<" "<<i+1<<") "<<lista->nro<<endl;
    lista = lista->next;
    i++;
  }
}

// funcion para eliminar elementos
void eliminarElemento(Tlista &lista, int valor){
  Tlista p = lista, ant;

  if(lista!=NULL){
    while(p!=NULL){
      if(p->nro==valor)
        lista = lista->next;
      else
       ant->next=p->next;

      delete(p);
      return;
    }

    ant = p;
    p = p->next;
  } else 
    cout<<"Lista vacía"<<endl;
}

// funcion para eliminar elementos repetidos
void eliminarRepetidos(Tlista &lista, int valor){
  Tlista q, ant;
  q = lista;
  ant = lista;

  while(q!=NULL){
    if(q->nro==valor){
      if(q==lista){
      lista = lista->next;
      delete(q);
      q = lista;
      }else{
        ant->next = q->next;
        delete(q);
        q = ant->next;
      }
    } else{
      ant = q;
      q = q->next;
    }
  }

  cout<<"\n\nValores eliminados"<<endl;
}

void menu(){
  cout<<"\n\t\tLista Enlazada Simple"<<endl<<endl;
  cout<<"1. Insertar al inicio"<<endl;
  cout<<"2. Insertar al final"<<endl;
  cout<<"3. Insertar en una posicion..."<<endl;
  cout<<"4. Reportar lista"<<endl;
  cout<<"5. Buscar elemento 'V'"<<endl;
  cout<<"6. Eliminar elemento 'V'"<<endl;
  cout<<"7. Eliminar elementos con valor 'V'"<<endl;
  cout<<"8. Salir"<<endl;
  cout<<"\nIngrese opcion: ";
}

int main (int argc, char *argv[])
{
  Tlista lista = NULL;

  int op, _dato, pos;
  do{
    menu(); cin>>op;
    switch (op) {
  case 1:
    cout<<"\n\nNumero a insertar: "; cin>>_dato;
    insertarIn(lista, _dato);
    break;
  case 2:
    cout<<"\n\nNumero a insertar: "; cin>>_dato;
    insertarFi(lista, _dato);
    break;
  case 3:
    cout<<"\n\nNumero a insertar: "; cin>>_dato;
    cout<<"\nPosicion: "; cin>>pos;
    insertarElemento(lista, _dato, pos);
    break;
  case 4:
    cout<<"Mostrando lista:"<<endl;
    reportarLista(lista);
    break;
  case 5:
    cout<<"\n\nNumero a buscar: "; cin>>_dato;
    buscarElemento(lista, _dato);
    break;
  case 6:
    cout<<"\n\nNumero a eliminar: "; cin>>_dato;
    eliminarElemento(lista, _dato);
    break;
  case 7:
    cout<<"\n\nNumero repetido a eliminar: "; cin>>_dato;
    eliminarRepetidos(lista, _dato);
    break;
  }
  cout<<"\n\n";
  }while(op!=8);

  return 0;
}
