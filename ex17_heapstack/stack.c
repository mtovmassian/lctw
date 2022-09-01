#include <stdio.h>
#include <stdlib.h>

const int STACK_TOP_INITIAL = -1;
int STACK_TOP;

int STACK_SIZE;
int *STACK;

void Stack_init(int stack_size)
{
    STACK_TOP = STACK_TOP_INITIAL;
    STACK_SIZE = stack_size;
    STACK = malloc(sizeof(int) * stack_size);
}

void Stack_free()
{
    free(STACK);
}

int Stack_is_empty() {
    return STACK_TOP == STACK_TOP_INITIAL;
}

void Stack_print()
{
    if (Stack_is_empty()) {
        printf("[ ]\n");
    } else {
        printf("[ ");
        for (int i = STACK_TOP; i >=1; i--) {
            printf("%d, ", STACK[i]);
        }
        printf("%d ]\n", STACK[0]);
    }
}

void Stack_push(int item)
{
    if (STACK_TOP == STACK_SIZE - 1) {
        printf("Impossible to push: stack overflow!\n");
    } else {
        STACK_TOP++;
        STACK[STACK_TOP] = item;
    }
}

void Stack_pop()
{
    if (Stack_is_empty()) {
        printf("Impossible to pop: stack underflow\n");
    } else {
        int item_popped = STACK[STACK_TOP];
        printf("Popped item: %d\n", item_popped);
        STACK[STACK_TOP] = 0;
        STACK_TOP--;
    }
}

int main(int argc, char *argv[])
{
    Stack_init(5);

    Stack_push(1);
    Stack_push(2);
    Stack_push(3);
    Stack_push(4);
    Stack_push(5);
    Stack_push(6);

    Stack_print();

    Stack_pop();
    Stack_pop();

    Stack_print();
    Stack_free();

    return 0;
}
