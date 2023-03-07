/*Se dă un număr natural n. Afișați cărui anotimp îi corespunde luna din an
citită în variabila n sau un mesaj corespunzător dacă valoarea citită nu poate
fi o lună din an. Exemplu: pentru n=3 se va afișa primavara deoarece 3
corespunde lunii martie.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    scanf("%d", &n);

    if (3 <= n && n <= 5) {
        printf("primavara");
    } else {
        if (6 <= n && n <= 8) {
            printf("vara");
        } else {
            if (9 <= n && n <= 11) {
                printf("toamna");
            } else {
                if (n == 12 || (1 <= n && n <= 2)) {
                    printf("iarna");
                } else {
                    printf("numarul introdus nu reprezinta o luna a anului");
                }
            }
        }
    }

    return 0;
}
