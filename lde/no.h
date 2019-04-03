#ifndef NO_H
#define NO_H
#include<cstdlib>
using namespace std;

template <typename T> class No{
private:
  T valor;
  // No<T>* proximo;

public:
  No(int v):valor(v), proximo(NULL){}

  T getValor(){
    return valor;
  }

  void setValor(T valor){
    valor = valor;
  }

  // No<T>* getNo(){
  //   return proximo;
  // }

  No<T>* proximo;

};

#endif
