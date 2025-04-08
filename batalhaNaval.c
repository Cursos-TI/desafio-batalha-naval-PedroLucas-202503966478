#include <stdio.h> // Inclui a biblioteca padrão para entrada e saída

#define LARGURA 10  // Define a largura do tabuleiro
#define ALTURA 10   // Define a altura do tabuleiro

// Função que exibe o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[ALTURA][LARGURA]) {
    printf(" #");
    for (int x = 0; x < LARGURA; x++) {
        printf("-%d", x); // Imprime os índices da parte superior do tabuleiro
    }
    printf("-#\n");

    for (int i = 0; i < ALTURA; i++) {
        printf(" %d-", i); // Imprime o índice da linha atual (esquerda)
        for (int j = 0; j < LARGURA; j++) {
            if (j) {
                printf(" "); // Espaçamento entre colunas
            }
            printf("%d", tabuleiro[i][j]); // Imprime o valor da célula
        }
        printf("-%d\n", i); // Imprime o índice da linha atual (direita)
    }

    // Imprime os índices da parte inferior do tabuleiro
    printf(" #");
    for (int x = 0; x < LARGURA; x++) {
        printf("-%d", x);
    }
    printf("-#\n");
}

// Função para exibir uma matriz de habilidade (3x5)
void exibirHabilidade(int habilidade[3][5]) {
    for (int i = 0; i < 3; i++) { // Linhas
        for (int j = 0; j < 5; j++) { // Colunas
            printf(" %d", habilidade[i][j]); // Imprime cada valor da habilidade
        }
        printf("\n");
    }
}

// Aplica a habilidade escolhida no tabuleiro
void usarHabilidade(int x, int y, int habilidade[3][5], int tabuleiro[ALTURA][LARGURA]) {
    // Centraliza a matriz da habilidade no ponto (x, y) escolhido
    x -= 2; // Corrige para alinhar a largura da habilidade
    y -= 1; // Corrige para alinhar a altura da habilidade

    // Percorre a matriz da habilidade (3 linhas x 5 colunas)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            // Verifica se está dentro dos limites do tabuleiro e se a célula da habilidade é 1
            if (y+i >= 0 && y+i < ALTURA && x+j >= 0 && x+j < LARGURA && habilidade[i][j]) {
                tabuleiro[y+i][x+j] = 1; // Marca o impacto no tabuleiro
            }
        }
    }
}

int main() {
    // Inicializa o tabuleiro com obstáculos (valor 3) e espaços vazios (0)
    int tabuleiro[ALTURA][LARGURA] = {
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 3, 3, 3, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Habilidade em formato de cone
    int cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    // Habilidade em formato de octaedro (diamante)
    int octaedro[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Habilidade em formato de cruz
    int cruz[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };

    while (1) {
        printf("Tabuleiro:\n");
        exibirTabuleiro(tabuleiro); // Exibe o estado atual do tabuleiro

        // Menu de opções
        printf("\nEscolha uma habilidade ou sair:\n");
        printf("\nSair[0]: Encerra o programa\n");

        // Exibe a forma das habilidades
        printf("\nCone[1]:\n");
        exibirHabilidade(cone);

        printf("\nOctaedro[2]:\n");
        exibirHabilidade(octaedro);

        printf("\nCruz[3]:\n");
        exibirHabilidade(cruz);

        int opt = -1;

        // Lê a opção do usuário até que seja válida (entre 0 e 3)
        while (opt < 0 || opt > 3) {
            printf("\nHabilidade: ");
            scanf("%d", &opt);
            getchar(); // Limpa o buffer do teclado
        }

        if (opt == 0) {
            return 0; // Sai do programa se o jogador escolher 0
        }

        int x, y; // Coordenadas do centro do ataque

        // Solicita ao usuário a posição para usar a habilidade
        printf("Centro do ataque: \n");
        printf("\nX: ");
        scanf("%d", &x);
        getchar();

        printf("Y: ");
        scanf("%d", &y);
        getchar();

        // Chama a função correspondente à habilidade escolhida
        switch (opt) {
            case 1:
                usarHabilidade(x, y, cone, tabuleiro);
                break;
            case 2:
                usarHabilidade(x, y, octaedro, tabuleiro);
                break;
            case 3:
                usarHabilidade(x, y, cruz, tabuleiro);
                break;
        }
    }

    return 0;
}
