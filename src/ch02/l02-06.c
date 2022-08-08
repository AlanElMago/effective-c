#include <stdio.h>

void increment(void);

int main(void)
{
    for ( int i = 0; i < 5; i++ )
        increment();

    printf("\n");

    return 0;
}

void increment(void)
{
    static unsigned int counter = 0;

    counter++;

    printf("%d ", counter);
}
