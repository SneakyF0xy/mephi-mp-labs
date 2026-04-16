#include <omp.h>
#include <iostream>

#define M 10

int main() {
    float A[M][M], b[M], c[M];
    int i, j, rank;
    
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++)
            A[i][j] = (j+1) * 1.0;
        b[i] = 1.0 * (i+1);
        c[i] = 0.0;
    }
    
    std::cout << "\nOutput of matrix A and vector b values:\n";
    for (i = 0; i < M; i++) {
        std::cout << " A[" << i << "]= ";
        for (j = 0; j < M; j++)
            std::cout << A[i][j] << " ";
        std::cout << " b[" << i << "]= " << b[i] << std::endl;
    }
    
    #pragma omp parallel shared(A,b,c) private(rank,i)
    {
        rank = omp_get_thread_num();
        
        #pragma omp for private(j)
        for (i = 0; i < M; i++) {
            for (j = 0; j < M; j++)
                c[i] += (A[i][j] * b[j]);
            
            #pragma omp critical
            {
                std::cout << " rank= " << rank << " i= " << i << " c[" << i << "]=" << c[i] << std::endl;
            }
        }
    }
    
    return 0;
}