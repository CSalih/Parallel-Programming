#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define N 100000
#define M 100000

struct Data {
    float m[N + 10];
};

int main(int argc, char *argv[]) {
    printf("\n\n\n");
    int n;
    int m;
    if (argc != 3) {
        n = N;
        m = M;
        fprintf(stderr, "arg missing <n,t> \n");
    }
    if (argc == 3) {
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }
    // n = 8;
    // m=6;
    printf("N %d , M %d\n", n, m);

    struct Data *a_2 = (struct Data *)malloc(sizeof(struct Data));
    struct Data *a = (struct Data *)malloc(sizeof(struct Data));
    struct Data *b = (struct Data *)malloc(sizeof(struct Data));
    struct Data *c = (struct Data *)malloc(sizeof(struct Data));

    if (a_2 == NULL || a == NULL || b == NULL || c == NULL) {
        puts("MALLOC ERROR");
        return 1;
    }
    printf("using MB:%lu\n", ((4 * sizeof(struct Data)) / 1000000));

    for (int i = 0; i < n; i++) {
        a->m[i] = i * 0.001;
        a_2->m[i] = a->m[i];
        b->m[i] = i * 0.002;
        c->m[i] = i * 0.003;
    }

    clock_t begin = clock();
    for (int run = 0; run < n; ++run)
        for (int i = 0; i < m; ++i) a->m[i] += b->m[i] * c->m[i];
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Executiontime: %lf\n", time_spent);

    // Verify Part

    for (int i = 0; i < 10 && i < N && i < M; ++i) {
        printf("%f ", a->m[i]);
    }

    puts("-");

    free(a_2);
    free(a);
    free(b);
    free(c);

    return 0;
}
