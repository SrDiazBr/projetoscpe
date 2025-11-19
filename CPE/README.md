# Sistema Cliente/Pedido (C++)

Pequeno sistema em C++ para cadastro de clientes e controle de pedidos com relação 1:N.

Arquivos gerados:

- `cliente_pedido.cpp` - implementação principal.

Como compilar (Windows, PowerShell):

```powershell
g++ -std=c++17 cliente_pedido.cpp -o cliente_pedido.exe
```

Exemplo de execução interativa:

```powershell
./cliente_pedido.exe
```

Exemplo de execução automatizada (entrada redirecionada) para teste rápido:

1) Crie um arquivo `input.txt` com as linhas que representam a interação (cada entrada por linha). Exemplo simples:

```
1
João Silva
joao@email.com
(11)99999-0000
3
1
Pizza grande
45.5
4
0
```

2) Pipe o arquivo para o programa no PowerShell:

```powershell
type input.txt | .\cliente_pedido.exe
```

Os dados são salvos em CSV nos arquivos padrões `clients.csv` e `pedidos.csv` quando escolhida a opção "Salvar dados (CSV)" no menu.

Notas:
- Este projeto é simples e faz persistência em CSV sem escaping avançado; não é adequado para dados com ponto-e-vírgula na descrição.
- Pode ser facilmente estendido (remoção, edição de cliente, busca, relatórios, etc.).
