#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // char
    printf("CHAR_MAX = %d\n", CHAR_MAX);
    printf("CHAR_MIN = %d\n", CHAR_MIN);
    printf("UCHAR_MAX = %u\n", UCHAR_MAX);

    // short
    printf("SHRT_MAX = %d\n", SHRT_MAX);
    printf("SHRT_MIN = %d\n", SHRT_MIN);
    printf("USHRT_MAX = %u\n", USHRT_MAX);

    // int
    printf("INT_MAX = %d\n", INT_MAX);
    printf("INT_MIN = %d\n", INT_MIN);
    printf("UINT_MAX = %u\n", UINT_MAX);

    // long
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LONG_MIN = %ld\n", LONG_MIN);
    printf("ULONG_MAX = %lu\n", ULONG_MAX);

    // long long
    printf("LLONG_MAX = %lld\n", LLONG_MAX);
    printf("LLONG_MIN = %lld\n", LLONG_MIN);
    printf("ULLONG_MAX = %llu\n", ULLONG_MAX);

    // float
    printf("FLT_MAX = %e\n", FLT_MAX);
    printf("FLT_MIN = %e\n", FLT_MIN);

    // double
    printf("DBL_MAX = %le\n", DBL_MAX);
    printf("DBL_MIN = %le\n", DBL_MIN);

    return 0;
}
