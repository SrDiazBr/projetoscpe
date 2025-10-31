#include<iostream>
using namespace std;
int main(){
    unsigned int codproduto[1000];
    string nomeproduto[1000];
    int i=0;
    while(true){
        cout<<"******* MENU *******"<< endl;
        cout<<"1 Cadastre o produto"<< endl;
        cout<<"2 Procurar produto"<< endl;
        cout<<"3 Apagar produto"<< endl;
        cout<<"4 Listar produtos"<< endl;
        cout<<"5 Sair"<< endl;
        cout<<"Digite a opcao desejada: "<< endl;
        int opcao = 0;
        cin>>opcao;
        switch(opcao) {
            case 1:
                cout<<"Cadastrar o produto"<<endl;
                cout<<"--------------------"<<endl;
                cout<<"codigo do produto: "<<endl;
                cin>>codproduto[i];
                cout<<"nome do produto: "<<endl;
                cin>>nomeproduto[i];
                i++;
                break;
            case 2:
                cout << "Procurar produto"<<endl;
                int cod_produto;
                cout<<"Digite o codigo do produto que deseja procurar: "<<endl;
                cin>>cod_produto;
                for (int j=0;j<i;j++){
                    if (codproduto[j]==cod_produto){
                        cout<<"Produto encontrado!"<<endl;
                        cout<<"Codigo: "<<codproduto[j]<<endl;
                        cout<<"Nome: "<<nomeproduto[j]<<endl;
                    }
                    else {
                        cout<<"Produto nao encontrado!"<<endl;
                    }
                }
                // Aqui pode adicionar lógica de busca se quiser
                break;
            case 3:
                cout << "Apagar produto"<<endl;
                int apaga;
                cout<<"Digite o codigo do produto que deseja apagar: "<<endl;
                cin>>apaga;
                for ( int j=0;j<i;j++){
                    if(apaga==codproduto[j]){
                        cout<<"Produto apagado!"<<endl;
                        // Lógica simples para "apagar" o produto
                        codproduto[j]=0;
                        nomeproduto[j]="";
                    }
                    
                }
                // Aqui pode adicionar lógica de apagar se quiser
                break;
            case 4:
                cout << "Listar produtos"<<endl;
                for(int j=0;j<i;j++){
                    cout<<"Codigo: "<<codproduto[j]<<endl<<" Nome: "<<nomeproduto[j]<<endl;
                    cout<<"-----------------------"<<endl;
                }
                break;
            case 5:
                cout << "Saindo do programa..."<<endl;
                return 0;
            default:
                cout << "Opcao invalida!" << endl;
        }
    }
}