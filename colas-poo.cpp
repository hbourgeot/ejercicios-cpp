#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
  public:
    int number; // dato
    Node *next; // puntero

    Node(int data, Node *next){ // construye un nodo
      this->number = data; // asignamos los valores recibidos
      this->next = next;
    }
};

class Queue{
  public:
    Node *first;
    Node *last;

    void insert(int num);
    void del();
    void print();
};

void Queue::insert(int num){
  Node *new_node = new Node(num, NULL);
  if(this->last){
    this->last->next = new_node;
    this->last = new_node;
  } else{
    this->first = this->last = new_node;
  }
  system("cls");
}

void Queue::del(){
  if(this->first){
    Node *new_node = this->first;
    cout << "Eliminando a: " << new_node->number;
    this->first = new_node->next;
    delete (new_node);
  }else{
    cout << "\nNo hay datos";
  }
}

void Queue::print(){
  if (!this->last){
    cout << "No hay datos" << endl;
    return;
  }

  Node *node_temp = this->first;
  for (int i = 0; node_temp; ++i)
  {
    cout << "\n"
         << i << "- " << node_temp->number;
    node_temp = node_temp->next;
  }
}

int main(){
  int op, y;
  Queue *cola = new Queue();
  Queue *cola2 = new Queue();

  do{
    cout<<"\n1. Insertar"<<endl;
    cout<<"\t2. Borrar"<<endl;
    cout<<"\t3. Listar"<<endl;
    cout<<"\t4. Salir"<<endl;
    cout<<"\t Ingrese su opcion: "; cin>>op;

    switch(op){
      case 1:
        cout<<"Ingresar dato: "; cin>>y;
        cola->insert(y);
        cola2->insert(y * 2);
        cout<<"\n\nDato insertado"<<endl;
        break;
      case 2:
        cola->del();
        cola2->del();
        break;
      case 3:
        cola->print();
        cola2->print();
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
