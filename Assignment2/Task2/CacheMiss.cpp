#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "Cache.h"

int main(void) 
{
    int n = 10;
    int32_t a[n][n]; // = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int32_t b[n][n]; // = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int32_t c[n][n];

    Cache cache(5);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cache.refer(&a[i][j]);
            cache.refer(&b[i][j]);
            cache.refer(&c[i][j]);

            c[i][j] = a[i][j] * b[i][j];
        }
    }

    cache.display();
}