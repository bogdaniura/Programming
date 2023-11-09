#include <math.h>
#include <stdio.h>

#define N 100

void print_vector(int v[N], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void sum_right_neighbour(int v[N], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        v[i] += v[i + 1];
    }
}

void sum_left_neighbour(int v[N], int n) {
    int i;
    for (i = 1; i < n; i++) {
        v[i] += v[i - 1];
    }
}

void produs(int v[N], int n) {
    int vector[N];
    for (int i = 0; i < n; i++) {
        vector[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != i) {
                vector[i] *= v[j];
            }
        }
    }
    print_vector(vector, n);
}

int fminim(int v[N], int n) {
    int min = v[0];
    for (int i = 0; i < n; i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    return min;
}

int fpoz_max(int v[N], int n) {
    int max = v[0], imax;
    for (int i = 0; i < n; i++) {
        if (v[i] > max) {
            imax = i;
        }
    }
    return imax;
}

int fpoz_min(int v[N], int n) {
    int min = v[0], imin;
    for (int i = 0; i < n; i++) {
        if (v[i] < min) {
            imin = i;
        }
    }
    return imin;
}

void elim_elem_minim(int v[N], int n) {
    int ielim = fpoz_min(v, n);
    for (int i = ielim; i < n - 1; i++) {
        v[i] = v[i + 1];
    }
    print_vector(v, n - 1);
}

void elim_elem_maxim(int v[N], int n) {
    int ielim = fpoz_max(v, n);
    for (int i = ielim; i < n - 1; i++) {
        v[i] = v[i + 1];
    }
    print_vector(v, n - 1);
}

void pb1(int v[N], int n) {
    int op, cont = 1;
    do {
        scanf("%d", &op);
        switch (op) {
            case 1:
                elim_elem_minim(v, n);
                break;
            case 2:
                elim_elem_maxim(v, n);
                break;
            case 3:
                print_vector(v, n);
                break;

            default:
                break;
        }
    } while (op != 0);
}

double fmarit(int v[N], int n) {
    double medie;
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += v[i];
    }
    medie = suma / n;
    return medie;
}

int fgt_ma(int v[N], int n, int ma) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > ma) {
            c++;
        }
    }
    return c;
}

void pb2(int v[N]) {
    int n, min, poz_max, ma, gt_ma;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    min = fminim(v, n);
    poz_max = fpoz_max(v, n);
    ma = fmarit(v, n);
    gt_ma = fgt_ma(v, n, ma);

    printf("min = %d\npoz_max = %d\nma = %d\ngt_ma = %d", min, poz_max, ma,
           gt_ma);
}

void pb3(int v1[N], int n) {
    int k, v2[N];
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &v1[i]);
    // }
    scanf("%d", &k);

    for (int i = 0; i < n - k; i++) {
        v2[i] = v1[i + k];
    }
    for (int i = n - k, j = 0; i < n && j < k; i++, j++) {
        v2[i] = v1[j];
    }

    print_vector(v2, n);
}

void incrementare(int v1[N], int n) {
    int v2[N];
    for (int i = 0; i < n; i++) {
        v2[i] = v1[i] + 1;
    }
    print_vector(v2, n);
}

void inmultire_doi(int v1[N], int n) {
    int v2[N];
    for (int i = 0; i < n; i++) {
        v2[i] = v1[i] * 2;
    }
    print_vector(v2, n);
}

void impartire_doi(int v1[N], int n) {
    int v2[N];
    for (int i = 0; i < n; i++) {
        v2[i] = v1[i] / 2;
    }
    print_vector(v2, n);
}

void patrat(int v1[N], int n) {
    int v2[N];
    for (int i = 0; i < n; i++) {
        v2[i] = v1[i] * v1[i];
    }
    print_vector(v2, n);
}

void radical(int v1[N], int n) {
    double v2[N];
    for (int i = 0; i < n; i++) {
        v2[i] = sqrt(v1[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%.6f ", v2[i]);
    }
}

void pb4(int v1[N], int n) {
    int k, v2[N];
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &v1[i]);
    // }
    scanf("%d", &k);

    switch (k) {
        case 0:
            incrementare(v1, n);
            break;
        case 1:
            inmultire_doi(v1, n);
            break;
        case 2:
            impartire_doi(v1, n);
            break;
        case 3:
            patrat(v1, n);
            break;
        case 4:
            radical(v1, n);
            break;

        default:
            break;
    }
}

int main() {
    int v[N] = {1, 2, 3, 4, 5}, vector[N], operation, n = 5;

    pb1(v, n);
    pb2(v);
    pb3(v, n);
    pb4(v, n);

    return 0;
}