#include <stdio.h>

int main(void){
    int N, i, min, pos, a[1000];
    if (scanf("%d", &N) != 1) return 0;
    for (i = 0; i < N; i++) scanf("%d", &a[i]);
    min = a[0]; pos = 0;
    for (i = 1; i < N; i++) if (a[i] < min){ min = a[i]; pos = i; }
    printf("Menor valor: %d\nPosicao: %d\n", min, pos);
    return 0;
}
