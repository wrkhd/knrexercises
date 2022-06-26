#include <stdio.h>
#include <stdint.h>
#include <string.h>
double atof(char s[]);
int main() 
{
    char s[] = "123.45e+6";
    printf("%f", atof(s));
    return 0;
}


#include <ctype.h>
/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    int add_power = 1;
    if(s[i++] == 'e' || s[i++] == 'E') {
        s[i] == '-' ? (add_power = -1, ++i) : (add_power = 1, ++i);
        for(int k = 0, j = s[i] - '0'; k < j; k++)
            add_power *= 10;
    }
    if(add_power < 0) {
        add_power *= -1;
        return sign * val / (add_power * power);
    }
    return sign * val * add_power / power;
}