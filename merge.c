/* 
 * File:   merge.c
 * Author: Andrea Romanello
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayUtil.h"

void unione(int [], int [], int [], int, int, int *);
void intersezione(int [], int [], int [], int, int, int *);
void diff(int [], int [], int [], int, int, int *);

/**
 * questo metodo fa l'unione insiemistica tra l'array a e l'array b
 * e lo inserisce nell'array c
 * @param a primo array
 * @param b secondo array
 * @param c array unione tra il primo e il secondo array
 * @param m lunghezza array a
 * @param n lunghezza array b
 * @param p puntatore al numero di elementi inseriti in c
 */
void unione(int a[], int b[], int c[], int m, int n, int *p) {
    int i, j;
    i = j = 0;

    while (i < m && j < n) {
        if (a[i] == b[j]) {
            c[*p] = a[i];
            i++;
            j++;
            (*p)++;
        }
        while (a[i] < b[j] && i < m) {
            c[*p] = a[i];
            i++;
            (*p)++;
        }

        while (a[i] > b[j] && j < n) {
            c[*p] = b[j];
            j++;
            (*p)++;
        }
    }

    while (i < m) {
        c[*p] = a[i];
        i++;
        (*p)++;
    }

    while (j < n) {
        c[*p] = b[j];
        j++;
        (*p)++;
    }
}

/**
 * questo metodo fa l'intersezione insiemistica tra l'array a e l'array b
 * e lo inserisce nell'array c
 * @param a primo array
 * @param b secondo array
 * @param c array intersezione tra il primo e il secondo array
 * @param m lunghezza primo array
 * @param n lunghezza secondo array
 * @param p puntatore al numero di elementi inseriti in c
 */
void intersezione(int a[], int b[], int c[], int m, int n, int *p) {
    int i, j;
    i = j = 0;

    while (i < m && j < n) {
        if (a[i] == b[j]) {
            c[*p] = a[i];
            i++;
            j++;
            (*p)++;
        }
        while (a[i] < b[j] && i < m) {
            i++;
        }

        while (a[i] > b[j] && j < n) {
            j++;
        }
    }
}

/**
 * questo metodo fa la differenza insiemistica tra l'array a e l'array b
 * e lo inserisce nell'array c
 * @param a primo array
 * @param b secondo array
 * @param c array da riempire con gli elementi risultanti dalla differenza
 * @param m lunghezza prima array
 * @param n lunghezza secondo array
 * @param p puntatore al numero di elementi inseriti nell'array c
 */
void diff(int a[], int b[], int c[], int m, int n, int *p) {
    int i, j;
    i = j = 0;

    while (i < m && j < n) {
        if (a[i] == b[j]) {
            i++;
            j++;
        }
        while (a[i] < b[j] && i < m) {
            c[*p] = a[i];
            i++;
            (*p)++;
        }

        while (a[i] > b[j] && j < n) {
            j++;
        }
    }

    while (i < m) {
        c[*p] = a[i];
        i++;
        (*p)++;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    int p;
    p = 0;

    int a[10] = {1, 3, 7, 8, 11, 12, 13, 15, 21, 32};
    int b[10] = {2, 4, 5, 8, 12, 14, 15, 16, 20, 30};
    int c[20];

    diff(a, b, c, 10, 10, &p);

    printf("valore p %d\n", p);
    print(c, p);

    return (EXIT_SUCCESS);
}

