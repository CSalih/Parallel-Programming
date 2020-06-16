#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <xmmintrin.h>

#define N 100000
#define REPETITIONS 100000

int main(int argc, char *argv[]) {
    int n;

    // Get arguments
    if (argc == 2) {
        n = atoi(argv[1]);
    } else {
        n = N;
        fprintf(stderr, "WARN: No args, using default values \n");
    }
    printf("N=%d\n", n);

    /* 
    * Alloc memory, _mm_load_ps loads 16 Bytes adding 
    * 16 Bytes to ensure not gettin a segment fault.
    */ 
    float *a = (float *)malloc(sizeof(float) * n + 16);
    float *b = (float *)malloc(sizeof(float) * n + 16);
    float *c = (float *)malloc(sizeof(float) * n + 16);

    if (a == NULL || b == NULL || c == NULL) {
        puts("MALLOC ERROR");
        return EXIT_SUCCESS;
    }

    // Init
    for (int i = 0; i < n; i++) {
        a[i] = i * 0.001;
        b[i] = i * 0.002;
        c[i] = i * 0.003;
    }

    // compile vectorization, _mm_load1_ps loads 4 floats
    clock_t begin = clock();
    for (int run = 0; run < REPETITIONS; ++run) {
        for (int i = 0; i < n; i+=4) {
            __m128 result;
            __m128 SSEa = _mm_load1_ps(&a[i]);
            __m128 SSEb = _mm_load1_ps(&b[i]);
            __m128 SSEc = _mm_load1_ps(&c[i]);
            result = _mm_add_ps(_mm_mul_ps(SSEb, SSEc), SSEa);
            _mm_store_ps(&a[i], result);
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Executiontime: %lf\n", time_spent);

    // Verify Part
    for (int i = 0; i < 10 && i < N && i < REPETITIONS; ++i) {
        printf("%f ", a[i]);
    }

    // Free memory
    free(a);
    free(b);
    free(c);

    return EXIT_SUCCESS;
}
