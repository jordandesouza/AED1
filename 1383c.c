#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int t, k = 1;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int *a = (int*)malloc(9 * 9 * sizeof(int));
        for (int i = 0; i < 81; i++) scanf("%d", &a[i]);

        int ok = 1;

        for (int i = 0; i < 9 && ok; i++) {
            int *f = (int*)calloc(10, sizeof(int));
            for (int j = 0; j < 9; j++) {
                int v = a[i*9 + j];
                if (v < 1 || v > 9 || ++f[v] > 1) { ok = 0; break; }
            }
            free(f);
        }

        for (int j = 0; j < 9 && ok; j++) {
            int *f = (int*)calloc(10, sizeof(int));
            for (int i = 0; i < 9; i++) {
                int v = a[i*9 + j];
                if (v < 1 || v > 9 || ++f[v] > 1) { ok = 0; break; }
            }
            free(f);
        }

        for (int br = 0; br < 9 && ok; br += 3) {
            for (int bc = 0; bc < 9 && ok; bc += 3) {
                int *f = (int*)calloc(10, sizeof(int));
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int v = a[(br+i)*9 + (bc+j)];
                        if (v < 1 || v > 9 || ++f[v] > 1) { ok = 0; break; }
                    }
                    if (!ok) break;
                }
                free(f);
            }
        }

        printf("Instancia %d\n", k++);
        printf(ok ? "SIM\n\n" : "NAO\n\n");
        free(a);
    }
    return 0;
}
