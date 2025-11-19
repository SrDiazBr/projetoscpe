#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    vector<string> palavras;
    vector<string>::iterator it;
    string palavra;
    while(true){
        cout << "Digite uma palavra (ou 'sair' para terminar): ";
        cin >> palavra;
        for(int i = 0; i < palavra.length(); i++){
            palavra[i] = tolower(palavra[i]);
        }
        if(palavra == "sair")
            break;
        palavras.push_back(palavra);
    }
    sort(palavras.begin(), palavras.end());
    cout << "Palavras em ordem alfabetica:" << endl;
    for(it = palavras.begin(); it != palavras.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}