#include <stdio.h>

// Find string length
int stringLength(char s[]) 
{
    int i = 0;
    while (s[i] != '\0') 
   {
        i++;
    }
    return i;
}

// Compare two strings
int stringCompare(char s1[], char s2[]) 
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return 0;   // not equal
        }
        i++;
    }

    // If both ended at same time → equal
    if (s1[i] == '\0' && s2[i] == '\0')
        return 1;
    else
        return 0;
}

// Concatenate two strings
void stringConcat(char s1[], char s2[], char out[]) {
    int i = 0, j = 0;

    // copy s1
    while (s1[i] != '\0') {
        out[i] = s1[i];
        i++;
    }

    // copy s2
    while (s2[j] != '\0') {
        out[i] = s2[j];
        i++;
        j++;
    }

    out[i] = '\0';  // end string
}

int main() {

    int ch;
    char a[100], b[100], res[200];

    printf("1. Compare\n2. Concatenate\n3. Find Length\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
        printf("Enter first string: ");
        scanf("%s", a);
        printf("Enter second string: ");
        scanf("%s", b);

        if (stringCompare(a, b))
            printf("Strings are Equal\n");
        else
            printf("Strings are Not Equal\n");
    }

    else if (ch == 2) {
        printf("Enter first string: ");
        scanf("%s", a);
        printf("Enter second string: ");
        scanf("%s", b);

        stringConcat(a, b, res);
        printf("Concatenated String: %s\n", res);
    }

    else if (ch == 3) {
        printf("Enter a string: ");
        scanf("%s", a);
        printf("Length = %d\n", stringLength(a));
    }

    else {
        printf("Invalid Choice\n");
    }

    return 0;
}
