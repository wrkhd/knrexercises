#include <stdio.h>
#include <stdint.h>
#include <string.h>
int main() 
{
    return 0;
}


int strindex(char s[], char t[]) {
    int i, j, k, res = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if (k > 0 && t[k] == '\0')
            res = i;
    }
    return res;
}