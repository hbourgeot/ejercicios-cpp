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

class List{
  public:
    // Variable, es el primer nodo
    Node *head;

    List(){
      this->head = NULL; // se crea la lista apuntando a null, por lo que esta vacia
    }

    // Funciones a definir mas adelante
    void in_front(int number); // agrega al frente
    void in_back(int number); // agrega al final
    void at_position(int number, int pos); // agrega en una posicion especifica
    bool empty(); // verifica si el nodo está vacío
    void delete_node(int number); // borra un nodo
    void delete_nodes(int number); // borra nodos repetidos
    void get_node(int number); // obtiene un nodo
    void print(); // imprime la lista
};

// Funciones de la clase List
void List::in_front(int number){ // agregar al frente
  this->head = new Node(number, this->head);
}

void List::in_back(int number){ // agregar al final
  if (this->head == NULL){
    this->head = new Node(number, NULL);
    return;
  }

  Node *now = this->head;
  while(now->next)
    now = now->next;

  now->next = new Node(number, NULL);
}

void List::at_position(int number, int pos){ // agrega elementos en una posicion dada
  Node *node = new Node(number, NULL);

  int _op, band, i;
  cout << endl;

  // menu para saber en que posicion insertar el elemento
  cout << "1. Antes de la posicion" << endl;
  cout << "2. Despues de la posicion" << endl;

  cout << "\nOpcion: ";
  cin >> _op;

  if (_op == 1)
    band = -1;
  else
    band = 0;

  if(pos!=1){
    Node *lastNode = this->head;
    for (i = 1; lastNode != NULL; i++){
      if(i == pos + band){
        node->next = lastNode->next;
        lastNode->next = node;
        return;
      }
      lastNode = lastNode->next;
    }
  }

  cout << "Error... no se pudo encontrar la posicion deseada." << endl;
}

bool List::empty(){ // revisa si la lista esta vacia
  return this->head == NULL;
}

void List::delete_node(int number_del){
  if(this->empty()){
    cout << "Lista vacia!!" << endl
        << endl;
    return;
  }

  Node *now = this->head, *prev;

  while (now && now->number != number_del){
    prev = now;
    now = now->next;
  }
  
  if(prev==NULL)
    this->head = now->next;
  else if (now){
    prev->next = now->next;
    now->next = NULL;
  }
} 

void List::delete_nodes(int number_dup){
  if(this->empty()){
    cout << "Lista vacia!!" << endl
        << endl;
    return;
  }
  Node *current_node = this->head, *prev = this->head;

  while (current_node != NULL){
    if(current_node->number == number_dup){
      if (current_node==this->head){
        this->head = this->head->next;
        delete(current_node);
        current_node = this->head;
      } else{
        prev->next = current_node->next;
        delete (current_node);
        current_node = prev->next;
      }
    } else{
      prev = current_node;
      current_node = current_node->next;
    }
  }
  cout << "\n\nValores eliminados" << endl;
}

void List::get_node(int search){
  if(this->empty()){
    cout << "Lista vacia!!" << endl
        << endl;
    return;
  }
  
  Node *current_node = this->head;
  int i = 0, band = 0;

  while (current_node!=NULL){
    if(current_node->number == search){
      cout << "Encontrada en la posicion " << i << endl;
      band = 1;
    }
    current_node = current_node->next;
    i++;
  }
  if(band==0)
    cout << "\n\nNumero no encontrado" << endl;
}

void List::print(){
  Node *node = this->head;
  for (int i = 1; node != NULL; i++){
    cout << i << ") " << node->number << endl;
    node = node->next;
  }
}

void menu() {
  cout << "\n\t\tLista Enlazada Simple" << endl << endl;
  cout << "1. Insertar al inicio" << endl;
  cout << "2. Insertar al final" << endl;
  cout << "3. Insertar en una posicion..." << endl;
  cout << "4. Reportar lista" << endl;
  cout << "5. Buscar elemento 'V'" << endl;
  cout << "6. Eliminar elemento 'V'" << endl;
  cout << "7. Eliminar elementos con valor 'V'" << endl;
  cout << "8. Salir" << endl;
  cout << "\nIngrese opcion: ";
}

int main(int argc, char *argv[]) {
  List *lista = new List();
  int op, _dato, pos;
  do {
    menu();
    cin >> op;
    switch (op) {
    case 1:
      cout << "\n\nNumero a insertar: ";
      cin >> _dato;
      lista->in_front(_dato);
      break;
    case 2:
      cout << "\n\nNumero a insertar: ";
      cin >> _dato;
      lista->in_back(_dato);
      break;
    case 3:
      cout << "\n\nNumero a insertar: ";
      cin >> _dato;
      cout << "\nPosicion: ";
      cin >> pos;
      lista->at_position(_dato, pos);
      break;
    case 4:
      cout << "Mostrando lista:" << endl;
      lista->print();
      system("pause");
      break;
    case 5:
      cout << "\n\nNumero a buscar: ";
      cin >> _dato;
      lista->get_node(_dato);
      system("pause");
      break;
    case 6:
      cout << "\n\nNumero a eliminar: ";
      cin >> _dato;
      lista->delete_node(_dato);
      break;
    case 7:
      cout << "\n\nNumero repetido a eliminar: ";
      cin >> _dato;
      lista->delete_nodes(_dato);
      system("pause");
      break;
    }
    system("cls");
  } while (op != 8);

  return 0;
}
