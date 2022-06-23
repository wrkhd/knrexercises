#include <stdio.h>
#include <stdint.h>

int bitcount(uint32_t);

int main()
{
    printf("%d", bitcount(0xF1));
    return 0;
}

int bitcount(uint32_t number) {
    int count = 0;

    while(number != 0) {
        number = number & (number - 1);
            count++;
    }

    return count;
}