#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
// It's unclear how to write this without supplying array size as a parameter...
int htoi(const char s[], int size);
int main()
{
    char s[] = "0xAB1";
    int size = sizeof(s)/sizeof(s[0]) - 1;
    printf("%d", htoi(s, size));
    return 0;
}

int htoi(const char s[], int size) {
    int number = 0;
    int bs = 1;
    for(int i = size - 1; i >= 0; i--) {
        if(i != size - 1)
            bs *= 16;
        if(s[i] >= '0' && s[i] <= '9')
            number += bs * (s[i] - '0');
        else if(s[i] >= 'a' && s[i] <= 'f')
            number += bs * (s[i] - 'a' + 10);
        else if(s[i] >= 'A' && s[i] <= 'F')
            number += bs * (s[i] - 'A' + 10);
    }
    return number;
}
