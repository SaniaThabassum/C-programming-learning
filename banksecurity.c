#include <stdio.h>

int main() {
    char name[50];
    int units;
    float bill, surcharge = 0;

    // Input
    printf("Enter customer name (no spaces): ");
    scanf("%s", name);
    printf("Enter units consumed: ");
    scanf("%d", &units);

    // Calculate bill
    if (units <= 200) {
        bill = units * 0.80;
    } else if (units <= 300) {
        bill = (200 * 0.80) + (units - 200) * 0.90;
    } else {
        bill = (200 * 0.80) + (100 * 0.90) + (units - 300) * 1.00;
    }

    // Add surcharge if bill > 400
    if (bill > 400) {
        surcharge = 0.15 * bill; //For 500 units 160+90+200=450 surcharge=67.5
    }

    // Add minimum meter charge
    bill = bill + surcharge + 100; //For 500 units bill=450+67.5+100

    // Output
    printf("\nCustomer: %s\n", name);
    printf("Total Bill = Rs. %.2f\n", bill);

    return 0;
}
