// Sistema simples de cadastro de Clientes e controle de Pedidos (relação 1:N)
// Arquivo: cliente_pedido.cpp
// Compilar: g++ -std=c++17 cliente_pedido.cpp -o cliente_pedido.exe






// O  RAFAEL , vc tá no meu repositorio meu mano , fica de olho nisso aí em, pra n








#include <bits/stdc++.h>
using namespace std;

struct Cliente {
    int id;
    string nome;
    string email;
    string telefone;
};

struct Pedido {
    int id;
    int clienteId;
    string descricao;
    double valor;
    string status; // ex: Pendente, Enviado, Concluido
};

vector<Cliente> clientes;
vector<Pedido> pedidos;
int nextClienteId = 1;
int nextPedidoId = 1;

string trim(const string &s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a==string::npos) return string();
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b-a+1);
}

void saveClients(const string &filename="clients.csv"){
    ofstream f(filename);
    if(!f){ cout<<"Erro ao abrir "<<filename<<" para salvar clientes\n"; return; }
    for(auto &c: clientes){
        // id;nome;email;telefone
        f<<c.id<<";"<<c.nome<<";"<<c.email<<";"<<c.telefone<<"\n";
    }
    cout<<"Clientes salvos em "<<filename<<"\n";
}

void savePedidos(const string &filename="pedidos.csv"){
    ofstream f(filename);
    if(!f){ cout<<"Erro ao abrir "<<filename<<" para salvar pedidos\n"; return; }
    for(auto &p: pedidos){
        // id;clienteId;descricao;valor;status
        // substituir possíveis quebras de linha e ponto-e-virgula na descricao é além do escopo simples
        f<<p.id<<";"<<p.clienteId<<";"<<p.descricao<<";"<<p.valor<<";"<<p.status<<"\n";
    }
    cout<<"Pedidos salvos em "<<filename<<"\n";
}

vector<string> split(const string &s, char delim){
    vector<string> out; string cur;
    stringstream ss(s);
    while(getline(ss, cur, delim)) out.push_back(cur);
    return out;
}

void loadClients(const string &filename="clients.csv"){
    ifstream f(filename);
    if(!f){ cout<<"Arquivo "<<filename<<" não encontrado (nenhum cliente carregado).\n"; return; }
    clientes.clear();
    string line;
    int maxid = 0;
    while(getline(f, line)){
        if(line.empty()) continue;
        auto parts = split(line, ';');
        if(parts.size() < 4) continue;
        Cliente c;
        try{ c.id = stoi(trim(parts[0])); } catch(...) { c.id = 0; }
        c.nome = trim(parts[1]);
        c.email = trim(parts[2]);
        c.telefone = trim(parts[3]);
        clientes.push_back(c);
        if(c.id > maxid) maxid = c.id;
    }
    nextClienteId = maxid + 1;
    cout<<"Carregados "<<clientes.size()<<" clientes (next id="<<nextClienteId<<")\n";
}

void loadPedidos(const string &filename="pedidos.csv"){
    ifstream f(filename);
    if(!f){ cout<<"Arquivo "<<filename<<" não encontrado (nenhum pedido carregado).\n"; return; }
    pedidos.clear();
    string line; int maxid = 0;
    while(getline(f, line)){
        if(line.empty()) continue;
        auto parts = split(line, ';');
        if(parts.size() < 5) continue;
        Pedido p;
        try{ p.id = stoi(trim(parts[0])); } catch(...) { p.id = 0; }
        try{ p.clienteId = stoi(trim(parts[1])); } catch(...) { p.clienteId = 0; }
        p.descricao = trim(parts[2]);
        try{ p.valor = stod(trim(parts[3])); } catch(...) { p.valor = 0.0; }
        p.status = trim(parts[4]);
        pedidos.push_back(p);
        if(p.id > maxid) maxid = p.id;
    }
    nextPedidoId = maxid + 1;
    cout<<"Carregados "<<pedidos.size()<<" pedidos (next id="<<nextPedidoId<<")\n";
}

void listarClientes(){
    if(clientes.empty()){ cout<<"Nenhum cliente cadastrado.\n"; return; }
    cout<<"Clientes:\n";
    for(auto &c: clientes){
        cout<<"ID="<<c.id<<" | "<<c.nome<<" | "<<c.email<<" | "<<c.telefone<<"\n";
    }
}

Cliente* findClienteById(int id){
    for(auto &c: clientes) if(c.id==id) return &c;
    return nullptr;
}

Pedido* findPedidoById(int id){
    for(auto &p: pedidos) if(p.id==id) return &p;
    return nullptr;
}

