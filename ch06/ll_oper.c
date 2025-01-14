/* Linked list operations. We try to build a lexically ordered linked list.
 * That will involve adding nodes in the middle etc. It is a highly inefficient
 * technique as compared to btrees.
 * Compare the run times of this program with that of "btree.c" in this
 * directory. Test it on huge files e.g. bible_kjv.txt
 * Usage:
 *     ./linked_list < test_file_for_btree.txt
 *     ./linked_list < test_file_for_btree_1.txt
 *     time ./ll_oper < ../ch05/bible_kjv.txt 2>/dev/null 1>&2  (about 1 min 13 sec)
 *     time ./btree < ../ch05/bible_kjv.txt 2>/dev/null 1>&2 (about 0.75 sec)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 100

struct tnode {
    char *word;
    int count;
    struct tnode *next;
};
struct tnode *addtree(struct tnode *, char *);
struct tnode *addtree_1(struct tnode *, char *, int);

struct tnode *talloc(void);
char *strduplicate(char *s);
void treeprint(struct tnode *);
void treeprint_rev(struct tnode *);

int getword(char *w, int lim);

int main(int argc, char *argv[]) {
    struct tnode *root;
    root = NULL;
    int calls = 0;

/*
    // Let's try to build a lexically ordered linked list
    printf("--------------------------------------------\n");
    char word1[MAXLEN] = "apple";
    root = addtree_1(root, word1, calls);
    treeprint(root);

    printf("--------------------------------------------\n");
    char word2[MAXLEN] = "apple";
    root = addtree_1(root, word2, calls);
    treeprint(root);

    printf("--------------------------------------------\n");
    char word3[MAXLEN] = "orange";
    root = addtree_1(root, word3, calls);
    treeprint(root);

    printf("--------------------------------------------\n");
    char word4[MAXLEN] = "grapes";
    root = addtree_1(root, word4, calls);
    treeprint(root);

    printf("--------------------------------------------\n");
    char word5[MAXLEN] = "plum";
    root = addtree_1(root, word5, calls);
    treeprint(root);

    printf("--------------------------------------------\n");
    char word6[MAXLEN] = "grapes";
    root = addtree_1(root, word6, calls);
    treeprint(root);

    printf("--------------------------------------------\n");
    char word7[MAXLEN] = "raspberry";
    root = addtree_1(root, word7, calls);
    treeprint(root);

    printf("--------------------------------------------\n");
    char word8[MAXLEN] = "peach";
    root = addtree_1(root, word8, calls);
    treeprint(root);

    printf("--------------------------------------------\n");
    char word9[MAXLEN] = "peach";
    root = addtree_1(root, word9, calls);
    treeprint(root);

    printf("--------------------------------------------\n");
    char word10[MAXLEN] = "anise";
    root = addtree_1(root, word10, calls);
    treeprint(root);

    printf("--------------------------------------------\n");
    char word11[MAXLEN] = "acai";
    root = addtree_1(root, word11, calls);
    treeprint(root);

    printf("--------------------------------------------\n");
    char word12[MAXLEN] = "aardvark";
    root = addtree_1(root, word12, calls);
    treeprint(root);
*/

    char word[MAXLEN];
    while ( getword(word, MAXLEN) != EOF ) {
        //printf("getword = [%s]\n", word);
        root = addtree_1(root, word, calls);
    }
    treeprint(root);
//    //treeprint_rev(root);

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
        p->count = 1;
        p->next = NULL;
    } else {
        p->next = addtree(p->next, w);
    }
    return p;
}

struct tnode *addtree_1(struct tnode *p, char *w, int cnt) {
    cnt++;
    //printf("\tCall no. = [%d]\n", cnt);
    int cond;
    struct tnode *ptrnext;
    if (p == NULL) {
        p = talloc();
        p->word = strduplicate(w);
        p->count = 1;
        p->next = NULL;
    } else {
        cond = strcmp(w, p->word);
        if (cond == 0) {
            p->count++;
        } else if (cond < 0) {
            if (cnt == 1) {
                // If we are here, then we are at the root node and
                // the string w should be before the root node; so
                // that's what we shall do next
                ptrnext = talloc();
                ptrnext->word = strduplicate(w);
                ptrnext->count = 1;
                ptrnext->next = p;
                p = ptrnext;
            }
            //p->next = addtree_1(p->next, w, cnt);
        } else if (cond > 0) {
            ptrnext = p->next;
            if ( ptrnext == NULL || strcmp(w, ptrnext->word) >= 0 ) {
                p->next = addtree_1(p->next, w, cnt);
            } else {
                // string w lies between p->word and ptrnext->word; so
                // add a tnode for w between p and ptrnext
                p->next = talloc();
                p->next->word = strduplicate(w);
                p->next->count = 1;
                p->next->next = ptrnext;
            }
        }
    }
    //printf("Total no. of recursive calls = [%d]\n", cnt);
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
        printf("%4d %s\n", ptr->count, ptr->word);
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

