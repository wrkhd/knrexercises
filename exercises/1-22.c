#include <stdio.h>
#include <stdbool.h>

// It's actually 51
#define MAXSIZE 50
#define MAX_POSSIBLE 1000
#define SEARCH_AREA 10
#define IN  1
#define OUT 0

void fold(int size, char s[]);

int main()
{
    char arr[MAX_POSSIBLE];
    int c, n = 0;
    while((c = getchar()) != EOF) {
        if(c == '\n') {
            fold(n, arr);
            n = 0;
        } else {
            arr[n] = c;
            n++;
        }
    }
    return 0;
}

void fold(int size, char s[])
{
    if(size <= 50) {
        for(int i = 0; i < size; i++)
            printf("%c", s[i]);
        printf("%c", '\n');
        return;
    }

    int area_min = MAXSIZE - SEARCH_AREA;
    int area_max = MAXSIZE;
    bool state = OUT;

    for(int i = 0 ; i < size; i++) {
        if(i == area_min)
            state = IN;

        if (state == OUT) {
            printf("%c", s[i]);

        }
        else {
            if (i < area_max) {

                if (s[i] == ' ') {
                    printf("%c", '\n');
                    state = OUT;
                    area_min += MAXSIZE;
                    area_max += MAXSIZE;
                } else printf("%c", s[i]);
            }

            else if (i == area_max) {
                printf("%c\n", '-');
                printf("%c", s[i]);
                state = OUT;
                area_min += MAXSIZE;
                area_max += MAXSIZE;
            }
        }
    }
}