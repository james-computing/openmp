#include <iostream>
#include <omp.h>

#define N 1000

int main() {
    int i;
    float a[N], b[N], sum[N], product[N];

    for (i = 0; i < N; ++i) {
        a[i] = i * 1.5;
        b[i] = i + 22.35;
    }

    #pragma omp parallel shared(a, b, sum, product) private(i)
    {
        #pragma omp sections nowait
        {
            #pragma omp section
            for (i = 0; i < N; ++i) {
                sum[i] = a[i] + b[i];
            }

            #pragma omp section
            for (i = 0; i < N; ++i) {
                product[i] = a[i] * b[i];
            }
        }
    }

    std::cout << "sum:\n";
    for (i = 0; i < 10; ++i) {
        std::cout << sum[i] << '\n';
    }
    std::cout << '\n';

    std::cout << "product:\n";
    for (i = 0; i < 10; ++i) {
        std::cout << product[i] << '\n';
    }
    std::cout << std::flush;

    return 0;
}