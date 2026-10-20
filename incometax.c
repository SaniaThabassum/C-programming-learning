#include <stdio.h>

int main() {
    float income, investments, taxable_income, tax = 0;
    int age;

    // Input
    printf("Enter annual income: ");
    scanf("%f", &income);

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter total investments: ");
    scanf("%f", &investments);

    taxable_income = income;

    // Senior citizen exemption
    if (age >= 60) {
        taxable_income = taxable_income - 50000;
    }

    // Investment deduction
    if (investments > 150000) {
        taxable_income = taxable_income - 75000;
    }

    // Tax slab calculation
    if (taxable_income <= 250000) {
        tax = 0;
    }
    else if (taxable_income <= 500000) {
        tax = taxable_income * 0.05;
    }
    else if (taxable_income <= 1000000) {
        tax = taxable_income * 0.20;
    }
    else {
        tax = taxable_income * 0.30;
    }

    // Minimum tax condition
    if (tax > 0 && tax < 1000) {
        tax = 1000;
    }

    // Output
    printf("\nTaxable Income: %.2f", taxable_income);
    printf("\nFinal Tax Payable: %.2f\n", tax);

    return 0;
}
