#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int instancias;
    if (scanf("%d", &instancias) != 1) return 0;

    int *matriz = (int*)malloc(9 * 9 * sizeof(int));
    if (!matriz) return 0;

    for (int k = 1; k <= instancias; k++) {
        for (int i = 0; i < 81; i++) scanf("%d", &matriz[i]);

        int valido = 1, controle[10], numero;

        for (int i = 0; i < 9 && valido; i++) {
            memset(controle, 0, sizeof(controle));
            for (int j = 0; j < 9; j++) {
                numero = matriz[i * 9 + j];
                if (numero < 1 || numero > 9 || controle[numero]) { valido = 0; break; }
                controle[numero] = 1;
            }
        }

        for (int j = 0; j < 9 && valido; j++) {
            memset(controle, 0, sizeof(controle));
            for (int i = 0; i < 9; i++) {
                numero = matriz[i * 9 + j];
                if (numero < 1 || numero > 9 || controle[numero]) { valido = 0; break; }
                controle[numero] = 1;
            }
        }

        for (int li = 0; li < 9 && valido; li += 3) {
            for (int cj = 0; cj < 9 && valido; cj += 3) {
                memset(controle, 0, sizeof(controle));
                for (int i = li; i < li + 3; i++) {
                    for (int j = cj; j < cj + 3; j++) {
                        numero = matriz[i * 9 + j];
                        if (numero < 1 || numero > 9 || controle[numero]) { valido = 0; break; }
                        controle[numero] = 1;
                    }
                    if (!valido) break;
                }
            }
        }

        printf("Instancia %d\n", k);
        printf(valido ? "SIM\n\n" : "NAO\n\n");
    }

    free(matriz);
    return 0;
}
