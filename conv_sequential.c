#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sequential_convolution(int *A, int *F, int *R, int NA, int NF) {
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

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    sequential_convolution(A, F, R, NA, NF);
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    //printf("Sequential Convolution time: %.6f seconds\n", elapsed_time);
    for (int i = 0; i < NA - NF + 1; i++) {
         printf("%d\n", R[i]);
    }
    free(A);
    free(F);
    free(R);

    return 0;
}
