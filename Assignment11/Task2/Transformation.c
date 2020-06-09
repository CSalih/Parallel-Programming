#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000000000

void a(unsigned *a, unsigned *b) {
    for (long  i = 0; i < N - 1; ++i) {
	    a[i] = b[i] + b[i + 1];
	}
}

void a_solution(unsigned *a, unsigned *b) {
    for (long i = 0; i < N-2; i+=2){
        a[i] = b[i] + b[i + 1];
        a[i+1] = b[i+1] + b[i + 2];   
    }
}

void c(unsigned *a) {
    for (int i = 0; i < N; ++i) {
        a[i] *= hypot(0.3, 0.4);
    }
}

void c_solution(unsigned *a) {
	double c=hypot(0.3, 0.4);
	for (int i = 0; i < N; ++i) {
	    a[i] *= c;
	}
}

void d(unsigned *a, unsigned *b, unsigned *c) {
    for (int i = 0; i < N; ++i) {
        if (N % 2) {
            a[i] = b[i] + 5;
        } else {
            a[i] = c[i] + 5;
        }
    }
}

void d_solution(unsigned *a, unsigned *b, unsigned *c) {
	if (N % 2) {
        for (int i = 0; i < N; ++i) {
            a[i] = b[i] + 5;
        }
    } else {
        for (int i = 0; i < N; ++i) {
            a[i] = c[i] + 5;
        }
    }
}

void e(unsigned *a, unsigned *b, unsigned *c) {
    int sum_a=0,sum_b=0,sum_c=0;
    for (int i = 0; i < N; ++i) {
        sum_a += a[i];
        sum_b += b[i];
        sum_c += c[i];
    }
}

void e_solution(unsigned *a, unsigned *b, unsigned *c) {
    int sum_a=0,sum_b=0,sum_c=0;
	for (int i = 0; i < N; ++i) 
	    sum_a += a[i];

	for (int i = 0; i < N; ++i)
		sum_b += b[i];
		
	for (int i = 0; i < N; ++i)
	    sum_c += c[i];
}

void f(unsigned *a) {
    int min = a[0], sum = 0;
    for (int i = 1; i < N; ++i) {
        min = (a[i] < min) ? a[i] : min;
    }
    for (int i = 0; i < N; ++i) {
        sum += a[i];
    }
}

void f_solution(unsigned *a) {
    int min = a[0], sum = 0;
	for (int i = 0; i < N; ++i) { 
	    min = (a[i] < min) ? a[i] : min;
	    sum += a[i];
	}
}

void g(unsigned *a, unsigned *b, unsigned *c) {
    for (int i = 0; i < N; ++i) {
        if (i % 2) {
            a[i] = b[i] + 4;
        } else {
            a[i] = c[i] + 5;
        }
    }
}

void g_solution(unsigned *a, unsigned *b, unsigned *c) {
	for (int i = 0; i < N; i+=2) 
	    a[i] = b[i] + 5;
	
	for (int i = 1; i < N; i+=2) 
		a[i] = c[i] + 5;
}

void h(unsigned **a, unsigned **b, unsigned **c) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                c[i][j] = a[i][k] * b[k][j];
            }
        }
    }  
}

#define BLOCK_SIZE (64 / sizeof(double))
void h_solution(unsigned **a, unsigned **b, unsigned **c) {
	for(int ii=0;ii<N-1;ii+=BLOCK_SIZE)
		for(int kk=0;kk<N-1;kk+=BLOCK_SIZE)
			for (int i = ii; i < ii+BLOCK_SIZE && i<N; ++i) // && i<N -> N-1 in ii and kk
			    	for (int j = 0; j < N; ++j) 
				    	for (int k=kk; k < kk+BLOCK_SIZE && k<N; ++k) 
				            c[i][j] = a[i][k] * b[k][j]; 
}

int main(void) {
    return EXIT_SUCCESS;
}