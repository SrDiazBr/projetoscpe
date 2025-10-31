#include <iostream>
using namespace std;
int main() {
    char tabuleiro[3][3] = {{ ' ',' ',' '}}; {{' ',' ',' '}}; {{' ',' ',' '}}; 
    while (true) {
        system("cls");
        // Exixibir o tabuleiro
        cout << "********** Jogo da Velha **********" << endl;
        for(int i = 0; i<3; i++){
            for ( int j =0 ;j<3;j++){
                cout << "[" << tabuleiro[i][j] << "]" << "\t";
            }
            cout << endl;
        }
    }
}