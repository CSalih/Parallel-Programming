#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

// Size of random created 2D points
#define N 500000000


// Result of the Thread
typedef struct ThreadResult {
    int sum;
} ThreadResult;


/*
    Approximates Pi using the Monte Carlo method
*/
void *calcPi(void* obj) {
    // Number of iteration
    int n = *((int*)obj);
    // The number of points that lie inside the quarter of the unit circle.
    int i = 0;
    time_t start, end;

    // Initializing random
   unsigned int seed = time(NULL) + pthread_self();
    
    time(&start);
    for (int j = 0; j < n; j++) {
        // rand() blocks
        // generated random 2D points in the interval [0, 1]
        double x = (double) (rand_r(&seed) % (n + 1)) / n;
        double y = (double) (rand_r(&seed) % (n + 1)) / n;

        // Formular from: http://www.eveandersson.com/pi/monte-carlo-circle
        double distance = x * x + y * y;

        // Check whether they are inside the first quadrant of a unit circle
        if (distance <= 1)
            i++;
    }
    time(&end);

    // Calculating total time taken by the program. 
    double time_taken = (double)(end - start);
    printf("Thread %d took : %.2f s\n", (int)pthread_self(), time_taken);
    // return points inside
    ThreadResult* res = (ThreadResult*) malloc(sizeof(ThreadResult*));
    res->sum = i;
    pthread_exit((void*)res);
}

int main(int argc, char** argv) {
    // Check if argument is valid
    if (argc < 2) {
        printf("Provide number of threads! Usage: ./PiParallel 4\n");
        return EXIT_FAILURE;
    }

    // Get number of threads
    char* err;
    int threadCount = strtol(argv[1], &err, 10);
    if (*err != '\0' && threadCount == 0) {
        printf("Invalid input! Usage: ./PiParallel 4\n");
        return EXIT_FAILURE;
    }

    // Only for even numbers
    int pointsGenerate = N / threadCount;

    // Threads
    pthread_t tid[threadCount];
    time_t start, end;

    // Create Threads
    time(&start);
    for (int i = 0; i < threadCount; i++) {
        // Append the remain value to the last thread
        if ( (i == threadCount - 1) &&  (N % threadCount != 0)) {
            int rest = (N % threadCount) + pointsGenerate;
            pthread_create(&tid[i], NULL, &calcPi, &rest);
            break;
        }
        pthread_create(&tid[i], NULL, &calcPi, &pointsGenerate);
    }

    // Wait for termination
    int pointsInside = 0;
    for (int i = 0; i < threadCount; i++) {
        ThreadResult* result;
        pthread_join(tid[i], (void*) &result);

        if (result != NULL) {
            // Add
            pointsInside += result->sum;
            // Destroy alocated memory
            free(result);
        }
        else {
            printf("Error: result null\n");
            return EXIT_FAILURE;
        }
    }

    // Pi can be approximated by
    double pi = ((double)4 * pointsInside) / N;

    time(&end);
    double time_taken = (double)(end - start);
    printf("Calculation took : %.2f s\n", time_taken);

    // Print approximated result of pi
    printf("Pi = %.2f\n", pi);

    return EXIT_SUCCESS;
}