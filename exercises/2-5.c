#include <stdio.h>
#include <stdbool.h>

#define IN 1
#define OUT 0

int any(const char s1[], const char s2[]);

int main()
{
    char s1[] = "hello, t";
    char s2[] = " ";
    printf("%d", any(s1, s2));
    return 0;
}

int any(const char s1[], const char s2[]) {
    bool state = OUT;

    for(int i = 0; s1[i] != '\0'; i++) {
        for(int j = 0; s2[j] != '\0'; j++) {
            if(s1[i] == s2[j]) {
                state = IN;
                break;
            }
        }
        if(state == IN)
            return i;
    }
    return -1;
}
