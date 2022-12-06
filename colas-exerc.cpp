#include<iostream>
#include<cstdlib>
#include<string>
#include<stdio.h>

using namespace std;

struct datos{
  int dato;
  datos *s;
}*p,*aux,*u;

void insertar(int dat){
  aux = new(datos);
  aux->dato = dat;
  if (u){
    u->s=aux;
    aux->s= NULL;
    u=aux;
  } else{
    p=u=aux;
  }
  system("clear");
}

void borrar(){
  if(p){
    aux=p;
    cout<<"\nElimino a: "<<p->dato;
    p=aux->s;
    delete(aux);
  } else{
    cout<<"\nNo hay datos";
  }
}

void listar(){
  int i = 0;
  if(!u){
    cout<<"\nNo hay datos en la cola, no sea bruto";
    return;
  }

  aux = p;
  while(aux){
    cout<<"\n"<<++i<<"-"<<aux->dato;
    aux=aux->s;
  }
}

int main(){
  int op, y;

  do{
    cout<<"\n1. Insertar"<<endl;
    cout<<"\t2. Borrar"<<endl;
    cout<<"\t3. Listar"<<endl;
    cout<<"\t4. Salir"<<endl;
    cout<<"\t Ingrese su opcion: "; cin>>op;

    switch(op){
      case 1:
        cout<<"Ingresar dato: "; cin>>y;
        insertar(y);
        cout<<"\n\nDato insertado"<<endl;
        break;
      case 2: 
        borrar();
        break;
      case 3:
        listar();
        break;
      case 4:
        exit(0);
      default:
        cout<<"\n opcion no permitida"<<endl;
        break;
    }
  }while(op);

  return 0;
}
