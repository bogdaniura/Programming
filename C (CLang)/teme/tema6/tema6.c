#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[200] = {0}, b[200] = {0}, s[200] = {0}, i, t = 0;

int suma(char *x[200], char *y[200]) {
    char z[200];
    if ((a[0] < b[0]) || (a[0] == b[0]) && (strcmp(x, y) < 0)) {
        strcpy(z, x);
        strcpy(x, y);
        strcpy(y, z);
        a[0] = strlen(x);
        b[0] = strlen(y);
    }
    if (a[0] > b[0])
        s[0] = a[0];
    else
        s[0] = b[0];

    for (i = 1; i <= a[0]; i++) a[i] = x[a[0] - i] - '0';

    for (i = s[0]; i > 0; i--) printf("%d ", a[i]);
    printf("\n");

    for (i = 1; i <= b[0]; i++) b[i] = y[b[0] - i] - '0';

    for (i = s[0]; i > 0; i--) printf("%d ", b[i]);
    printf("\n");

    for (i = 1; i <= s[0]; i++) {
        s[i] = (a[i] + b[i] + t) % 10;
        t = (a[i] + b[i] + t) / 10;
    }

    if (t) {
        s[0]++;
        s[s[0]] = t;
    }
    for (i = s[0]; i > 0; i--) printf("%d ", s[i]);
}

int main() {
    char x[200], y[200], z[200];
    printf("Primul numar = ");
    gets(x);
    printf("Al doilea numar = ");
    gets(y);
    a[0] = strlen(x);
    printf("%d\n", a[0]);
    b[0] = strlen(y);
    printf("%d\n", b[0]);
    suma(x, y);
    printf("\n");

    return 0;
}
