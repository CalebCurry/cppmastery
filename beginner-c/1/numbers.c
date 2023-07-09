#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
    printf("signed short:  %i \n", SHRT_MAX);
    printf("Unsigned short:  %i \n", USHRT_MAX);
    printf("signed int:  %i \n", INT_MAX);
    printf("unsigned int: %u \n", UINT_MAX);
    printf("signed long: %li \n", LONG_MAX);
    printf("unsigned long: %lu \n", ULONG_MAX);
    printf("long long: %llu \n", LLONG_MAX);
    printf("unsigned long long: %llu \n", ULLONG_MAX);
    printf("float: %f \n", FLT_MAX);
    printf("double: %lf \n", DBL_MAX);
    printf("long double: %Lf \n", LDBL_MAX);

    printf("%lu \n", sizeof(short));
    printf("%lu \n", sizeof(unsigned short));
    printf("%lu \n", sizeof(int));
    printf("%lu \n", sizeof(unsigned int));
    printf("%lu \n", sizeof(long int));
    printf("%lu \n", sizeof(unsigned long int));
    printf("%lu \n", sizeof(long long int));
    printf("%lu \n", sizeof(unsigned long long int));
    printf("%lu \n", sizeof(float));
    printf("%lu \n", sizeof(double));
    printf("%lu \n", sizeof(long double));
    return 0;
}