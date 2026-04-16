#include <omp.h>
#include <iostream>

int main() {
    int size, rank;
    
    #pragma omp parallel private(size, rank)
    {
        rank = omp_get_thread_num();
        std::cout << "Hello World from thread = " << rank << std::endl;
        
        if (rank == 0) {
            size = omp_get_num_threads();
            std::cout << "Number of threads = " << size << std::endl;
        }
    }
    
    return 0;
}