#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint-gcc.h>
int32_t manup(int32_t(*func)(int32_t, int32_t), int32_t a, int32_t b, int32_t c);
int main(int arhc, char *argv[])
{
    int add(int32_t, int32_t);
    int mult(int32_t, int32_t);
    int (*func_p)(int32_t, int32_t) = mult;
    printf("%d\n", manup(func_p, 2, 3, 5));
    return 0;
}

int32_t add(int32_t a, int32_t b) 
{
    return a + b;
}

int32_t mult(int32_t a, int32_t b)
{
    return a * b;
}

int32_t manup(int32_t(*func)(int32_t, int32_t), int32_t a, int32_t b, int32_t c)
{
    return ((*func)(a, b)) * c;  
}