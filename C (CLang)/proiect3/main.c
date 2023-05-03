#include <stdio.h>

#define MAX 50

int main() {
    int mat[MAX][MAX], nl, nc, vector[MAX * MAX], indice_vector;
    // citire(mat[MAX][MAX], nl, nc);
    // scanf("%d%d", &nl, &nc);
    nl = nc = 4;
    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++) {
            scanf("%d", &mat[l][c]);
        }
    }
    for (int suma = 0; suma < nl + nc; suma++) {
        if (suma % 2 == 0) {
            for (int l = 0; l < nl; l++) {
                for (int c = 0; c < nc; c++) {
                    if (l + c == suma) {
                        vector[indice_vector++] = mat[l][c];
                    }
                }
            }

        } else {
            for (int l = nl-1; l >= 0; l--) {
                for (int c = nc-1; c >= 0; c--) {
                    if (l + c == suma) {
                        vector[indice_vector++] = mat[l][c];
                    }
                }
            }
        }
    }
    for (int i = 0; i < nl * nc; i++) {
        printf("%d ", vector[i]);
    }

    return 0;
}