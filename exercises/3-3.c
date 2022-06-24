#include <stdio.h>
#include <stdint.h>
void expand(const char s1[], char s2[]);
int main()
{
    char s1[] = "a-bA-Zsdg2-5";
    char s2[500];
    expand(s1, s2);
    printf("%s", s2);
}

void expand(const char s1[], char s2[]) {
    char c;
    int i = 0, j = 0;
    if(!(c = s1[i]))
        return;

    while((c = s1[i++]) != '\0') {
        if(s1[i] == '-' && s1[i + 1] >= c) {
            i++;
            while(s1[i] > c)
                s2[j++] = c++;
        }
        else s2[j++] = c;
    } s2[j] = '\0';
}
