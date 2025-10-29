#include <stdio.h>

int main(void){
    int n;
    while (scanf("%d", &n) == 1){
        int stk[1000], stksz = 0;
        int que[1000], qh = 0, qt = 0;
        int pq[1000], pqs = 0;

        int ok_stack = 1, ok_queue = 1, ok_pq = 1;

        for (int i = 0; i < n; i++){
            int op, x;
            scanf("%d %d", &op, &x);

            if (op == 1){
                if (ok_stack) stk[stksz++] = x;
                if (ok_queue) que[qt++] = x;
                if (ok_pq)    pq[pqs++]  = x;
            } else {
                if (ok_stack){
                    if (stksz == 0) ok_stack = 0;
                    else if (stk[stksz-1] != x) ok_stack = 0;
                    else stksz--;
                }
                if (ok_queue){
                    if (qh == qt) ok_queue = 0;
                    else if (que[qh] != x) ok_queue = 0;
                    else qh++;
                }
                if (ok_pq){
                    if (pqs == 0) ok_pq = 0;
                    else{
                        int idx = 0;
                        for (int j = 1; j < pqs; j++)
                            if (pq[j] > pq[idx]) idx = j;
                        if (pq[idx] != x) ok_pq = 0;
                        else{
                            pq[idx] = pq[pqs-1];
                            pqs--;
                        }
                    }
                }
            }
        }

        int cnt = ok_stack + ok_queue + ok_pq;
        if (cnt == 0) puts("impossible");
        else if (cnt > 1) puts("not sure");
        else if (ok_stack) puts("stack");
        else if (ok_queue) puts("queue");
        else puts("priority queue");
    }
    return 0;
}
