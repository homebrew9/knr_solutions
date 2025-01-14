/* Bare-bones version of wc. From K&R, section 1.5.4
 * Usage: ./wordcount < sample_file.txt
 *        ./wordcount < error_prone.txt
 */
#include <stdio.h>
#define IN  1  /*  inside a word */
#define OUT 0  /* outside a word */
/* count lines, words, and characters in input */
main () {
  int c, nl, nw, nc, state;
  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf ("%d %d %d\n", nl, nw, nc);
}

/* Exercise 1-11:
 * How would you test the word count program?
 * - By passing a sample file as a stream to the program.
 *
 * What kinds of input are most likely to uncover bugs if there are any?
 * - Since a blank space, newline or tab is considered a word "boundary",
 * a word that is spread out on two lines, separated by a hyphen will not
 * be counted correctly by this program.
 * As an example, the following sentence has 8 words ("error-prone" is a
 * single word), but this program reports 9 words, as does "wc".
 *
 * This input will result in an error-
 * prone output.
 *
 */
