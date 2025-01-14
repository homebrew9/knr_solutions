/* The binary tree program from the Section 6.5 Self-referential structures
 * in KnR. I use my modified getword routine from ex6_01_v1.c here.
 * New concepts: malloc, talloc, strduplicate, self-referential structure.
 * I used a variation on the name of strdup because it conflicted with a
 * definition in the header file "string.h"
 * Usage:
 *     ./btree < test_file_for_btree.txt
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

int getword(char *, int);
int getch(void);
void ungetch(int c);

struct tnode {              /* the tree node: */
    char *word;             /* points to the text */
    int count;              /* number of occurrences */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

/* word frequency count */
int main(int argc, char *argv[]) {
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        //printf("%s\n", word);
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
char *strduplicate(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;
    if (p == NULL) {                        /* a new word has arrived */
        p = talloc();                       /* make a new node */
        p->word = strduplicate(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ( (cond = strcmp(w, p->word)) == 0 ) {
        p->count++;                         /* repeated word */
    } else if (cond < 0) {                  /* less than into left subtree */
        p->left = addtree(p->left, w);
    } else {                                /* greater than into right subtree */
        p->right = addtree(p->right, w);
    }
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strduplicate(char *s) {    /* make a duplicate of s */
    char *p;
    p = (char *) malloc(strlen(s) + 1);    /* +1 for '\0' */
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    /* In order to disregard single and multi line comments, we declare
     * variables as follows. They are all defaulted to 0 (false).
     */
    int in_mlc = 0;  // multi line comment
    int in_slc = 0;  // single line comment

    int temp;

    for ( ; ; )
    {
        c = getch();
        if ( lim == MAXWORD && isspace(c) && in_mlc == 0 && in_slc == 0 ) {
            ;
        } else if ( c == '/' && (in_mlc == 0 || in_slc == 0) ) {
            temp = c;
            c = getch();
            if (c == '*') {
                in_mlc = 1;
            } else if (c == '/') {
                in_slc = 1;
            } else {
                lim--;
                *w++ = temp;
                ungetch(c);
                *w = '\0';
                return word[0];
            }
        } else if (in_mlc == 1 && c == '*') {
            c = getch();
            if (c == '/')
                in_mlc = 0;
        } else if (in_slc == 1 && c == '\n') {
            in_slc = 0;
        } else if (in_mlc == 1 || in_slc == 1) {
            continue;
        } else if ( !isalpha(c) && c != '_' ) {
            *w++ = c;
            *w = '\0';
            return c;
        } else {
            *w++ = c;
            if (--lim <= 0) {
                *w = '\0';
                return c;
            }
        }
    }
}

#define BUFSIZE 100
char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void) {     /* get a (possibly pushed back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters!\n");
    } else {
        buf[bufp++] = c;
    }
}

