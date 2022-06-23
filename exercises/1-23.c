#include <stdio.h>
#include <stdbool.h>

#define IN  1
#define OUT 0

int main()
{
    int c;
    bool double_slash_state = OUT, slash_star_state = OUT;
    char temp = ' ';
    while((c = getchar()) != EOF) {
        if(c == '/' && temp == ' ') {
            temp = c;
            printf("%d", 1);
        }
        else if(c == '/' && temp == '/') {
            double_slash_state = IN;
            temp = ' ';
            printf("%d", 2);
        }
        else if(c == '*' && temp == '/') {
            slash_star_state = IN;
            temp = ' ';
            printf("%d", 3);
        }
        else if(c == '\n' && double_slash_state) {
            double_slash_state = OUT;
            temp = ' ';
            printf("%d", 4);
        }
        else if(c == '*' && slash_star_state == IN) {
            temp = c;
            printf("%d", 5);
        }
        else if(temp == '*' && c != '/') {
            temp = ' ';
            printf("%d", 6);
        }
        else if(c == '/' && temp == '*') {
            slash_star_state = OUT;
            temp = ' ';
            printf("%d", 7);
        }
        else if(slash_star_state == OUT && double_slash_state == OUT && temp == ' ')
            printf("%c", c);
    }
    return 0;
}
