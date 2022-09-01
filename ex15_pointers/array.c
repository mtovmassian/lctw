#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const int ARRAY_LENGTH = 5;
    int *array = (int*) malloc(sizeof(int) * ARRAY_LENGTH);

    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    *(array + 4) = 5;

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%d\n", array[i]);
    }

    free(array);

    return 0;
}
