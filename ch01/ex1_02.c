/* Experiment to find out what happens when printf's argument string contains \c
 * where c is some character not listed above
 */
#include <stdio.h>
main() {
  printf ("Now printing \\a => \a"); printf ("\n");
  printf ("Now printing \\b => \b"); printf ("\n");
  printf ("Now printing \\c => \c"); printf ("\n");
  printf ("Now printing \\d => \d"); printf ("\n");
  printf ("Now printing \\e => \e"); printf ("\n");
  printf ("Now printing \\f => \f"); printf ("\n");
  printf ("Now printing \\g => \g"); printf ("\n");
  printf ("Now printing \\h => \h"); printf ("\n");
  printf ("Now printing \\i => \i"); printf ("\n");
  printf ("Now printing \\j => \j"); printf ("\n");
  printf ("Now printing \\k => \k"); printf ("\n");
  printf ("Now printing \\l => \l"); printf ("\n");
  printf ("Now printing \\m => \m"); printf ("\n");
  printf ("Now printing \\n => \n"); printf ("\n");
  printf ("Now printing \\o => \o"); printf ("\n");
  printf ("Now printing \\p => \p"); printf ("\n");
  printf ("Now printing \\q => \q"); printf ("\n");
  printf ("Now printing \\r => \r"); printf ("\n");
  printf ("Now printing \\s => \s"); printf ("\n");
  printf ("Now printing \\t => |\t|"); printf ("\n");
//  printf ("Now printing \\u => \u"); // error: incomplete universal character name \u
  printf ("Now printing \\v => \v"); printf ("\n");
  printf ("Now printing \\w => \w"); printf ("\n");
//  printf ("Now printing \\x => \x"); // error: \x used with no following hex digits
  printf ("Now printing \\y => \y"); printf ("\n");
  printf ("Now printing \\z => \z"); printf ("\n");
}

