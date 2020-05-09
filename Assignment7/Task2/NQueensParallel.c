/**
 * Author: http://rosettacode.org/wiki/N-queens_problem#C
 */ 
#include <stdio.h>
#include <stdlib.h>

#define MAXN 27

int nQueens(int n) {
    int q0, q1;
    int cols[MAXN], diagl[MAXN], diagr[MAXN], posibs[MAXN];  // Our backtracking 'stack'
    int num = 0;
    //
    // The top level is two fors, to save one bit of symmetry in the enumeration by forcing second queen to
    // be AFTER the first queen.
    //
    // #pragma omp parallel for collapse(2)
    for (q0 = 0; q0 < n - 2; q0++) {
        for (q1 = q0 + 2; q1 < n; q1++) {
            int bit0 = 1 << q0;
            int bit1 = 1 << q1;
            int d = 0;                          // d is our depth in the backtrack stack
            cols[0] = bit0 | bit1 | (-1 << n);  // The -1 here is used to fill all 'coloumn' bits after n ...
            diagl[0] = (bit0 << 1 | bit1) << 1;
            diagr[0] = (bit0 >> 1 | bit1) >> 1;

            //  The variable posib contains the bitmask of possibilities we still have to try in a given row ...
            int posib = ~(cols[0] | diagl[0] | diagr[0]);

            while (d >= 0) {
                while (posib) {
                    int bit = posib & -posib;  // The standard trick for getting the rightmost bit in the mask
                    int ncols = cols[d] | bit;
                    int ndiagl = (diagl[d] | bit) << 1;
                    int ndiagr = (diagr[d] | bit) >> 1;
                    int nposib = ~(ncols | ndiagl | ndiagr);
                    posib ^= bit;  // Eliminate the tried possibility.

                    num += ncols == -1;

                    if (nposib) {
                        if (posib) {              // This if saves stack depth + backtrack operations when we passed the last possibility in a row.
                            posibs[d++] = posib;  // Go lower in stack ..
                        }
                        cols[d] = ncols;
                        diagl[d] = ndiagl;
                        diagr[d] = ndiagr;
                        posib = nposib;
                    }
                }
                posib = posibs[--d];  // backtrack ...
            }
        }
    }
    return num * 2;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Argument missing! ./NQueensSerial n\n");
        return EXIT_FAILURE;
    }

    // Get size of array
    int n = atoi(argv[argc - 1]);
    if (n <= 0 || n > 27) {
        fprintf(stderr, "Invalid input! Size must between 0 and 27.\n");
        return EXIT_FAILURE;
    }

    printf("Number of solution for %d is %d\n", n, nQueens(n));
    return EXIT_SUCCESS;
}