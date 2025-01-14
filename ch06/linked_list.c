/* Usage:
 *     ./linked_list < test_file_for_btree.txt
 *     ./linked_list < test_file_for_btree_1.txt
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 100

struct tnode {
    char *word;
    struct tnode *next;
};
struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);
char *strduplicate(char *s);
void treeprint(struct tnode *);
void treeprint_rev(struct tnode *);

int getword(char *w, int lim);

int main(int argc, char *argv[]) {
    struct tnode *root;
    root = NULL;
    char word[MAXLEN];
    while ( getword(word, MAXLEN) != EOF ) {
        //printf("getword = [%s]\n", word);
        root = addtree(root, word);
    }
    printf("Direct printing\n");
    treeprint(root);

    printf("\nReverse printing\n");
    treeprint_rev(root);

    return 0;
}

int getword(char *w, int lim) {
    int c;
    while ( (c = getchar()) != EOF ) {
        if ( !isalpha(c) || lim-- == 0 )
            break;
        *w++ = c; 
    }
    *w = '\0';
    return c;
}

struct tnode *addtree(struct tnode *p, char *w) {
    if (p == NULL) {
        p = talloc();
        p->word = strduplicate(w);
        p->next = NULL;
    } else {
        p->next = addtree(p->next, w);
    }
    return p;
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strduplicate(char *s) {
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

void treeprint(struct tnode *p) {
    /* Recursive direct printing */
/*
    if (p != NULL) {
        printf("\t%s\n", p->word);
        treeprint(p->next);
    }
*/

    /* Iterative direct printing */
    int i = 0;
    struct tnode *ptr;
    for (ptr = p; ptr != NULL; ptr = ptr->next) {
        printf("%3d : %s\n", ++i, ptr->word);
    }
}

void treeprint_rev(struct tnode *p) {
    /* Recursive reverse printing */
    static int i = 0;
    if (p != NULL) {
        treeprint_rev(p->next);
        printf("%3d : %s\n", ++i, p->word);
    }
}

