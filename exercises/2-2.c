#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
enum boolean{ OUT, IN } ;
int main()
{
    bool state = IN;
    int32_t i = 0;
    int32_t lim = 1000;
    int8_t s[1000];

    while(state) {
        int8_t c = getchar();
        if(i >= lim - 1)
            state = OUT;
        else if(c == '\n')
            state = OUT;
        else if(c == EOF)
            state = OUT;
        else {
            s[i] = c;
            i++;
        }
    }
    return 0;
}
