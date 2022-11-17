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

  Ejercicio: Uso de la libreria list en C++
*/

#include<iostream>
#include<list>

using namespace std;

void test01(){
  list <string> nombres; // declaramos la lista

  // llenamos la lista
  nombres.push_back("Juan");
  nombres.push_back("Oscar");
  nombres.push_back("Samantha");
  nombres.push_back("Angela");
  nombres.push_back("Wilder");
  nombres.push_back("Carlos");
  nombres.push_back("Oscar");

  // definimos un iterador de la lista
  list<string>::iterator it = nombres.begin();

  // Operacion de remover elementos
  cout<<"Antes de remove"<<endl;

  // bucle para mostrar los elementos de la lista
  while (it!= nombres.end()) {
    cout<<"\t" << *it++<<endl;
  }
  cout<<endl;

  nombres.remove("Oscar");
  it = nombres.begin();
  cout<<"Despues del remove"<<endl;

  while (it!=nombres.end()) {
    cout<<"\t"<<*it++<<endl;
  }
  cout<<endl;
}

void test02(){
  // definimos nuevamente la lista
  list<string> nombres;

  nombres.push_back("Juan");
  nombres.push_back("Oscar");
  nombres.push_back("Samantha");
  nombres.push_back("Angela");
  nombres.push_back("Wilder");
  nombres.push_back("Carlos");
  nombres.push_back("Oscar");

  // definimos un iterador de la lista
  list<string>::iterator it = nombres.begin();

  // Operacion de remover elementos
  cout<<"Antes de erase"<<endl;

  // bucle para mostrar los elementos de la lista
  while (it!= nombres.end()) {
    cout<<"\t" << *it++<<endl;
  }
  cout<<endl;

  nombres.erase(nombres.begin());
  it = nombres.begin();
  cout<<"Despues del erase"<<endl;

  while (it!=nombres.end()) {
    cout<<"\t"<<*it++<<endl;
  }
  cout<<endl;
}

void test03(){
    // definimos nuevamente la lista
  list<string> nombres;

  nombres.push_back("Juan");
  nombres.push_back("Oscar");
  nombres.push_back("Samantha");
  nombres.push_back("Angela");
  nombres.push_back("Wilder");
  nombres.push_back("Carlos");
  nombres.push_back("Oscar");

  // definimos un iterador de la lista
  list<string>::iterator it = nombres.begin();

  // Operacion de remover elementos
  cout<<"Antes de erase"<<endl;

  // bucle para mostrar los elementos de la lista
  while (it!= nombres.end()) {
    cout<<"\t" << *it++<<endl;
  }
  cout<<endl;

  list<string>::iterator ini = nombres.begin();
  list<string>::iterator fin = nombres.end();
  ini++; ini++;
  fin--; fin--;

  nombres.erase(ini,fin);
  it = nombres.begin();
  cout<<"Despues del erase"<<endl;

  while (it!=nombres.end()) {
    cout<<"\t"<<*it++<<endl;
  }
  cout<<endl;
}

int main (int argc, char *argv[])
{
  test01(); test02(); test03();
  return 0;
}
