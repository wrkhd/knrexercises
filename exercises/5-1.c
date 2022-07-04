#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 1000

int getch(void);
void ungetch(int);
int getint(int *pn);
char buf[BUFSIZE]; /* buffer for ungetch */
int buf_position = 0; /* next free position in buf */

int main()
{
    int x = 4;
    printf("%d", getint(&x));
    return 0;
}
/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if(!isdigit(c)) {
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c), c = getch();)
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    else
        return c;
}

int getch(void) /* get a (possibly pushed-back) character */
{
    return (buf_position > 0) ? buf[--buf_position] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (buf_position >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[buf_position++] = c;
}
