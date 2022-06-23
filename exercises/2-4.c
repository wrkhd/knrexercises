#include <stdio.h>
#include <stdbool.h>

#define IN 1
#define OUT 0
void squeeze(char s1[], const char s2[]);

int main()
{
    char s1[] = "hello, t";
    char s2[] = "eo";
    squeeze(s1, s2);
    printf("%s", s1);
    return 0;
}

void squeeze(char s1[], const char s2[]) {
    int i = 0, j = 0;
    bool state;

    while(s1[i] != '\0') {
        state = OUT;
        for(int k = 0; s2[k] != '\0'; k++) {
            if(s1[i] == s2[k]) {
                state = IN;
                break;
            }
        }

        if(state == IN) {
            i++;
        } else {
            s1[j++] = s1[i++];
        }

    }
    s1[j] = '\0';
}

