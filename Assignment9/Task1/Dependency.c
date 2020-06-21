#include <math.h>
#include <omp.h>

void a(int *x, int *y, int n) {
    for (int i = 0; i < n - 1; i++) {
        x[i] = (y[i] + x[i + 1]) / 7;
    }
}

void a_sol(int *x, int *y, int n) {
    int x2[n];
#pragma omp parallel for
    for (int i = 0; i < n - 1; i++) {
        x2[i] = x[i + 1];
    }
#pragma omp parallel for
    for (int i = 0; i < n - 1; i++) {
        x2[i] = (y[i] + x2[i]) / 7;
    }
}

void b(int *x, int *y, int *z, int n, int k) {
    int a;
    for (int i = 0; i < n; i++) {
        a = (x[i] + y[i]) / (i + 1);
        z[i] = a;
    }

    int f = sqrt(a + k);
}

void b_sol(int *x, int *y, int *z, int n, int k) {
#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        z[i] = (x[i] + y[i]) / (i + 1);
    }
    int f = sqrt(z[n] + k);
}

void c(int *x, int *y, int n, int a, int b) {
    for (int i = 0; i < n; i++) {
        x[i] = y[i] * 2 + b * i;
    }

    for (int i = 0; i < n; i++) {
        y[i] = x[i] + a / (i + 1);
    }
}

void c_sol(int *x, int *y, int n, int a, int b) {
#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        x[i] = y[i] * 2 + b * i;
        y[i] = x[i] + a / (i + 1);
    }
}