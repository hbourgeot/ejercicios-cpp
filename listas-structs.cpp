#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{ // Nodo de la lista
  int numero;
  nodo *next;
};

typedef struct nodo *Lista; //Typedef Se utiliza para renombrar elementos

void insertar_al_inicio(Lista &lista){ //Void no retorna ningun valor
  cout << lista;
} 