#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, posicao;
    int menor;

    scanf("%d", &numero);

    // alocando memória
    int *lista = (int *)malloc(numero * sizeof(int));
    if (lista == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    // recebendo valores 
    for (int i = 0; i < numero; i++) {
        scanf("%d", lista + i); 
    }
    // o primeiro elemento
    menor = *lista;  
    posicao = 0;

    // encontrando o menor valor e sua posição 
    for (int i = 0; i < numero; i++) {
        if (*(lista + i) < menor) {  
            menor = *(lista + i);
            posicao = i;
        }
    }

    printf("Menor valor: %d\nPosicao: %d\n", menor, posicao);

    // liberando memória
    free(lista);

    return 0;
}
