#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    double sum = 0, mean, variance = 0, stdDev;
    
    printf("Enter number of parts: ");
    scanf("%d", &n);
    
    double arr[n];
    printf("Enter %d part lengths: ", n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
    
    // Using pointer for sum
    double *ptr = arr;
    for (i = 0; i < n; i++) {
        sum += *(ptr + i);
    }
    
    mean = sum / n;
    
    // Calculate variance
    for (i = 0; i < n; i++) {
        variance += pow(*(ptr + i) - mean, 2);
    }
    variance /= n;
    
    stdDev = sqrt(variance);
    
    printf("Sum = %.2f\n", sum);
    printf("Mean = %.2f\n", mean);
    printf("Standard Deviation = %.2f\n", stdDev);
    
    return 0;
}