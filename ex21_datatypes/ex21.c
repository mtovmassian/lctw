#include <stdlib.h>
#include <stdio.h>
#include "/usr/include/stdint.h"
#include "/usr/include/math.h"

long unsigned int guess_short_size()
{
    return sizeof(int16_t);
}

int check_short_size()
{
    return guess_short_size() == sizeof(short);
}

unsigned int guess_short_max_value_unsigned()
{
    return (unsigned int) (pow(2, sizeof(short) * 8) - 1);
}

int check_short_max_value_unsigned()
{
    return guess_short_max_value_unsigned() == UINT16_MAX;
}

int guess_short_max_value()
{
    return guess_short_max_value_unsigned() / 2;
}

int check_short_max_value()
{
    return guess_short_max_value() == INT16_MAX;
}

void explore_short() {
    
}

long unsigned int guess_int_size()
{
    return sizeof(int32_t);
}

int check_int_size()
{
    return guess_int_size() == sizeof(int);
}

unsigned int guess_int_max_value_unsigned()
{
    return (unsigned int) ((pow(2, sizeof(int) * 8) - 1));
}

int check_int_max_value_unsigned()
{
    return guess_int_max_value_unsigned() == UINT32_MAX;
}

int guess_int_max_value()
{
    return guess_int_max_value_unsigned() / 2;
}

int check_int_max_value()
{
    return guess_int_max_value() == INT32_MAX;
}

int main(int argc, char *argv[])
{
    printf("This computer processor word size is %d bits\n", __WORDSIZE);

    printf("short\n");
    if (check_short_size()) {
        printf("    short is %lu bits\n", guess_short_size() * 8);
    }
    if (check_short_max_value_unsigned()) {
        printf("    short max value unsigned is %u\n", guess_short_max_value_unsigned());
    } else {
        printf("    :( wrong guess for short max value unsigned.\n");
    }
    if (check_short_max_value()) {
        printf("    short max value is %d\n", guess_short_max_value());
    } else {
        printf(" :( wrong guess short max value is ...\n");
    }

    printf("int\n");
    if (check_int_size()) {
        printf("    int is %lu bits\n", guess_int_size() * 8);
    }
    if (check_int_max_value_unsigned()) {
        printf("    int max value unsigned is %u\n", guess_int_max_value_unsigned());
    }
    if (check_int_max_value()) {
        printf("    int max value is %d\n", guess_int_max_value());
    }


    return 0;
}

