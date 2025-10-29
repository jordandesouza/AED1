#include <stdio.h>

int main(void) {
    int t, k = 1;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int a[9][9];
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                scanf("%d", &a[i][j]);

        int ok = 1;

        for (int i = 0; i < 9 && ok; i++) {
            int f[10] = {0};
            for (int j = 0; j < 9; j++) {
                int v = a[i][j];
                if (v < 1 || v > 9 || ++f[v] > 1) { ok = 0; break; }
            }
        }

        for (int j = 0; j < 9 && ok; j++) {
            int f[10] = {0};
            for (int i = 0; i < 9; i++) {
                int v = a[i][j];
                if (v < 1 || v > 9 || ++f[v] > 1) { ok = 0; break; }
            }
        }

        for (int br = 0; br < 9 && ok; br += 3) {
            for (int bc = 0; bc < 9 && ok; bc += 3) {
                int f[10] = {0};
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int v = a[br + i][bc + j];
                        if (v < 1 || v > 9 || ++f[v] > 1) { ok = 0; break; }
                    }
                    if (!ok) break;
                }
            }
        }

        printf("Instancia %d\n", k++);
        printf(ok ? "SIM\n\n" : "NAO\n\n");
    }
    return 0;
}
