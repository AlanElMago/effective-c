#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include <math.h>

/* I changed the definition of the show_classification() function as shown in
 * the book; it takes a float as an argument instead of a double. The reason
 * is that it is easier to experiment with floats than it is with doubles.
 */

const char *show_classification(float x);

int main(void)
{
    // note: the results may vary between different platforms and machines

    uint32_t i1  = 0x3f800000;   //  1.0f
    uint32_t i2  = 0xbf800000;   // -1.0f
    uint32_t i3  = 0x00000000;   //  0.0f
    uint32_t i4  = 0x80000000;   // -0.0f
    uint32_t i5  = 0x00800000;   //  1.175494e-38 (normal as a float)
    uint32_t i6  = 0x007fffff;   //  1.175494e-38 (subnormal as a float)
    uint32_t i7  = 0x00000001;   //  1.401298e-45 (subnormal as a float)
    uint32_t i8  = 0x7fffffff;   //  nan (as a float)
    uint32_t i9  = 0xffffffff;   // -nan (as a float)
    uint32_t i10 = 0x7f800000;   //  inf (as a float)
    uint32_t i11 = 0xff800000;   // -inf (as a float)

    float f1  = *(float *) &i1;
    float f2  = *(float *) &i2;
    float f3  = *(float *) &i3;
    float f4  = *(float *) &i4;
    float f5  = *(float *) &i5;
    float f6  = *(float *) &i6;
    float f7  = *(float *) &i7;
    float f8  = *(float *) &i8;
    float f9  = *(float *) &i9;
    float f10 = *(float *) &i10;
    float f11 = *(float *) &i11;

    printf("% f: %s\n", f1 , show_classification(f1));
    printf("% f: %s\n", f2 , show_classification(f2));
    printf("% f: %s\n", f3 , show_classification(f3));
    printf("% f: %s\n", f4 , show_classification(f4));
    printf("% e: %s\n", f5 , show_classification(f5));
    printf("% e: %s\n", f6 , show_classification(f6));
    printf("% e: %s\n", f7 , show_classification(f7));
    printf("% e: %s\n", f8 , show_classification(f8));
    printf("% e: %s\n", f9 , show_classification(f9));
    printf("% e: %s\n", f10, show_classification(f10));
    printf("% e: %s\n", f11, show_classification(f11));

    return 0;
}

const char *show_classification(float x)
{
    switch (fpclassify(x)) {
        case FP_INFINITE:   return "Inf";
        case FP_NAN:        return "NaN";
        case FP_NORMAL:     return "normal";
        case FP_SUBNORMAL:  return "subnormal";
        case FP_ZERO:       return "zero";
        default:            return "unknown";
    }
}
