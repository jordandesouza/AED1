#include <stdio.h>
#include <stdlib.h>

int main(){

    int numero, posicao, menor;
    scanf("%d", &numero);

    //tamanho do array definido pelo usuário
    int lista[numero];

    //valores do usuário sendo alocado na array
    for(int i = 0; i< numero; i++){
        scanf("%d", &lista[i]);

    }

    menor = lista[0];

    //encontrando o menor valor e sua posição
    for(int i=0; i< numero; i++){
        if(lista[i] < menor){
            posicao = i;
            menor = lista[i];
        }
    }


    printf("Menor valor: %d\nPosicao: %d\n", menor, posicao);
}