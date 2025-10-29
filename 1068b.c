#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct node {
    struct node *next;
} node;

int push(node **top){
    node *n = (node*)malloc(sizeof(node));
    if (!n) return 0;
    n->next = *top;
    *top = n;
    return 1;
}

int popn(node **top){
    if (!*top) return 0;
    node *t = *top;
    *top = t->next;
    free(t);
    return 1;
}

void clear(node **top){ while (*top) popn(top); }

int main(void){
    char s[MAX+1];
    while (scanf(" %1000[^\n]", s) == 1) {
        node *st = NULL;
        int ok = 1;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '(') { if (!push(&st)) { ok = 0; break; } }
            else if (s[i] == ')') { if (!popn(&st)) { ok = 0; break; } }
        }
        if (st) ok = 0;
        clear(&st);
        printf("%s\n", ok ? "correct" : "incorrect");
    }
    return 0;
}
