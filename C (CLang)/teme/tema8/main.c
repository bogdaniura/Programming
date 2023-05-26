#include <stdio.h>

int data[3];
int luna[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void leap_year() {
    if (data[2] % 4 == 0) {
        if (data[2] % 100 == 0) {
            if (data[2] % 400 == 0) {
                luna[2]++;
            }
        } else {
            luna[2]++;
        }
    }
}

int validare_data(int data[3]) {
    if (data[2] >= 0) {
        if (data[1] >= 1 && data[1] <= 12) {
            if (data[0] >= 1 && data[0] <= luna[data[1]]) {
                return 1;
            }
        }
    }
    return 0;
}

void data_urmatoare(int data[3]) {
    data[0]++;
    if (data[0] > luna[data[1]]) {
        data[0] -= luna[data[1]];
        data[1]++;
        if (data[1] > 12) {
            data[1] = 1;
            data[2]++;
        }
    }
}

int nr_de_zile() {
    int zile = 0;
    int data1[3], data2[3];

    for (int i = 0; i < 3; i++) {
        scanf("%d", &data1[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf("%d", &data2[i]);
    }
    if (validare_data(data1) && validare_data(data2)) {
        while (data1[0] != data2[0] || data1[1] != data2[1] ||
               data1[2] != data2[2]) {
            data_urmatoare(data1);
            zile++;
        }
    }
    return zile;
}

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%d", &data[i]);
    }
    leap_year();
    printf("%d\n", validare_data(data));
    if (validare_data(data)) {
        data_urmatoare(data);
        for (int i = 0; i < 3; i++) {
            printf("%d ", data[i]);
        }
    }
    printf("%d", nr_de_zile());

    return 0;
}