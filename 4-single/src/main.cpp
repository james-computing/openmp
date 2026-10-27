#include <iostream>
#include <omp.h>


int main() {

    #pragma omp parallel
    {
        #pragma omp single
        {
            std::cout << "Number of threads = " << omp_get_num_threads() << std::endl;
            std::cout << "This thread id = " << omp_get_thread_num() << std::endl;
        }
    }

    return 0;
}