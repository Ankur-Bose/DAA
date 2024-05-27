#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

// Function to find the minimum number of scalar multiplications required to multiply a chain of matrices
int matrixChainOrder(int p[], int i, int j) {
    if (i == j)
        return 0;

    int k, min = INF, count;

    // Iterate through all possible positions to split the chain
    for (k = i; k < j; k++) {
        count = matrixChainOrder(p, i, k) + matrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    return min;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications: %d \n", matrixChainOrder(arr, 1, n - 1));
    return 0;
}