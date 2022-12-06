#include<iostream>
#include<stdlib.h>

using namespace std;

class Vector{
  int vector[50];

public:
  Vector();

  void entrarDato(int valor, int pos){
    vector[pos]=valor;
  }

  int verDato(int pos){
    return vector[pos];
  }

  void mostrarVector();
};

Vector::Vector(){
  for(int i=0;i<50;i++)
    vector[i] = -1;
}

void Vector::mostrarVector(){
  for(int i=0;i<50;i++){
    cout<<"Vector["<<i<<"] = "<<vector[i]<<endl<<endl;
  }
}

int main(){

  // declaramos objeto de la clase
  Vector vector;

  // ingresamos datos
  vector.entrarDato(345, 45);
  vector.entrarDato(23, 47);
  vector.entrarDato(5, 35);
  vector.entrarDato(8, 38);
  vector.entrarDato(10, 39);
  vector.entrarDato(23, 40);

  // mostramos el vector
  vector.mostrarVector();
  for(int i=0;i<15;i++) cout<<"*";
      cout<<endl<<"Posicion 23:"<<vector.verDato(23)<<endl;
  return 0;
}
