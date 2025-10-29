#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

static ll merge_count(int *a, int *tmp, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2;
    ll inv = merge_count(a, tmp, l, m) + merge_count(a, tmp, m, r);

    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else { tmp[k++] = a[j++]; inv += (ll)(m - i); }
    }
    while (i < m) tmp[k++] = a[i++];
    while (j < r) tmp[k++] = a[j++];
    for (i = l; i < r; i++) a[i] = tmp[i];

    return inv;
}

int main(void) {
    int N;
    while (scanf("%d", &N) == 1) {
        if (N == 0) break;

        int *a = (int*)malloc(N * sizeof(int));
        int *tmp = (int*)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) scanf("%d", &a[i]);

        ll inv = merge_count(a, tmp, 0, N);
        puts((inv % 2) ? "Marcelo" : "Carlos");

        free(a);
        free(tmp);
    }
    return 0;
}
