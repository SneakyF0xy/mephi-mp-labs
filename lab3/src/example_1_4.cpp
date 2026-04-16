#include <omp.h>
#include <iostream>

#define N 50

int main() {
    int i, size, rank;
    float a[N], b[N], c[N];
    
    for (i = 0; i < N; i++)
        a[i] = b[i] = i * 1.0;
    
    #pragma omp parallel shared(a,b,c) private(i,rank,size)
    {
        rank = omp_get_thread_num();
        std::cout << "Thread " << rank << " starting..." << std::endl;
        
        #pragma omp sections nowait
        {
            #pragma omp section
            for (i = 0; i < N/2; i++) {
                c[i] = a[i] + b[i];
                std::cout << "rank = " << rank << " i= " << i << " c[i]= " << c[i] << std::endl;
            }
            
            #pragma omp section
            for (i = N/2; i < N; i++) {
                c[i] = a[i] + b[i];
                std::cout << "rank = " << rank << " i= " << i << " c[i]= " << c[i] << std::endl;
            }
        }
        
        if (rank == 0) {
            size = omp_get_num_threads();
            std::cout << "Number of threads = " << size << std::endl;
        }
    }
    
    return 0;
}