#include<cstdlib>
#include "no.h"
using namespace std;


template <typename T>
class Lde{
private:
  No<T> *primeiro;

public:
  Lde():primeiro(NULL){}

  ~Lde(){
    No<T>* a = primeiro;
    No<T>* b = NULL;

    int n=0;
    while(a){
      b=a->proximo;
      delete a;
      a=b;
      cout<<"Destói "<<n<<endl;
      n++;
    }
  }

  bool insere(T valor){
      No<T>* novo = new No<T>(valor);

      if(!novo){
        cout<<"Não foi possível criar o Nó"<<endl;
        return false;
        }

      No<T>* anterior = NULL;
      No<T>* atual = primeiro;

      while(atual!=NULL && atual->getValor() < novo->getValor() ){
        anterior = atual;
        atual = atual->proximo;
      }

      if(anterior)
        anterior->proximo = novo;
      else
        primeiro = novo;

      novo->proximo = atual;
      return true;
  }

  void imprime(){
    No<T>* a = primeiro;
    while(a){
      cout<<a->getValor()<<endl;
      a=a->proximo;
    }
  }

  No<T>* busca(T valor){

    No<T>* a=primeiro;
    while(a && a->getValor()<=valor){
      if(a->getValor()==valor)
        return a;
      a=a->proximo;
    }

    a = new No<T>(-1);
    return a;

  }

  bool remove(T valor){
    bool cond=false;

    No<T>* anterior = NULL;
    No<T>* atual=primeiro;

    if(atual->getValor() == valor){
      primeiro = atual->proximo;
      delete atual;//Destói No removido da lista
    }

    while(atual && atual->getValor()<=valor){
      if(atual->getValor()==valor){
        cond=true;
        break;
      }
      anterior = atual;
      atual=atual->proximo;
    }

    if(cond){
      anterior->proximo = atual->proximo;
      delete atual; //Destói No removido da lista
      return true;
    }else{
      cout<<endl<<"Função remoção: valor "<<valor<< " não encontrado"<<endl;
      return false;
    }

  }


};
