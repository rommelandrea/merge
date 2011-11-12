#include "arrayUtil.h"

void copyArray(int a[], int b[], int length) {
    int i = 0;

    for (i = 0; i < length; i++)
        b[i] = a[i];
}

void fillRandomArray(int a[], int length, int max) {
    srand(time(NULL));
    int i;

    for (i = 0; i < length; i++)
        a[i] = rand() % max;
}

void print(int a[], int length) {
    int i;
    printf("stampo l'array\n");
    for (i = 0; i < length; i++) {
        printf("%d-->", a[i]);
    }
    printf("\n");
}

int sorted(int a[], int length) {
    int i;
    for (i = 1; i < length; i++)
        if (a[i - 1] > a[i])
            return 0;

    return 1;
}

void swap(int a[], int i, int j) {
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}