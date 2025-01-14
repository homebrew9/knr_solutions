#include <stdio.h>
#define MAXLEN 1000
#define SIZE 26

void print_line(int ln, char *s);
void update_lower_counts(char *s, int *arr);
void initialize_array(int *arr);
void print_frequencies(int *arr);

int main(void) {
    char str[MAXLEN];
    int lower[SIZE];
    int c, i;
    int line;
    line = 0;
    i = 0;
    initialize_array(&lower[SIZE]);
    while ( (c = getchar()) != EOF ) {
         str[i++] = c;
        if (c == '\n') {
            str[i] = '\0';
            //printf("%04d: %s", line, str);
            print_line(line, str);
            update_lower_counts(str, &lower[SIZE]);
            line++;
            i = 0;
        }
    }
    print_frequencies(&lower[SIZE]);
    return 0;
}

void print_line(int ln, char *s) {
    printf("%04d: %s", ln, s);
}

void initialize_array(int *arr) {
    int i;
    for (i = 0; i < SIZE; i++) {
        *(arr + i) = 0;
    }
}

void update_lower_counts(char *s, int *arr) {
    int i;
    i = 0;
    int offset;
    while (*(s + i) != '\0') {
        if (*(s+i) >= 97 && *(s+i) <= 122) {
            offset = *(s+i) - 'a';
            *(arr+offset) += 1;
        }
        i++;
    }
}

void print_frequencies(int *arr) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%c => %d\n", (97+i), *(arr+i));
    }
}

