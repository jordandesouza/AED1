#include <stdio.h>

int main(void){
    int N, i, v, min, pos;
    if (scanf("%d", &N) != 1) return 0;
    scanf("%d", &min); pos = 0;
    for (i = 1; i < N; i++){
        scanf("%d", &v);
        if (v < min){ min = v; pos = i; }
    }
    printf("Menor valor: %d\nPosicao: %d\n", min, pos);
    return 0;
}
