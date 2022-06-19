#include <stdio.h>
#define TAB_SPACES 4

void entab(int length);

int main()
{
    int c, n;
    while((c = getchar()) != EOF) {
        if(c == ' ') {
            n++;
        }
        else {
            entab(n);
            printf("%c", c);
            n = 0;
        }
    }
    return 0;
}

void entab(int length)
{
    int tabs = length / TAB_SPACES;
    int blanks = length - tabs * TAB_SPACES;
    for(int i = 0; i < tabs; i++)
        printf("%c", '\t');
    for(int i = 0; i < blanks; i++)
        printf("%c", ' ');
}