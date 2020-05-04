/*
    Source of calculation logic: https://github.com/allscale/allscale_api/wiki/HeatStencil
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <omp.h>
#include <string.h>
#include <math.h>

#define RESOLUTION_WIDTH 50
#define RESOLUTION_HEIGHT 50
#define HEAT_SOURCE_TEMP 273 + 60

#define PERROR fprintf(stderr, "%s:%d: error: %s\n", __FILE__, __LINE__, strerror(errno))
#define PERROR_GOTO(label) \
	do { \
		PERROR; \
		goto label; \
	} while (0)

// -- vector utilities --
#define IND(y, x) ((y) * (N) + (x))

#define SWAP(x,y) do { \
        __typeof__(x) _x = x; \
        __typeof__(y) _y = y; \
        x = _y; \
        y = _x; \
    } while(0)

#define FLOAT_EQUALS(x, y) fabs(x - y) < 0.001


void printTemperature(double *m, int N, int M);

// -- simulation code ---

int main(int argc, char **argv) {
    // 'parsing' optional input parameter = problem size
    int N = 200;
    if (argc > 1) {
        N = atoi(argv[1]);
    }
    int T = N * 10;
    printf("Computing heat-distribution for room size %dX%d for T=%d timesteps\n", N, N, T);

    // ---------- setup ----------

    // create a buffer for storing temperature fields
    double *A =  malloc(sizeof(double) * N * N);

    if(!A) PERROR_GOTO(error_a);

    // set up initial conditions in A
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[IND(i,j)] = 273; // temperature is 0° C everywhere (273 K)
        }
    }

    // and there is a heat source
    int source_x = N / 4;
    int source_y = N / 4;
    A[IND(source_x,source_y)] = HEAT_SOURCE_TEMP;

    printf("Initial:");
    printTemperature(A, N, N);
    printf("\n");

    // ---------- compute ----------

    // create a second buffer for the computation
    double *B = malloc(sizeof(double) * N * N);
    if(!B) PERROR_GOTO(error_b);

    // for each time step ..
    #pragma omp parallel
    for (int t = 0; t < T; t++) {
        // todo implement heat propagation, if at corner, use own heat value
        #pragma omp parallel for collapse(2)
        for(int i=1; i<N; i++) {
            for(int j=1; j<N; j++) {
                double l, r, up, un;
                // todo make sure the heat source stays the same
                // don't change the value if heat source, else set surrounding tiles values 
                if (!(i == source_x && j == source_y)) {   
                    l = A[IND(i,j-1)];
                    r = A[IND(i,j+1)];
                    up = A[IND(i-1,j)];
                    un = A[IND(i+1,j)];
                    // if left tile is on the border set it to the to the actual tile's value
                    if (j == 0) {
                        l = A[IND(i,j)];
                    }
                    // if right tile is on the border set it to the to the actual tile's value
                    if (j == (N - 1)) {
                        r = A[IND(i,j)];
                    }
                    // if top tile is on the border set it to the to the actual tile's value
                    if (i == 0) {
                        up = A[IND(i,j)];
                    }
                    // if bottom tile is on the border set it to the to the actual tile's value
                    if (i == (N - 1)) {
                        un = A[IND(i,j)];
                    }
                
                    // formula from lecture slides to calculate new A value
                    A[IND(i,j)] = (l + r + up + un + A[IND(i,j)]) / 5;
                    //change to B
                } else {
                    // B[IND(i,j)] = A[IND(i,j)];
                }
            }
        }
        // SWAP(A, B);

        // every 1000 steps show intermediate step
        if (!(t % 1000)) {
            printf("Step t=%d\n", t);
            printTemperature(A, N, N);
            printf("\n");
        }
    }
    


    // ---------- check ----------

    printf("Final:");
    printTemperature(A, N, N);
    printf("\n");

    // simple verification if nowhere the heat is more then the heat source
    int success = 1;
    for (long long i = 0; i < N; i++) {
        for (long long j = 0; j < N; j++) {
            double temp = A[IND(i,j)];
            if (273 <= temp && temp <= 273 + 60)
                continue;
            success = 0;
            break;
        }
    }

    printf("Verification: %s\n", (success) ? "OK" : "FAILED");

    // todo ---------- cleanup ----------
    error_b:
    free(B);
    error_a:
    free(A);
    return (success) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void printTemperature(double *m, int N, int M) {
    const char *colors = " .-:=+*^X#%@";
    const int numColors = 12;

    // boundaries for temperature (for simplicity hard-coded)
    const double max = 273 + 30;
    const double min = 273 + 0;

    // set the 'render' resolution
    int W = RESOLUTION_WIDTH;
    int H = RESOLUTION_HEIGHT;

    // step size in each dimension
    int sW = N / W;
    int sH = M / H;

    // upper wall
    printf("\t");
    for (int u = 0; u < W + 2; u++) {
        printf("X");
    }
    printf("\n");
    // room
    for (int i = 0; i < H; i++) {
        // left wall
        printf("\tX");
        // actual room
        for (int j = 0; j < W; j++) {
            // get max temperature in this tile
            double max_t = 0;
            for (int x = sH * i; x < sH * i + sH; x++) {
                for (int y = sW * j; y < sW * j + sW; y++) {
                    max_t = (max_t < m[IND(x,y)]) ? m[IND(x,y)] : max_t;
                }
            }
            double temp = max_t;

            // pick the 'color'
            int c = ((temp - min) / (max - min)) * numColors;
            c = (c >= numColors) ? numColors - 1 : ((c < 0) ? 0 : c);

            // print the average temperature
            printf("%c", colors[c]);
        }
        // right wall
        printf("X\n");
    }
    // lower wall
    printf("\t");
    for (int l = 0; l < W + 2; l++) {
        printf("X");
    }
    printf("\n");
}