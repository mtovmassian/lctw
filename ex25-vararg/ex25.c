#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "dbg.h"

#define MAX_DATA 100

int read_string(char **out_string, int max_buffer)
{
    *out_string = calloc(1, max_buffer + 1);
    check_mem(*out_string);

    char *result = fgets(*out_string, max_buffer, stdin);
    check(result != NULL, "Input error.");

    return 0;

error:
    if (out_string) free(out_string);
    out_string = NULL;
    return -1;
}

void set_char_ptr(char *ptr)
{
    ptr = "toto";
}

int main(int argc, char **argv)
{
    char *first_name = NULL;
    read_string(&first_name, MAX_DATA);

    printf("%s\n", first_name);
    free(first_name);

    return 0;
}
