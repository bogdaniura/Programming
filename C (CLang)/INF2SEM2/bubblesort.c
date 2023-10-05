#include <stdio.h>

int main() {
    int v[100] = {6, 4, 8, 3, 1, 9, 5, 2, 9, 7};
    int schimbare, aux, lungime = 10, perete = 1;
    do {
        schimbare = 0;
        for (int i = 0; i < lungime-perete; i++) {
            if (v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                schimbare++;
            }
        }
        perete++;

    } while (schimbare != 0);
    for (int i = 0; i < lungime; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
