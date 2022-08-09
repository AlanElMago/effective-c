#include <stdio.h>
#include <limits.h>

int main(void)
{
    unsigned int ui = UINT_MAX;     // 4,294,967,295 on x86

    ui++;

    printf("ui = %u\n", ui);        // ui is 0

    ui--;

    printf("ui = %u\n", ui);        // ui is 4,294,967,295

    return 0;
}
