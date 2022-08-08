/* Exercise 02 from chapter 02.
 * Declare an array of three pointers to functions and invoke the appropriate
 * function based on an index value passed in as an argument.
 */

#define ARR_LEN 3   // length of the array

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b);  // function that adds two integers: a + b
int sub(int a, int b);  // function that subtracts two integers: a - b
int mul(int a, int b);  // function that multiplies two integers: a * b

int main(int argc, char **argv)
{
    // make sure two arguments have been passed to the program
    if ( argc != 3 ) {
        fprintf(stderr, "Usage: e02-02 a b\n");
        return EXIT_FAILURE;
    }

    // convert the arguments to integers and store them to a and b
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    // create an array of function pointers "ops" of length ARR_LEN that
    // contain pointers to the functions add, sub, and mul
    int (*ops[ARR_LEN]) (int a, int b) = { &add, &sub, &mul };

    // iterate all through all the functions contained in the array of
    // function pointers "ops" passing a and b as the arguments 
    for ( int i = 0; i < ARR_LEN; i++ )
        fprintf(stdout, "ops[%i](%i, %i) = %i\n", i, a, b, ops[i](a, b));

    return EXIT_SUCCESS;
}

/* Function implementations */

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}
