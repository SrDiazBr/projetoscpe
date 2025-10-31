#include <iostream>
using namespace std;
int main() {
    cout << "Digite a ordem da matriz quadrada : ";
    int n;
    cin >> n;
    int matriz[n][n];
    int linha, coluna;
    for (int linha = 0; linha < n; linha++) {
        for (int coluna = 0; coluna < n; coluna++) {
            cout << "Digite o valor para a posicao [" << linha << "][" << coluna << "]: ";
            cin >> matriz[linha][coluna];
        }
    }
    for (int linha = 0; linha < n; linha++) {
        for (int coluna = 0; coluna < n; coluna++) {
            cout << "Digite o valor para a posicao [" << linha << "][" << coluna << "]: "<<endl;
            cout << matriz[linha][coluna]<<endl;
        }
    }
    int somap=0,somas=0;
    for (int linha = 0; linha < n; linha++) {
        for (int coluna = 0; coluna < n; coluna++) {
            if(linha==coluna)
                somap+=matriz[linha][coluna];
            if (linha+coluna==n-1) 
                somas+=matriz[linha][coluna];               
        }
    }
    cout<<"Soma da diagonal principal: "<<somap<<endl;
    cout<<"Valor da diagonal secundaria: "<<somas<<endl;
    return 0;
}