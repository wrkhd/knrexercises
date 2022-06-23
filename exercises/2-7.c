#include <stdio.h>
#include <stdint.h>

int invert(uint32_t, uint32_t, uint32_t);
void base_2(int n);

int main()
{
    base_2(0xDEADBEEF);
    base_2(invert(0xDEADBEEF, 5, 7));
    return 0;
}

int invert(uint32_t x, uint32_t p, uint32_t n) {
    for(int i = p; i < p + n; i++) {
        x = x ^ (1 << i);
    }
    return x;
}

void base_2(int n) {
    int k = 0;
    for (int c = 31; c >= 0; c--) {
        k = n >> c;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}