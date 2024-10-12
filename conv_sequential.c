#include <stdio.h>
#include <stdlib.h>

void sequential_convolution(int *A, int *F, int *R, int NA, int NF) {
    for (int i = 0; i <= NA - NF; i++) {
        int sum_result = 0;
        int j;
        for (j = 0; j < NF - 3; j += 4) {
            sum_result += A[i + j] * F[NF - j - 1];
            sum_result += A[i + j + 1] * F[NF - (j + 1) - 1];
            sum_result += A[i + j + 2] * F[NF - (j + 2) - 1];
            sum_result += A[i + j + 3] * F[NF - (j + 3) - 1];
        }
        for (; j < NF; j++) {
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

    
    sequential_convolution(A, F, R, NA, NF);
    
    // for (int i = 0; i < NA - NF + 1; i++) {
    //      printf("%d\n", R[i]);
    // }
    free(A);
    free(F);
    free(R);

    return 0;
}
