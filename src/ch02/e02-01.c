/* Exercise 01 from chapter 02.
 * Add a retrieve function to the counting example from Listing 2-6 to
 * retrieve the current value of the counter.
 */

#include <stdio.h>

void increment(void);
int retrieve(void);

int main(void)
{
    for ( int i = 0; i < 5; i++ )
        increment();

    printf("\nretrieve() = %i\n", retrieve());

    return 0;
}

void increment(void)
{
    static unsigned int counter = 0;

    counter++;

    printf("%d ", counter);
}

/* I wanted to challenge myself to see if I could access the counter variable
 * that is defined in the increment() function WITHOUT changing the definition
 * or implementation of said function and WITHOUT using any global variables.
 * The resulting retrieve() function is that which accesses the memory
 * location that stores the value of the counter variable.
 *
 * For example:
 * Address of counter variable from the increment() function: 0x5642905f8014
 * Address of result  variable from the retrieve()  function: 0x5642905f8018
 * Address pointed to by the expression *(&result - 1): 0x5642905f8014
 *
 * Because counter and result are both zero-initialized static variables, they
 * are stored in the same section of memory (specifically the .BSS section).
 * Being that they are also the ONLY two zero-initialized static variables,
 * they are stored right next to each other. The counter variable will have a
 * lower address than the result variable, as it is the first one being
 * declared. Thanks to this knowledge, I knew that I could access the value
 * of the counter variable by subtracting 1 from the address of the result
 * variable then dereferencing it, thus: *(&result - 1) == *(&counter).
 *
 * This was a fun challenge, however, this is a HORRIBLE IDEA AND MUST NEVER
 * BE CONCIEVED BY ANY PROGRAMMER WHO IS MENTALLY SANE.
 *
 * Note: this code was tested on a linux platform using the gcc compiler on a
 * 64-bit computer. It might not work on other platforms or machines.
 */
int retrieve(void)
{
    static unsigned int result = 0;

    return *(&result - 1);
}
