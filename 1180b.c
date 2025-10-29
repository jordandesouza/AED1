#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N, i, min, pos, *a;
    if (scanf("%d", &N) != 1) return 0;
    a = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) scanf("%d", &a[i]);
    min = a[0]; pos = 0;
    for (i = 1; i < N; i++) if (a[i] < min){ min = a[i]; pos = i; }
    printf("Menor valor: %d\nPosicao: %d\n", min, pos);
    free(a);
    return 0;
}
