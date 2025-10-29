#include <stdio.h>

int main(void){
    int N;
    while (scanf("%d", &N) == 1 && N) {
        for (;;) {
            int first;
            if (scanf("%d", &first) != 1) return 0;
            if (first == 0) { printf("\n"); break; }

            int seq[1000]; seq[0] = first;
            for (int i = 1; i < N; i++) scanf("%d", &seq[i]);

            int stack[1000], top = 0, next = 1, ok = 1;
            for (int i = 0; i < N; i++) {
                int want = seq[i];
                while (next <= N && (top == 0 || stack[top-1] != want))
                    stack[top++] = next++;
                if (top > 0 && stack[top-1] == want) top--;
                else ok = 0;
            }
            printf(ok ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
