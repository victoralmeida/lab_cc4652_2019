#include<iostream>
#include<cstdlib>
#include "no.h"
#include "lde.h"

using namespace std;


int main(int argc, char const *argv[]) {

  Lde <int>lista;
  lista.remove(70);
  //inserir valores
  lista.insere(10);
  lista.insere(113);
  lista.insere(80);
  lista.insere(81);

  //imprimir
  lista.imprime();

  //buscar - salva nó retornado em respostaBusca
  No<int>* respostaBusca = lista.busca(81);
  cout<<endl<<"Confere se busca funcionou: "<<respostaBusca->getValor()<<endl;

  //remover
  lista.remove(70);

  //imprime para conferir se valor foi removido
  cout<<endl<<"imprimindo após remoção:"<<endl<<endl;
  lista.imprime();




  return 0;
}
