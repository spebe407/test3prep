#ifndef BST_H_
#define BST_H_
#include <stdio.h>
typedef struct bstnode *bst;
extern bst bst_delete(bst b, char *str);
extern bst bst_free(bst b);
extern void bst_inorder(bst b, void f(char *str));
extern bst bst_insert(bst b, char *str);
extern bst bst_new();
extern void bst_preorder(bst b, void f(char *str));
extern int bst_search(bst b, char *str);
extern void bst_print(bst b);
#endif