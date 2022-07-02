#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void reverse(char *s);
int main()
{
    char a1[] = "hi there";
    char a2[] = ", I'm here";
    char *s = a1;
    char *t = a2;
    reverse(s);
    printf("%s", s);
    return 0;
}

void reverse(char *s) 
{
    char *t = s;
    char temp;
    for(; *s; s++);
    s--;
    
    for(; t < s; t++, s--) {
        temp = *s;
        *s = *t;
        *t = temp;        
    }
}