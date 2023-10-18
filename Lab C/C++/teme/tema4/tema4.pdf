#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool prim(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void pb1() {
    int c = 2, n;
    printf("introduceti un numar: ");
    scanf("%d", &n);
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            c++;
        }
    }
    printf("%d", c);
}

void pb2() {
    int n, c = 0, dlpmax = 0, pmax = 0;
    printf("introduceti un numar: ");
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            int p = 0;
            while (n % i == 0) {
                n /= i;
                p++;
            }
            if (p > pmax) {
                pmax = p;
                dlpmax = i;
            }
            c++;
        }
    }
    printf("%d %d", dlpmax, pmax);
    printf("\n%d", c);
}

void pb3() {
    int m, n;
    printf("introduceti doua numere: ");
    scanf("%d%d", &m, &n);
    while (m < n) {
        m *= m;
    }
    if (m == n) {
        printf("DA");

    } else {
        printf("NU");
    }
}

void pb4() {  // trebuie rulat cu -lm pe unele compilatoare
    int n, e, nrp = 0, sumn = 0, prodp = 1;
    printf("introduceti un numar: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("introduceti mai multe numere: ");
        scanf("%d", &e);
        if (e > 0) {
            nrp++;
        }
        if (e < 0) {
            sumn += e;
        }
        if ((int)sqrt(e) == sqrt(e)) {
            prodp *= e;
        }
    }
    printf("%d %d %d", nrp, sumn, prodp);
}

void pb5() {
    int n, maxim = 0, e, fmax = 0;
    printf("introduceti un numar: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("introduceti mai multe numere: ");
        scanf("%d", &e);
        if (e > maxim) {
            maxim = e;
            fmax = 0;
        }
        if (e == maxim) {
            fmax++;
        }
    }
    printf("%d %d", maxim, fmax);
}

void pb6() {
    int d, i, r, cmmmc;
    printf("introduceti doua numere: ");
    scanf("%d%d", &d, &i);
    int aux_d = d, aux_i = i;
    do {
        r = d % i;
        d = i;
        i = r;
    } while (r != 0);
    printf("%d", d);

    cmmmc = ((aux_d * aux_i) / d);
    printf(" %d", cmmmc);
}

void pb7() {
    int n;
    printf("introduceti un numar: ");
    scanf("%d", &n);
    do {
        n++;
    } while (!prim(n));
    printf("%d", n);
}

void pb8() {
    int n, u, s = 0, np = 0, npo = 0, umax = -1;
    printf("introduceti un numar: ");
    scanf("%d", &n);
    while (n > 1) {
        u = n % 10;
        s += u;
        if (u % 2 == 0) {
            np = np * 10 + u;
        }
        n /= 10;
        if (u > umax) {
            umax = u;
        }
    }
    while (np > 1) {
        u = np % 10;
        npo = npo * 10 + u;
        np /= 10;
    }
    s += n % 10;
    if (npo != 0) {
        printf("%d %d %d", s, umax, npo);
    } else {
        printf("%d %d NU EXISTA", s, umax);
    }
}

void pb9() {
    int n;
    printf("introduceti un numar: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("\n");
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
    }
}

int main() {
    pb1();
    pb2();
    pb3();
    pb4();
    pb5();
    pb6();
    pb7();
    pb8();
    pb9();
    return 0;
}