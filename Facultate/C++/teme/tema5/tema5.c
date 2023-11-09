#include <stdio.h>

void sortare(int v[100], int n) {
    int schimbare, aux;
    do {
        schimbare = 0;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                schimbare = 1;
            }
        }
    } while (schimbare);
}

void afisare(int v[100], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
}

int main() {
    int v[100], n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    afisare(v, n);
    printf("\n");
    sortare(v, n);
    afisare(v, n);

    return 0;
}