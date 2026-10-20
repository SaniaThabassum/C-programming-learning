#include <stdio.h>

/* Structure to store patient details */
struct Patient {
    int patientID;
    int age;
    int admissionType;   // 1 = General, 2 = ICU
    int daysAdmitted;
    int insurance;       // 1 = Yes, 0 = No
};

int main() {
    struct Patient p;
    float totalBill = 0, discount = 0, insuranceCover = 0, finalBill = 0;
    float perDayCharge;

    // Input patient details
    printf("Enter Patient ID: ");
    scanf("%d", &p.patientID);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Admission Type (1-General, 2-ICU): ");
    scanf("%d", &p.admissionType);

    printf("Enter Number of Days Admitted: ");
    scanf("%d", &p.daysAdmitted);

    printf("Insurance Available? (1-Yes, 0-No): ");
    scanf("%d", &p.insurance);

    // Determine per-day charge
    if (p.admissionType == 2)
        perDayCharge = 5000;   // ICU
    else
        perDayCharge = 2000;   // General

    // Calculate total bill
    totalBill = perDayCharge * p.daysAdmitted;

    // Senior citizen discount
    if (p.age > 60) {
        discount = totalBill * 0.10;   // 10% discount
    }

    // Insurance coverage
    if (p.insurance == 1) {
        insuranceCover = totalBill * 0.70;  // 70% coverage
    }

    // Final bill calculation
    finalBill = totalBill - discount - insuranceCover;

    // Output
    printf("\n--- PATIENT BILL DETAILS ---");
    printf("\nPatient ID        : %d", p.patientID);
    printf("\nTotal Bill        : ₹%.2f", totalBill);
    printf("\nSenior Discount   : ₹%.2f", discount);
    printf("\nInsurance Covered : ₹%.2f", insuranceCover);
    printf("\nFinal Amount Payable: ₹%.2f\n", finalBill);

    return 0;
}
