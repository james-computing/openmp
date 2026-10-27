#include <iostream>
#include <omp.h>

#define CHUNKSIZE 100
#define N 1000

int main() {
    int i, chunksize;
    float a[N], b[N], c[N];

    for (i = 0; i < N; ++i) {
        a[i] = i;
        b[i] = i;
    }
    chunksize = CHUNKSIZE;

    #pragma omp parallel shared(a, b, c, chunksize) private(i)
    {
        #pragma omp for schedule(dynamic, chunksize) nowait
        for (i = 0; i < N; ++i) {
            c[i] = a[i] + b[i];
        }
    }

    for (i = 0; i < 10; ++i) {
        std::cout << c[i] << '\n';
    }
    std::cout << std::flush;

    return 0;
}