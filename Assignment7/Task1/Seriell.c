#include <omp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printAll(int32_t* a, int32_t* b, int n);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "arg missing\n");
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);
    printf("%d\n", n);

    int32_t* a = malloc(sizeof(int32_t) * n);
    int32_t* b = malloc(sizeof(int32_t) * n);
    b[0] = 0;
    for (int i = 0; i < n; i++)
        a[i] = i;
    printf("using %ld MB\n", (sizeof(int32_t) * n * 2) / 1000000);
    printAll(a, b, n);

    for (int i = 0; i < n; i++)
        b[i] = b[i - 1] + a[i - 1];
    printAll(a, b, n);

    free(b);
    free(a);
}

void printAll(int32_t* a, int32_t* b, int n) {
    if (n > 200) {
        puts("skipping print");
        printf("LAST VALUE:%d\n", b[n - 1]);
        return;
    }

    puts("");
    printf("b:");
    for (int i = 0; i < n; i++)
        printf(" %d", b[i]);
    puts("");

    printf("a:");
    for (int i = 0; i < n; i++)
        printf(" %d", a[i]);
    puts("");
}
