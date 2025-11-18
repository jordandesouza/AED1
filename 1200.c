#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char key;
    struct Node *l, *r;
} Node;

Node* insert(Node *t, char x){
    if (!t){
        Node *n = (Node*)malloc(sizeof(Node));
        n->key = x; n->l = n->r = NULL;
        return n;
    }
    if (x < t->key) t->l = insert(t->l, x);
    else if (x > t->key) t->r = insert(t->r, x);
    return t;
}

int search(Node *t, char x){
    while (t){
        if (x == t->key) return 1;
        t = (x < t->key) ? t->l : t->r;
    }
    return 0;
}

void infixa(Node *t, int *first){
    if (!t) return;
    infixa(t->l, first);
    if (!*first) putchar(' '); else *first = 0;
    putchar(t->key);
    infixa(t->r, first);
}

void prefixa(Node *t, int *first){
    if (!t) return;
    if (!*first) putchar(' '); else *first = 0;
    putchar(t->key);
    prefixa(t->l, first);
    prefixa(t->r, first);
}

void posfixa(Node *t, int *first){
    if (!t) return;
    posfixa(t->l, first);
    posfixa(t->r, first);
    if (!*first) putchar(' '); else *first = 0;
    putchar(t->key);
}

int main(void){
    Node *root = NULL;
    char cmd[16], arg[16];

    while (scanf("%s", cmd) == 1){
        if (strcmp(cmd, "I") == 0){
            scanf("%s", arg);
            root = insert(root, arg[0]);
        } else if (strcmp(cmd, "P") == 0){
            scanf("%s", arg);
            printf("%c %s\n", arg[0], search(root, arg[0]) ? "existe" : "nao existe");
        } else if (strcmp(cmd, "INFIXA") == 0){
            int first = 1; infixa(root, &first); putchar('\n');
        } else if (strcmp(cmd, "PREFIXA") == 0){
            int first = 1; prefixa(root, &first); putchar('\n');
        } else if (strcmp(cmd, "POSFIXA") == 0){
            int first = 1; posfixa(root, &first); putchar('\n');
        }
    }
    return 0;
}
