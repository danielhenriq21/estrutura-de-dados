#include <stdio.h>
#include <string.h>

// Definindo a estrutura Produto
typedef struct {
    int codigo;          // C�digo �nico do produto
    char nome[30];       // Nome do produto
    float preco;         // Pre�o do produto
} Produto;

// Definindo a estrutura Carrinho
typedef struct {
    Produto produto;     // Produto associado ao carrinho
    int quantidade;      // Quantidade desse produto no carrinho
} Carrinho;

// Definindo os arrays para armazenar os produtos e o carrinho
#define MAX_PRODUTOS 50
#define MAX_CARRINHO 50

Produto produtos[MAX_PRODUTOS];   // Array de produtos cadastrados
Carrinho carrinho[MAX_CARRINHO];  // Array de produtos no carrinho
int numProdutos = 0;              // Contador de produtos cadastrados
int numCarrinho = 0;              // Contador de itens no carrinho

// Fun��o para exibir o menu
void menu() {
    int opcao;
    do {
        // Exibindo as op��es do menu
        printf("\n1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Comprar Produto\n");
        printf("4. Visualizar Carrinho\n");
        printf("5. Fechar Pedido\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);  // Lendo a escolha do usu�rio

        // Chamando a fun��o correspondente � op��o escolhida
        switch(opcao) {
            case 1: cadastrarProduto(); break;     // Cadastrar novo produto
            case 2: listarProdutos(); break;       // Listar todos os produtos
            case 3: comprarProduto(); break;       // Adicionar produtos ao carrinho
            case 4: visualizarCarrinho(); break;   // Visualizar os itens do carrinho
            case 5: fecharPedido(); break;         // Fechar o pedido e calcular o total
            case 6: printf("Saindo...\n"); break;  // Sair do sistema
            default: printf("Opcao invalida!\n");  // Caso o usu�rio insira uma op��o inv�lida
        }
    } while (opcao != 6);  // O loop continua at� que o usu�rio escolha sair
}

// Fun��o para cadastrar um novo produto
void cadastrarProduto() {
    // Verifica se ainda h� espa�o para cadastrar mais produtos
    if (numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\\n");
        return;
    }

    // Cria um novo produto e solicita as informa��es ao usu�rio
    Produto p;
    printf("Digite o codigo do produto: ");
    scanf("%d", &p.codigo);  // L� o c�digo do produto

    // Limpa o buffer de entrada antes de solicitar o pr�ximo dado
    getchar();  // Remove o caractere extra do buffer ap�s ler o n�mero

    printf("Digite o nome do produto: ");
    fgets(p.nome, sizeof(p.nome), stdin);  // Usa fgets para ler strings com espa�os
    // Remove o caractere de nova linha que o fgets pode adicionar
    p.nome[strcspn(p.nome, "\\n")] = 0;

    printf("Digite o preco do produto: ");
    scanf("%f", &p.preco);  // L� o pre�o do produto

    // Adiciona o produto ao array de produtos cadastrados
    produtos[numProdutos] = p;
    numProdutos++;

    printf("Produto cadastrado com sucesso!\\n");
}


// Fun��o para listar todos os produtos cadastrados
void listarProdutos() {
    if (numProdutos == 0) {
        // Caso n�o haja nenhum produto cadastrado
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    // Exibe a lista de produtos
    printf("\nLista de Produtos:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Codigo: %d, Nome: %s, Preco: %.2f\n",
            produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }
}

// Fun��o para adicionar produtos ao carrinho
void comprarProduto() {
    int codigo, quantidade;
    printf("Digite o codigo do produto que deseja comprar: ");
    scanf("%d", &codigo);  // Lendo o c�digo do produto

    // Verifica se o produto est� cadastrado
    int index = pegarProdutoPorCodigo(codigo);
    if (index == -1) {
        printf("Produto nao encontrado!\n");
        return;
    }

    // Lendo a quantidade desejada do produto
    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    // Verifica se o produto j� est� no carrinho
    int carrinhoIndex = temNoCarrinho(codigo);
    if (carrinhoIndex == -1) {
        // Se o produto n�o est� no carrinho, adiciona um novo item
        carrinho[numCarrinho].produto = produtos[index];
        carrinho[numCarrinho].quantidade = quantidade;
        numCarrinho++;
    } else {
        // Se j� est� no carrinho, apenas atualiza a quantidade
        carrinho[carrinhoIndex].quantidade += quantidade;
    }

    printf("Produto adicionado ao carrinho!\n");
}

// Fun��o para visualizar os produtos no carrinho
void visualizarCarrinho() {
    if (numCarrinho == 0) {
        // Caso o carrinho esteja vazio
        printf("Carrinho vazio!\n");
        return;
    }

    // Exibe os itens no carrinho
    printf("\nCarrinho de Compras:\n");
    for (int i = 0; i < numCarrinho; i++) {
        printf("Produto: %s, Quantidade: %d, Preco Unitario: %.2f\n",
            carrinho[i].produto.nome, carrinho[i].quantidade, carrinho[i].produto.preco);
    }
}

// Fun��o para fechar o pedido, calcular o total e limpar o carrinho
void fecharPedido() {
    if (numCarrinho == 0) {
        // Se o carrinho estiver vazio
        printf("Carrinho vazio!\n");
        return;
    }

    float total = 0.0;  // Vari�vel para armazenar o valor total da compra
    printf("\nFatura:\n");
    for (int i = 0; i < numCarrinho; i++) {
        float subtotal = carrinho[i].quantidade * carrinho[i].produto.preco;
        printf("Produto: %s, Quantidade: %d, Subtotal: %.2f\n",
            carrinho[i].produto.nome, carrinho[i].quantidade, subtotal);
        total += subtotal;  // Soma o subtotal ao total geral
    }

    printf("Total da compra: %.2f\n", total);
    numCarrinho = 0;  // Limpa o carrinho ap�s a finaliza��o do pedido
}

// Fun��o auxiliar para verificar se o produto j� est� no carrinho
int temNoCarrinho(int codigo) {
    for (int i = 0; i < numCarrinho; i++) {
        if (carrinho[i].produto.codigo == codigo) {
            return i;  // Retorna o �ndice do produto no carrinho
        }
    }
    return -1;  // Retorna -1 se o produto n�o estiver no carrinho
}

// Fun��o para buscar um produto pelo c�digo
int pegarProdutoPorCodigo(int codigo) {
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return i;  // Retorna o �ndice do produto encontrado
        }
    }
    return -1;  // Retorna -1 se o produto n�o for encontrado
}

// Fun��o principal
int main() {
    // Chama o menu principal do sistema
    menu();
    return 0;
}
