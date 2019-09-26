#include <stdio.h>
#include <string.h>
#include "bst.h"
#include "mylib.h"

struct bstnode {
    char* key;
    bst left;
    bst right;
};

bst bst_free(bst b) {
    bst_free(b->left);
    bst_free(b->right);

    free(b->key);
    free(b);
    return b;
}

void bst_inorder(bst b, void f(char *str)) {
    if(b == NULL) {
        return;
    }

    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);
}

bst bst_insert(bst b, char *str) {
    int cond;
    if(b == NULL) {
        b = emalloc(sizeof(bst));
        b->key = emalloc((strlen(str) + 1) * (sizeof(char)));
        strcpy(b->key, str);
        b->left = b->right = NULL;
    }

    if((cond = strcmp(b->key, str)) < 0) {
        b->left = bst_insert(b->left, str);
    } else if(cond > 0) {
        b->right = bst_insert(b->right, str);
    } else { }

    return b;
}

bst bst_new() {
    return NULL;
}

void bst_preorder(bst b, void f(char *str)) {
    if(b == NULL) {
        return;
    }

    f(b->key);
    bst_preorder(b->left, f);
    bst_preorder(b->right, f);
}

int bst_search(bst b, char *str) {
    int index;
    int cond;

    if(b == NULL) {
        return 0;
    }

    if((cond = strcmp(b->key, str)) < 0) {
        return bst_search(b->left, str);
    } else if(cond > 0) {
        return bst_search(b->right, str);
    } else {
        return 1;
    }
}