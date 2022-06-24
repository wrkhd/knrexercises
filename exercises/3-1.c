#include <stdio.h>
#include <stdint.h>

int binsearch(int32_t, const int32_t[], int32_t);

int main()
{
    int32_t s[] = {1, 2, 4, 5, 6, 8, 9};
    int32_t n = sizeof(s)/sizeof(s[0]);
    printf("%d", binsearch(5, s, n));
}

int binsearch(int32_t x, const int32_t v[], int32_t n) {
    int32_t high, low, mid;
    low = 0;
    high = n - 1;
    while(low <= high && x != v[mid]) {
        mid = low + high / 2;
        if(x > v[mid])
            low = mid + 1;
        else
            high = mid + 1;
    }
    if(x == v[mid])
        return mid;
    else
        return -1;
}

