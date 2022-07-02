#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int strend(char *, char *);

int main()
{
    char a1[] = "hacai";
    char a2[] = "haai";
    char *s = a1;
    char *t = a2;
    printf("%d", strend(s, t));
    return 0;
}

int strend(char *s, char *t)
{
    char *bs = s;
    char *bt = t;

    while(*s++);
    while(*t++);
    s--;
    t--;

    while(*s-- == *t--) {
        //printf("%c %c", *s);
        if(bs == s || bt == t)
            break;
    }

    if(*s == *t && t == bt && *s != '\0')
        return 1;
    else 
        return 0;
}