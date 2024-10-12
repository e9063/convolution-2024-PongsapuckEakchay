#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void parallel_convolution(int *A, int *F, int *R, int NA, int NF) {
    #pragma omp parallel for
    for (int i = 0; i <= NA - NF; i++) {
        int sum_result = 0;
        for (int j = 0; j < NF; j++) {
            sum_result += A[i + j] * F[NF - j - 1];
        }
        R[i] = sum_result;
    }
}

int main() {
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);
    int *R = malloc(sizeof(int) * (NA - NF + 1));

    for (int i = 0; i < NA; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < NF; i++) {
        scanf("%d", &F[i]);
    }

    double start_time = omp_get_wtime();
    parallel_convolution(A, F, R, NA, NF);
    double end_time = omp_get_wtime();

    //printf("Parallel Convolution time: %.6f seconds\n", end_time - start_time);
    for (int i = 0; i < NA - NF + 1; i++) {
         printf("%d\n", R[i]);
    }
    free(A);
    free(F);
    free(R);

    return 0;
}
