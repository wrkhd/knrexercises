#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define abs(x)  ((x) < 0 ? -(x) : (x))

void itoa(int32_t, char[]);
void reverse(char s[]);

int main() 
{
    char s[109];
    itoa(124, s);
    printf("%s", s);
    return 0;
}

void itoa(int32_t n, char s[])
{
    int i, sign;
    sign = n;
    i = 0;

    do {
        s[i++] = abs(n % 10) + '0';
    } while((n /= 10) != 0);
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}