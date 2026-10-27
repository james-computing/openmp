#include <iostream>
#include <omp.h>

#define N 1000
#define CHUNKSIZE 100

int main() {

    int i, chunksize;
    float a[N], b[N], c[N];

    for (i = 0; i < N; ++i) {
        a[i] = b[i] = i;
    }
    chunksize = CHUNKSIZE;

    #pragma omp parallel for \
        shared(a, b, c, chunksize) private(i) \
        schedule(static, chunksize)
    for (i = 0; i < N; ++i) {
        c[i] = a[i] + b[i];
    }

    for (i = 0; i < 10; ++i) {
        std::cout << c[i] << '\n';
    }
    std::cout << std::flush;

    return 0;
}