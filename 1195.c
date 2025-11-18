#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *l, *r;
} Node;

Node* insert(Node *t, int x){
    if (!t){
        Node *n = (Node*)malloc(sizeof(Node));
        n->key = x; n->l = n->r = NULL;
        return n;
    }
    if (x < t->key) t->l = insert(t->l, x);
    else            t->r = insert(t->r, x);
    return t;
}

void preorder(Node *t, int *first){
    if (!t) return;
    if (!*first) putchar(' '); else *first = 0;
    printf("%d", t->key);
    preorder(t->l, first);
    preorder(t->r, first);
}

void inorder(Node *t, int *first){
    if (!t) return;
    inorder(t->l, first);
    if (!*first) putchar(' '); else *first = 0;
    printf("%d", t->key);
    inorder(t->r, first);
}

void postorder(Node *t, int *first){
    if (!t) return;
    postorder(t->l, first);
    postorder(t->r, first);
    if (!*first) putchar(' '); else *first = 0;
    printf("%d", t->key);
}

void freetree(Node *t){
    if (!t) return;
    freetree(t->l);
    freetree(t->r);
    free(t);
}

int main(void){
    int C;
    if (scanf("%d", &C) != 1) return 0;
    for (int cs = 1; cs <= C; cs++){
        int N, x;
        scanf("%d", &N);
        Node *root = NULL;
        for (int i = 0; i < N; i++){
            scanf("%d", &x);
            root = insert(root, x);
        }

        printf("Case %d:\n", cs);

        int first = 1;
        printf("Pre.: ");
        first = 1; preorder(root, &first); putchar('\n');

        printf("In..: ");
        first = 1; inorder(root, &first); putchar('\n');

        printf("Post: ");
        first = 1; postorder(root, &first); putchar('\n');

        putchar('\n');
        freetree(root);
    }
    return 0;
}
