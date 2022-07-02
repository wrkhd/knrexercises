#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void strcat(char *, char *);
int main()
{
    char a1[] = "hi there '\0'         ";
    char a2[] = ", I'm here";
    char *s = a1;
    char *t = a2;
    strcat(s, t);
    printf("%s", s);
    return 0;
}


void strcat(char *s, char *t) {
    while(*s++);
    --s;
    while(*s++ = *t++);
}