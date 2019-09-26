#include "stdlib.h"
#include "stdio.h"
#include "bst.h"
#include "string.h"
#include "mylib.h"

#define STR_SIZE 256

struct bstnode {
    char *key;
    bst left;
    bst right;
};

bst bst_delete(bst b, char *str) {
    if(b == NULL) return b;

    if(strcmp(str, b->key) < 0) {
        b->left = bst_delete(b->left, str);
    } else if(strcmp(str, b->key) > 0) {
        b->right = bst_delete(b->right, str);
    } else {
        if(b->left == NULL) {
            bst temp = b->right;
            free(b->right);
            return temp;
        }
    }

}

bst bst_free(bst b) {
    
}

void bst_inorder(bst b, void f(char *str)) {
    if(b == NULL) {
        return;
    }

    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);
}

void bst_preorder(bst b, void f(char *str)) {
    if(b == NULL) {
        return;
    }    
    f(b->key);
    bst_preorder(b->left, f);
    bst_preorder(b->right, f);
}

bst bst_insert(bst b, char *str) {
    int comp;
    printf("Trying to insert: %s\n", str);
    if(b == NULL) {
        b = emalloc(sizeof(bst));
        b->key = emalloc((strlen(str) + 1) * sizeof(str));
        strcpy(b->key, str);
        b->left = b->right = NULL;
    } 
    
    if((comp = strcmp(b->key, str)) < 0) { /*str less than b->key*/
        printf("Going to left subtree.\n");
        b->left = bst_insert(b->left, str);
    } else if(comp > 0) { /*str greater than b->key*/
        printf("Going to left subtree.\n");
        b->right = bst_insert(b->right, str);
    } else { } /*str == b->key*/

    return b;
}

bst bst_new() {
    return NULL;
}

static void print_key(char* str) {
    printf("%s\n", str);
}

/*void bst_print_clean(bst b, int itr_c) {
    if(b != NULL) {
        bst_print_clean(b->left, itr_c++);
        printf("(%d): %s\n", itr_c, b->key);
        bst_print_clean(b->right, itr_c++);
    }

    return;
}*/

int main(void){
    bst root = bst_new();
    
    char word[STR_SIZE];
    while((getword(word, STR_SIZE, stdin) != EOF)) {
        root = bst_insert(root, word);
    }

    bst_preorder(root, print_key);

    return EXIT_SUCCESS;
}