#include <stdio.h>
int htoi(const char s[]);

int main()
{
    char s[] = "0xAB1";
    printf("%d", htoi(s));
    return 0;
}

int htoi(const char s[]) {
    int number = 0;
    int i = 0;
    int mult = 1;

    if(s[i] == '\0')
        return 0;
    if(s[i] == '0') {
        i++;
        if(s[i] == '\0')
            return 0;
        else if(s[i] == 'x' || s[i] == 'X')
            i++;
    } else if(s[i] == '\0')
        return 0;

    while(s[i] != '\0') {
        i++;
    } i--;

    while(i >= 0) {
        if(s[i] == 'x' || s[i] == 'X')
             break;
        if(s[i] >= '0' && s[i] <= '9')
            number += (s[i] - '0') * mult;
        else if(s[i] >= 'a' && s[i] <= 'f')
            number += (s[i] - 'a' + 10) * mult;
        else if(s[i] >= 'A' && s[i] <= 'F')
            number += (s[i] - 'A' + 10) * mult;
        mult *= 16;
        i--;
    }
    printf("%c %d %d %d\n", s[i], number, mult, i);

    return number;
}
