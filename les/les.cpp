#include<iostream>
using namespace std;


template <typename T>
class Vetor{
  private:
    int size;
    int capacity;
    T *buffer;

  public:
    Vetor(int capacity):capacity(capacity), size(0), buffer(new T[capacity]){}
    ~Vetor(){
      delete []buffer;
    }

    void ajusta(int novaCap){
      T *espelho = new T[novaCap];

      for(int i = 0; i<capacity; i++)
        espelho[i] = buffer [i];

      delete []buffer;
      buffer = espelho;
      capacity = novaCap;

    }

    void setItem(T item){
      if(size == capacity)
        ajusta(capacity+1);

      buffer[size] = item;
      size++;
    }

    T &getItem(int idx){
      if(size<idx)
        ajusta(idx+1);
      return buffer[idx];
    }

    T &operator[](int idx){
      return getItem(idx);
    }


};


int main(int argc, char const *argv[]) {

  Vetor<int> v(1);

  //Entradas
  v.setItem(10);
  v.getItem(8) = 121;
  v[5] = 1997;

  //Saídas
  cout<<v.getItem(0)<<endl;
  cout<<v.getItem(8)<<endl;
  cout<<v[5]<<endl;

  return 0;
}
