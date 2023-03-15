#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void pb1() {
    int c = 2, n;
    scanf("Introduceti un numar: %d", &n);
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            c++;
        }
    }
    printf("%d", c);
}

int main() {
    pb1();
}