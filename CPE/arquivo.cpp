#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string linha;
  ifstream meuarquivo("ntriangular.cpp"); 
  if (meuarquivo.is_open())
  {
    while (! meuarquivo.eof() ) 
    {
      getline (meuarquivo,linha);                              
      cout << linha << endl;
    }
    meuarquivo.close();
  }
  else cout << "Nao foi possivel abrir o aquivo !"; 
  return 0;
}
