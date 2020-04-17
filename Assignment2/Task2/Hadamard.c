#include <stddef.h>
#include <stdint.h>

#define N 100

int main(void) {
    int32_t a[N][N];
    int32_t b[N][N];
    int32_t c[N][N];

#ifdef COL_MAJOR
    for (size_t j = 0;j < N;++j) {
        for (size_t i = 0;i < N;++i) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }
#else
    for (size_t i = 0;i < N;++i) {
        for (size_t j = 0;j < N;++j) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }
#endif // COL_MAJOR

    return 0;
}