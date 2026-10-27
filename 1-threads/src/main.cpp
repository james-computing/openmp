#include <iostream>
#include <omp.h>

int main() {
    int nthreads, tid;

    #pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        std::cout << "tid = " << tid << std::endl;

        if (tid == 0) {
            nthreads = omp_get_num_threads();
            std::cout << "Number of threads = " << nthreads << std::endl;
        }
    }

    return 0;
}