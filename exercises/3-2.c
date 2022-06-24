#include <stdio.h>
#include <stdint.h>
// t is assumed to be big enough to copy modified s array.
void escape(char s[], char t[]);
int main()
{
    char s[] = "he  dklx        mdl,xm";
    s[5] = '\t';
    s[12] = '\n';
    s[17] = '\t';
    char t[100];
    escape(s, t);
    printf("%s", t);
}

void escape(char s[], char t[]) {
    int i, j;
    for(i = 0, j = 0; s[i]; i++) {
        switch (s[i]) {
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
                // and so on...
            default:
                t[j++] = s[i];
                break;
        }
    }
}


