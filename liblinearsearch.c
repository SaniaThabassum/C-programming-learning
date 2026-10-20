#include <stdio.h>

int main() 
{
    int n, key, low, high, mid, found = -1;
    
    printf("Enter number of books: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d sorted book IDs: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter book ID to search: ");
    scanf("%d", &key);
    
    low = 0;
    high = n - 1;
    
    while (low <= high) 
    {
        mid = (low + high) / 2;
        if (arr[mid] == key) 
        {
            found = mid;
            break;
        } 
        else if (arr[mid] < key) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    
    if (found != -1)
        printf("Book found at position %d\n", found);
    else
        printf("Book not found\n");
    
    return 0;
}
