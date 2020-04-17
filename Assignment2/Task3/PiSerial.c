#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 500000000 // Size of random created 2D points

int main(void)
{
    // The number of points that lie inside the quarter of the unit circle.
    int pointsInside = 0; 

    // Initializing random
    srand(time(NULL));

    clock_t begin = clock();
    for (int j = 0; j < N; j++) {

        // generated random 2D points in the interval [0, 1]
        double x = (double) (rand() % (N + 1)) / N;
        double y = (double) (rand() % (N + 1)) / N;

        // Formular from: http://www.eveandersson.com/pi/monte-carlo-circle
        double distance = x * x + y * y;

        // Check whether they are inside the first quadrant of a unit circle
        if (distance <= 1)
            pointsInside++;
    }

    // Pi can be approximated by
    double pi = ((double) 4 * pointsInside) / N;

    // Benchmark
    clock_t end = clock();
    double time = (double)(end - begin) / CLOCKS_PER_SEC;

    // Print approximated result of pi
    printf("Pi = %.2f Time: %.2f s\n", pi, time);

    return EXIT_SUCCESS;
}