void listarPedidos(){
    if(pedidos.empty()){ cout<<"Nenhum pedido registrado.\n"; return; }
    cout<<"Pedidos:\n";
    for(auto &p: pedidos){
        auto c = findClienteById(p.clienteId);
        cout<<"ID="<<p.id<<" | ClienteID="<<p.clienteId<<" ("<<(c?c->nome:string("-"))<<") | "<<p.descricao<<" | R$ "<<p.valor<<" | "<<p.status<<"\n";
    }
}

void listarPedidosPorCliente(int clienteId){
    bool any=false;
    for(auto &p: pedidos) if(p.clienteId==clienteId){
        if(!any){ cout<<"Pedidos do cliente "<<clienteId<<":\n"; any=true; }
        cout<<"ID="<<p.id<<" | "<<p.descricao<<" | R$ "<<p.valor<<" | "<<p.status<<"\n";
    }
    if(!any) cout<<"Nenhum pedido para o cliente "<<clienteId<<"\n";
}

void adicionarCliente(){
    Cliente c; c.id = nextClienteId++;
    cout<<"Nome: "; getline(cin, c.nome);
    cout<<"Email: "; getline(cin, c.email);
    cout<<"Telefone: "; getline(cin, c.telefone);
    clientes.push_back(c);
    cout<<"Cliente cadastrado com ID="<<c.id<<"\n";
}

void adicionarPedido(){
    if(clientes.empty()){ cout<<"Não há clientes. Cadastre um cliente antes de criar um pedido.\n"; return; }
    listarClientes();
    cout<<"Informe o ID do cliente para o pedido: ";
    string s; getline(cin, s);
    int cid=0; try{ cid = stoi(trim(s)); } catch(...) { cid = 0; }
    if(!findClienteById(cid)){ cout<<"Cliente não encontrado.\n"; return; }
    Pedido p; p.id = nextPedidoId++; p.clienteId = cid;
    cout<<"Descrição: "; getline(cin, p.descricao);
    cout<<"Valor: "; string vs; getline(cin, vs); try{ p.valor = stod(trim(vs)); } catch(...) { p.valor = 0.0; }
    p.status = "Pendente";
    pedidos.push_back(p);
    cout<<"Pedido criado ID="<<p.id<<" para cliente "<<p.clienteId<<"\n";
}

void alterarStatusPedido(){
    listarPedidos();
    cout<<"Informe ID do pedido a alterar: "; string s; getline(cin, s);
    int id=0; try{ id = stoi(trim(s)); } catch(...) { id = 0; }
    auto p = findPedidoById(id);
    if(!p){ cout<<"Pedido não encontrado.\n"; return; }
    cout<<"Status atual: "<<p->status<<"\n";
    cout<<"Opções: 1)Pendente 2)Em preparo 3)Enviado 4)Concluido 5)Cancelado\n";
    cout<<"Escolha: "; string opt; getline(cin, opt);
    int o=0; try{ o=stoi(trim(opt)); } catch(...) { o=0; }
    switch(o){
        case 1: p->status = "Pendente"; break;
        case 2: p->status = "Em preparo"; break;
        case 3: p->status = "Enviado"; break;
        case 4: p->status = "Concluido"; break;
        case 5: p->status = "Cancelado"; break;
        default: cout<<"Opção inválida.\n"; return;
    }
    cout<<"Status alterado.\n";
}

void menu(){
    while(true){
        cout<<"\n===== Sistema Cliente/Pedido =====\n";
        cout<<"1) Adicionar Cliente\n";
        cout<<"2) Listar Clientes\n";
        cout<<"3) Adicionar Pedido\n";
        cout<<"4) Listar Pedidos\n";
        cout<<"5) Listar Pedidos por Cliente\n";
        cout<<"6) Alterar status do Pedido\n";
        cout<<"7) Salvar dados (CSV)\n";
        cout<<"8) Carregar dados (CSV)\n";
        cout<<"0) Sair\n";
        cout<<"Escolha: ";
        string escolha; getline(cin, escolha);
        if(escolha.empty()) continue;
        int op = 0; try{ op = stoi(trim(escolha)); } catch(...) { op = -1; }
        switch(op){
            case 1: adicionarCliente(); break;
            case 2: listarClientes(); break;
            case 3: adicionarPedido(); break;
            case 4: listarPedidos(); break;
            case 5: {
                cout<<"Informe ID do cliente: "; string s; getline(cin, s);
                int id=0; try{ id = stoi(trim(s)); } catch(...) { id=0; }
                listarPedidosPorCliente(id);
                break;
            }
            case 6: alterarStatusPedido(); break;
            case 7: saveClients(); savePedidos(); break;
            case 8: loadClients(); loadPedidos(); break;
            case 0: cout<<"Saindo...\n"; return;
            default: cout<<"Opção inválida.\n"; break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<"Bem-vindo ao sistema de Cliente/Pedido\n";
    // tentar carregar automaticamente arquivos padrão se existirem
    loadClients();
    loadPedidos();
    menu();
    return 0;
}
