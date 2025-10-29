#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *matriz;
    int instancias, numero;
    int controle[10];
    int valido;

    scanf("%d", &instancias);

    matriz = (int *)malloc(9 * 9 * sizeof(int));

    for (int k = 1; k <= instancias; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i * 9 + j]);
            }
        }

        valido = 1;

        for (int i = 0; i < 9 && valido; i++) {
            memset(controle, 0, sizeof(controle));
            for (int j = 0; j < 9; j++) {
                numero = matriz[i * 9 + j];
                if (controle[numero] == 1) {
                    valido = 0;
                    break;
                }
                controle[numero] = 1;
            }
        }

        for (int j = 0; j < 9 && valido; j++) {
            memset(controle, 0, sizeof(controle));
            for (int i = 0; i < 9; i++) {
                numero = matriz[i * 9 + j];
                if (controle[numero] == 1) {
                    valido = 0;
                    break;
                }
                controle[numero] = 1;
            }
        }

        for (int linhaInicial = 0; linhaInicial < 9 && valido; linhaInicial += 3) {
            for (int colunaInicial = 0; colunaInicial < 9 && valido; colunaInicial += 3) {
                memset(controle, 0, sizeof(controle));
                for (int i = linhaInicial; i < linhaInicial + 3; i++) {
                    for (int j = colunaInicial; j < colunaInicial + 3; j++) {
                        numero = matriz[i * 9 + j];
                        if (controle[numero] == 1) {
                            valido = 0;
                            break;
                        }
                        controle[numero] = 1;
                    }
                    if (!valido) break;
                }
            }
        }

        printf("Instancia %d\n", k);
        if (valido)
            printf("SIM\n\n");
        else
            printf("NAO\n\n");
    }

    free(matriz);
    return 0;
}
