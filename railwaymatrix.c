#include <stdio.h>

int main() {
    int m, n, p, q;
    int A[20][20], B[20][20], C[20][20];
    int i, j, k;

    // Input matrix dimensions
    printf("Enter rows and columns of Matrix A (m n): ");
    scanf("%d %d", &m, &n);

    printf("Enter rows and columns of Matrix B (p q): ");
    scanf("%d %d", &p, &q);

    // Check matrix multiplication condition
    if (n != p) 
    {
        printf("\nMatrix multiplication NOT possible.\n");
        printf("Condition failed: Columns of A (%d) != Rows of B (%d)\n", n, p);
        return 0;  // Stop program
    }

    // Input elements for Matrix A
    printf("\nEnter elements of Matrix A (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Input elements for Matrix B
    printf("\nEnter elements of Matrix B (%d x %d):\n", p, q);
    for (i = 0; i < p; i++) 
    {
        for (j = 0; j < q; j++) 
        {
            scanf("%d", &B[i][j]);
        }
    }

    // Initialize Matrix C with 0
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < q; j++) 
        {
            C[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < q; j++) 
        {
            for (k = 0; k < n; k++) 
            {  // or k < p (same since n == p)
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            }
        }
    }

    // Display result
    printf("\nResultant Matrix C (%d x %d):\n", m, q);
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < q; j++) 
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
