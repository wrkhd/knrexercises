#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define swap(t, x, y) { \
t _z = y;                \
y = x;                   \
x = _z; }

int main()
{
    int32_t x = 2, y = 3;
    swap(int32_t, x, y);
    printf("%d", x);
    return 0;
}