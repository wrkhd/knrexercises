#include <stdio.h>
#include <limits.h>
#include <float.h>
int main()
{
    printf("%d %d %u\n", INT_MIN, INT_MAX, UINT_MAX);
    printf("%d %d %u\n", SHRT_MIN, SHRT_MAX, USHRT_MAX);
    printf("%ld %ld %lu\n", LONG_MIN, LONG_MAX, ULONG_MAX);
    printf("%lld %lld %llu\n", LLONG_MIN, LLONG_MAX, ULLONG_MAX);

    printf("%.10e %.10e\n", FLT_MIN, FLT_MAX);
    printf("%.10e %.10e\n\n", DBL_MIN, DBL_MAX);

    return 0;
}


