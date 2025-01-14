/* Write a program that prints the distinct words in its input sorted into
 * decreasing order of frequency of occurrence. Precede each word by its count.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

int getword(char *, int);

/* In order to store the word frequency counts, we create two structs:
 *  struct wlist => words list, which is a linked list to store pointers
 *                  to words in tnode. When a word's frequency count increases
 *                  we remove its pointer from one clist node and add it to the
 *                  subsequent node.
 *  struct clist => counts list, which is a linked list to store counts in
 *                  decreasing order. It has a pointer to wlist.
 */

struct wlist {
    struct tnode *word;
    struct wlist *next;
};
struct clist {
    int freq;
    struct wlist *word;
    struct clist *next;
};
struct clist *cnt_alloc(void);
struct wlist *word_alloc(void);
struct wlist *addwlist(struct wlist *wl, struct tnode *tn);
struct clist *addclist(struct clist *, struct tnode *, int);
struct clist *delwlist(struct clist *, struct tnode *, int);
void printclist(struct clist *);

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
struct tnode *addtree(struct tnode *, char *, struct clist *);
struct tnode *talloc(void);
void treeprint(struct tnode *);
char *strduplicate(char *);
struct tnode *fetchnode(struct tnode *, char *);

int main(int argc, char *argv[]) {
    char word[MAXLEN];
    int ch;
    struct tnode *root;
    root = NULL;
    struct clist *clst;
    clst = NULL;
    struct tnode *latest_node;
    while ( (ch = getword(word, MAXLEN)) != EOF ) {
//printf("-----------------------------------------------------------------------\n");

//printf("Now adding: [%d|%c|%s]\n", word[0], word[0], word);

        root = addtree(root, word, clst);

//if (clst == NULL)
//    printf("clst is null\n");
//else
//    printf("\tclst = [%p], clst->freq = [%d]\n", clst, clst->freq);

latest_node = fetchnode(root, word);

//printf("\tlnode = [%p], lnode->word = [%s], lnode->count = [%d]\n", latest_node, latest_node->word, latest_node->count);

clst = addclist(clst, latest_node, latest_node->count);

    }

    //treeprint(root);
    //printf("=======================================\n");
    printclist(clst);

}

int getword(char *w, int lim) {
    int c;
    int no_char_yet = 1;
    while ((c = getchar()) != EOF && lim-- > 0) {
//printf("\t\tRead c= [%d|%c]\n", c, c);
        if ( !isalpha(c) && no_char_yet ) {
            continue;
        } else if ( isalpha(c) ) {
            if (no_char_yet)
                no_char_yet = 0;
            *w++ = c;
        } else {
            break;
        }
    }
    *w = '\0';
//printf("\tReturning c= [%d|%c], word = [%s]\n", c, c, w);
    return c;
}

