#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVALUE 100 /* maximum depth of value_stack */
#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
double fmod(double, double);

char buf[BUFSIZE]; /* buffer for ungetch */
int buf_position = 0; /* next free position in buf */
int stack_position = 0; /* next free stack position */
double value_stack[MAXVALUE]; /* value stack */

int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                push(fmod(pop(), op2));
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void push(double f)
{
    if (stack_position < MAXVALUE)
        value_stack[stack_position++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (stack_position > 0)
        return value_stack[--stack_position];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
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

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
        ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

double fmod(double x, double y) {
    return x - (int)(x/y) * y;
}