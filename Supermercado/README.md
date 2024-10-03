# Trabalho Estrutura de dados
## Daniel Henrique Rodrigues da Silva
## UC20104282

# Sistema de Supermercado em C

## Descrição do Projeto
Este projeto implementa um sistema simples de supermercado utilizando a linguagem de programação C. O sistema utiliza conceitos de **estrutura de dados** como **structs**, **arrays** e **funções**. Ele permite o cadastro de produtos, adição ao carrinho, visualização do carrinho, fechamento do pedido, e outras operações básicas de um sistema de compras.

## Funcionalidades

1. **Cadastrar Produto**: Permite o cadastro de novos produtos no sistema, com código único, nome e preço.
2. **Listar Produtos**: Exibe a lista de todos os produtos cadastrados, mostrando código, nome e preço.
3. **Comprar Produto**: O usuário pode adicionar produtos ao carrinho de compras através do código.
4. **Visualizar Carrinho**: Exibe os produtos adicionados ao carrinho, com suas respectivas quantidades e preços.
5. **Fechar Pedido**: Calcula o valor total da compra, exibe uma fatura detalhada e esvazia o carrinho.
6. **Sair do Sistema**: Encerra a execução do sistema de forma segura.

## Estrutura de Dados

O sistema utiliza as seguintes estruturas de dados:

- **Produto**: Representa os produtos cadastrados no supermercado, contendo código, nome e preço.
  
```
typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;
```

- **Carrinho**: Representa os itens no carrinho de compras com o produto e a quantidade.

```
typedef struct {
    Produto produto;
    int quantidade;
} Carrinho;
```

## Requisitos

O sistema suporta:

- Até 50 produtos cadastrados.
- Até 50 itens diferentes no carrinho.
- Verificação de duplicidade no carrinho (produtos repetidos têm a quantidade aumentada).

## Regras de Negócio

- Só é possível adicionar ao carrinho produtos já cadastrados.
- Produtos duplicados no carrinho têm suas quantidades aumentadas.
- Ao fechar o pedido, o carrinho é esvaziado e o usuário retorna ao menu principal.

# Compilação e Execução do Programa

## Pré-requisitos

Você precisará de um compilador C instalado, como o Code::Blocks ou GCC.

## Compilar no Terminal usando GCC

- No terminal, navegue até a pasta onde o código foi salvo.
- Compile o programa com o comando:

```
gcc main.c -o supermercado
```

- Execute o programa com:
```
./supermercado
```
  
## Funcionalidades Implementadas

- **Cadastrar Produto**: O sistema pede o código, nome e preço do produto.
- **Listar Produtos**: Exibe todos os produtos cadastrados.
- **Comprar Produto**: Adiciona produtos ao carrinho com base no código.
- **Visualizar Carrinho**: Mostra os produtos e quantidades no carrinho.
- **Fechar Pedido**: Calcula e exibe o valor total, limpando o carrinho após a compra.
- **Sair do Sistema**: Encerra a execução do programa.

# Testes
Testes executados no sistema:
### Cadastrar produto
1. Digite 1;
2. Digite o código do produto. Ex.: 123
3. Digite o nome do produto. Ex.: Coca Cola
4. Digite o preço do produto. Ex.: 9.99

### Listar Produtos
1. Ao digitar 2 será listado todos os produtos cadastrados. No teste: "Codigo: 123, Nome: Coca Cola, Preco: 9.99"

### Comprar produto
1. Ao digitar 3 será solicitado o código do produto que cadastrou. Ex.: 123
2. Digite a quantia de produtos que quer. Ex.: 50

### Vizualizar carrinho
1. Ao digitar 4 o carrinho de produtos selecionados será mostrado. Ex.: "Produto: Coca Cola, Quantidade: 50, Preco Unitario: 9.99"

### Fechar pedido
1. Ao digitar 5 será mostrado o preço total de acordo com a quantidade mencionada no passo anterior. Ex.: "Produto: Coca Cola, Quantidade: 50, Subtotal: 499.50"

### Sair
1. Ao digitar 6, sairá do programa