struct tnode *addtree(struct tnode *p, char *w, struct clist *cl) {
    int cond;
struct clist *count_list;
struct wlist *word_list;
    if (p == NULL) {
        // Add a tnode
        p = talloc();
        p->word = strduplicate(w);
        p->count = 1;
        p->left = p->right = NULL;

//        cl = addclist(cl, p, 1);
//printf("\tcl = [%p], cl->freq = [%d]\n", cl, cl->freq);
//for (count_list = cl; count_list != NULL; count_list = count_list->next) {
//    for (word_list = count_list->word; word_list != NULL; word_list = word_list->next) {
//        printf("\t%5d %s\n", count_list->freq, word_list->word->word);
//    }
//}

    } else if ( (cond = strcmp(w, p->word)) == 0 ) {
        p->count++;
    } else if (cond < 0) {
        p->left = addtree(p->left, w, cl);
    } else if (cond > 0) {
        p->right = addtree(p->right, w, cl);
    }
    return p;
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        //printf("%5d [%d|%s]\n", p->count, *p->word, p->word);
        printf("%5d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

char *strduplicate(char *s) {
    char *p;
    p = (char *) malloc(sizeof(strlen(s)) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

struct clist *addclist(struct clist *p, struct tnode *t, int freq) {
//printf("in addclist\n");
    if (p == NULL) {
//printf("\tin p == null\n");
        p = cnt_alloc();
        p->freq = freq;
        p->word = NULL;
        p->word = addwlist(p->word, t);
        p->next = NULL;
    } else if ( freq < p->freq ) {
//printf("\tin freq < p.freq\n");
        p->next = addclist(p->next, t, freq);
    } else if ( freq == p->freq ) {
//printf("\tin freq == p.freq, freq = [%d], p.freq = [%d]\n", freq, p->freq);
        if (freq > 1) {
//printf("\t\tin freq > 1\n");
            // Delete the word from the previous (one less) freq node
            p = delwlist(p, t, freq-1);
//printf("\t\tafter call to delwlist\n");
        }
        // And add it to the current clist node
        p->word = addwlist(p->word, t);
    } else if ( freq > p->freq ) {
//printf("\tin freq > p.freq\n");
        // Add a node before the root of clist
        struct clist *ptr;
        ptr = cnt_alloc();
        ptr->freq = freq;
        ptr->word = NULL;
        ptr->word = addwlist(ptr->word, t);
        ptr->next = p;
        p = ptr;

//printf("\tabout to call delwlist\n");
        // Delete the word from clist
        p = delwlist(p, t, freq-1);

    }
    return p;
}

struct clist *cnt_alloc(void) {
    return (struct clist *)malloc(sizeof(struct clist));
}

struct wlist *addwlist(struct wlist *wl, struct tnode *tn) {
    if (wl == NULL) {
        wl = word_alloc();
        wl->word = tn;
        wl->next = NULL;
    } else {
        wl->next = addwlist(wl->next, tn);
    }
    return wl;
}

struct wlist *word_alloc(void) {
    return (struct wlist *)malloc(sizeof(struct wlist));
}

void printclist(struct clist *cl) {
    struct clist *count_list;
    struct wlist *word_list;
    for (count_list = cl; count_list != NULL; count_list = count_list->next) {
        for (word_list = count_list->word; word_list != NULL; word_list = word_list->next) {
            //printf("%5d [%s]\n", count_list->freq, word_list->word->word);
            printf("%5d %s\n", count_list->freq, word_list->word->word);
        }
    }
}

struct tnode *fetchnode(struct tnode *p, char *w) {
    // Since this function is always called after adding a node, p
    // will never be NULL.
    struct tnode *ptr;
    ptr = p;
    int cond;
    cond = strcmp(w, ptr->word);
    if (cond < 0) {
        ptr = fetchnode(ptr->left, w);
    } else if (cond > 0) {
        ptr = fetchnode(ptr->right, w);
    }
    return ptr;
}

struct clist *delwlist(struct clist *p, struct tnode *t, int freq) {
//printf("\t\tjust reached delwlist\n");
    int cond;
//printf("\t\t...after cond decl\n");
    struct wlist *ptr, *p1;
//printf("\t\t...after wlist ptrs decl\n");
    struct clist *orig_ptr;
//printf("\t\t...after clist ptrs decl, p = [%p], p.freq = [%d]\n", p, p->freq);
    orig_ptr = p;
//printf("\t\t...after orig_ptr = p, op.freq=[%d], op.word is null at this point!!\n", orig_ptr->freq);
//printf("\t\torig_ptr.freq = [%d], freq = [%d], orig_ptr.word = [%s], orig_ptr.next = [%p]\n", orig_ptr->freq, freq, orig_ptr->word->word->word);
    for (orig_ptr = p; orig_ptr != NULL; orig_ptr = orig_ptr->next) {
//printf("\t\tinside for loop; orig_ptr.freq = [%d], freq = [%d]\n", orig_ptr->freq, freq);
        if (orig_ptr->freq == freq) {
//printf("\t\t\tinside 2nd if loop; orig_ptr.freq = [%d], freq = [%d], orig_ptr.word = [%s], orig_ptr.next = [%p]\n", orig_ptr->freq, freq, orig_ptr->word->word->word);

            // If there is exactly on word at this frequency, then that is the word we have to remove, so strcmp is unnecessary.
            if (orig_ptr->word->next == NULL) {
//printf("\t\t\t\tinside if orig_ptr.word.next == null\n");
                orig_ptr->word = NULL;
                break;
            } else if ( (cond = strcmp(t->word, orig_ptr->word->word->word)) == 0 ) {
                // The first word in word_list is the one we have to delete.
                // Notice that the for loop in the "else" part below does not check for the
                // word hit on the **current** word. So, the first word is missed out, hence
                // we take care of it here.
                p1 = orig_ptr->word->next;
                orig_ptr->word = p1;
                break;
            } else {
//printf("\t\t\t\tinside else not orig_ptr.word.next == null\n");

                // Let's say the word_list is [stopping]->[by]->[woods]->[on]->[snowy]->NULL
                // We iterate from [stopping] to [on] and at each iteration, we strcmp the *next* word.
                // We have to do this because we will have access to the "next" pointer that way.
                // Otherwise, if the word we are on is the word we have to delete, then it is like chopping
                // the tree branch on which we are sitting! Not a good idea. ;-)
                //     When we are on [stopping] => we compare [by]    with the parameter
                //     When we are on [by]       => we compare [woods] with the parameter
                //     When we are on [woods]    => we compare [on]    with the parameter
                //     When we are on [on]       => we compare [snowy] with the parameter
                for (ptr = orig_ptr->word; ptr->next != NULL; ptr = ptr->next) {
                    cond = strcmp(t->word, ptr->next->word->word);
                    //printf("\t\t\t\tinside for loop; Freq = [%d], current = [%s], next = [%s], passed = [%s], cond = [%d]\n", freq, ptr->word->word, ptr->next->word->word, t->word, cond );
                    if (cond == 0) {
                        p1 = ptr->next->next;
                        ptr->next = p1;
                        //free(ptr->next);
                        break;
                    }
                } // end of for ptr wlist loop



                break;
            } // end of else

        } // end of if orig_freq = freq
    }

//    for (ptr = p->word; ptr->next != NULL; ptr = ptr->next) {
//        cond = strcmp(t->word, ptr->next->word->word);
//        printf("\tFreq = [%d], current = [%s], next = [%s], passed = [%s], cond = [%d]\n", freq, ptr->word->word, ptr->next->word->word, t->word, cond );
//        if (cond == 0) {
//            p1 = ptr->next->next;
//            ptr->next = p1;
//            //free(ptr->next);
//            break;
//        }
//    }

    return p;
}

