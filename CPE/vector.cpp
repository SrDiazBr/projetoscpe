#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>numbers;
    vector<int>::iterator ponteiro;
    numbers.push_back(100);
    numbers.push_back(101);
    numbers.push_back(102);
    cout << " nessa posição temos: "<< *ponteiro << endl;
    cout << "Removendo os elesmentos do vetor..." << endl;
    while(!numbers.empty()){
        cout << "Removendo o elemento: " << numbers.back() << endl;
        numbers.pop_back();
    }
    cout << "O tamanho do vetor agora e: " << numbers.size() << endl;
    return 0;
}
