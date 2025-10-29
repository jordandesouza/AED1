#include <stdio.h>

#define MAXN 100000

typedef struct {
    int a[1005];
    int top;
} Stack;

typedef struct {
    int a[1005];
    int l, r;
} Queue;

typedef struct {
    int a[1005];
    int sz;
} MaxHeap;

void st_init(Stack *s){ s->top = 0; }
void st_push(Stack *s, int x){ s->a[s->top++] = x; }
int  st_pop(Stack *s){ return s->a[--s->top]; }
int  st_empty(Stack *s){ return s->top == 0; }

void q_init(Queue *q){ q->l = q->r = 0; }
void q_push(Queue *q, int x){ q->a[q->r++] = x; }
int  q_pop(Queue *q){ return q->a[q->l++]; }
int  q_empty(Queue *q){ return q->l == q->r; }

void hp_init(MaxHeap *h){ h->sz = 0; }
void hp_push(MaxHeap *h, int x){
    int i = ++h->sz;
    while (i > 1 && h->a[i/2] < x){ h->a[i] = h->a[i/2]; i /= 2; }
    h->a[i] = x;
}
int hp_pop(MaxHeap *h){
    int ret = h->a[1], x = h->a[h->sz--], i = 1, j;
    while (i*2 <= h->sz){
        j = i*2;
        if (j+1 <= h->sz && h->a[j+1] > h->a[j]) j++;
        if (h->a[j] <= x) break;
        h->a[i] = h->a[j];
        i = j;
    }
    h->a[i] = x;
    return ret;
}
int hp_empty(MaxHeap *h){ return h->sz == 0; }

int main(void){
    int n;
    while (scanf("%d", &n) == 1){
        Stack st; Queue q; MaxHeap h;
        int isStack = 1, isQueue = 1, isPq = 1;
        st_init(&st); q_init(&q); hp_init(&h);

        for (int i = 0; i < n; i++){
            int t, x;
            scanf("%d %d", &t, &x);
            if (t == 1){
                if (isStack) st_push(&st, x);
                if (isQueue) q_push(&q, x);
                if (isPq)    hp_push(&h, x);
            } else {
                if (isStack){
                    if (st_empty(&st) || st_pop(&st) != x) isStack = 0;
                }
                if (isQueue){
                    if (q_empty(&q) || q_pop(&q) != x) isQueue = 0;
                }
                if (isPq){
                    if (hp_empty(&h) || hp_pop(&h) != x) isPq = 0;
                }
            }
        }

        int cnt = isStack + isQueue + isPq;
        if (cnt == 0) puts("impossible");
        else if (cnt > 1) puts("not sure");
        else if (isStack) puts("stack");
        else if (isQueue) puts("queue");
        else puts("priority queue");
    }
    return 0;
}
