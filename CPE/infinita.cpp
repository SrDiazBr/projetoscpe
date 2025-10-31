#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // inicializa semente uma vez
    srand(static_cast<unsigned int>(time(nullptr)));
    long long tentativas = 0;
    while (true) {
        int quadrado[3][3];
        int numero ;
        for (int linha = 0; linha < 3; linha++) {
            for (int coluna = 0; coluna < 3; coluna++) {
                numero = rand() % 10 + 1;
                quadrado[linha][coluna] = numero;
            }
        }
        tentativas++;
        int somalinha[3]={0,0,0};
        int somacoluna[3]={0,0,0};
        int somadp=0;
        int somads=0;
        bool emagico = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                somalinha[i] += quadrado[i][j];
                somacoluna[j] += quadrado[i][j];
                if (i == j) {
                    somadp += quadrado[i][j];
                }
                if (i + j == 2) {
                    somads += quadrado[i][j];
                }
            }
        }

        // Verifica se todas as somas (linhas, colunas e diagonais) são iguais
        emagico = true;
        int referencia = somalinha[0];
        for (int k = 0; k < 3; k++) {
            if (somalinha[k] != referencia || somacoluna[k] != referencia) {
                emagico = false;
                break;
            }
        }
        if (emagico && somadp == referencia && somads == referencia) {
            cout << "Quadrado magico encontrado:\n";
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) cout << quadrado[r][c] << '\t';
                cout << '\n';
            }
            cout << "Soma: " << referencia << '\n';
            break; // sai do while
        }
        // caso contrario, repete gerando nova matriz
    }
    return 0;
}