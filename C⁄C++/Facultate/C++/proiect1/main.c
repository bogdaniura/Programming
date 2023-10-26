#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1 = 5, a2 = 27, a3 = 186;
    float b1 = 11.22, b2 = 222.333, b3 = 3333.4444;
    double c1 = 44.55, c2 = 555.666, c3 = 666.777;
    char *d1 = "A", *d2 = "B", *d3 = "C";

    printf("\tHello world!\n");
    printf("my 3 favourite numbers are:\n%d\n%f\n%.1lf\nand my favourite letter is %c", a1, b1, c3, d1);
    return 0;
}
