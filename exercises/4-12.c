#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

void itoa(int32_t);
char s[100];
int32_t count;

int main()
{
    itoa(3214);
    printf("%s", s);
    return 0;
}

void itoa(int32_t x)
{
    extern char s[];
    if(x < 0) {
        s[count++] = '-';
        x = -x;
    }

    if(x / 10)
        itoa(x / 10);
    s[count++] = x % 10 + '0';
    s[count] = '\0';
    printf("a%d\n", count);
}
