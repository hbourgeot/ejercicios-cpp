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

class Stack{
  public:
    Node *top = NULL;

    void add_top(int num);
    void delete_top();
    void print();
};

void Stack::add_top(int num){
  if (this->top==NULL){
    this->top = new Node(num, NULL);
    return;
  }

  Node *new_node = new Node(num, this->top);
  this->top = new_node;
}

void Stack::delete_top(){
  if (this->top==NULL){
    cout << "No hay algun elemento en la pila" << endl;
    return;
  }

  this->top = this->top->next;
}

void Stack::print(){
  cout << "Imprimiendo pila\n";
  Node *nodo_temp = this->top;
  while(nodo_temp!=NULL){
    cout << nodo_temp->number << "," << endl;
    nodo_temp = nodo_temp->next;
  }
}

void menu() {
  cout << "\n\t\tLista Enlazada Simple" << endl << endl;
  cout << "1. Apilar" << endl;
  cout << "2. Desapilar" << endl;
  cout << "3. Reportar pila" << endl;
  cout << "4. Salir" << endl;
  cout << "\nIngrese opcion: ";
}

int main(int argc, char *argv[]) {
  Stack *pila = new Stack();
  int op, _dato, pos;
  do {
    menu();
    cin >> op;
    switch (op) {
    case 1:
      cout << "\n\nNumero a insertar: ";
      cin >> _dato;
      pila->add_top(_dato);
      break;
    case 2:
      pila->delete_top();
      break;
    case 3:
      pila->print();
      system("pause");
      break;
    }
    system("cls");
  } while (op != 4);

  return 0;
}
