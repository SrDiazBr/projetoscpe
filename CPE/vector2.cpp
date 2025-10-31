#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>numbers;
    vector<int>::iterator ponteiro;

    for (int i = 0; i < 5; i++)
        numbers.push_back(i);
    ponteiro = numbers.begin();
    ++ponteiro;
    cout << " nessa posicao temos: "<< *ponteiro << endl;
    
    return 0;
}