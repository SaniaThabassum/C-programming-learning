#include <stdio.h>

/* Function to check PIN attempts */
int checkPinAttempts(int attempts) {
    if (attempts > 3)
        return 0;   // Card blocked
    return 1;       // Card active
}

/* Function to check minimum balance */
int checkMinimumBalance(float balance, int accountType, float withdrawAmount) {
    float minBalance;

    // accountType: 1 = Savings, 2 = Current
    if (accountType == 1)
        minBalance = 1000;
    else
        minBalance = 5000;

    if ((balance - withdrawAmount) < minBalance)
        return 0;   // Insufficient balance
    return 1;
}

/* Function to validate withdrawal amount */
int validateAmount(float amount) {
    if ((int)amount % 100 != 0)
        return 0;   // Not multiple of 100
    if (amount > 25000)
        return 0;   // Exceeds daily limit
    return 1;
}

int main() {
    float balance, withdrawAmount;
    int pinAttempts, accountType;

    // Input
    printf("Enter account balance: ");
    scanf("%f", &balance);

    printf("Enter withdrawal amount: ");
    scanf("%f", &withdrawAmount);

    printf("Enter number of wrong PIN attempts: ");
    scanf("%d", &pinAttempts);

    printf("Account type (1-Savings, 2-Current): ");
    scanf("%d", &accountType);

    // Rule 1: PIN attempts check
    if (checkPinAttempts(pinAttempts) == 0) {
        printf("\nCARD BLOCKED: Too many incorrect PIN attempts.\n");
        return 0;
    }

    // Rule 2: Withdrawal amount validation
    if (validateAmount(withdrawAmount) == 0) {
        printf("\nWITHDRAWAL FAILED: Invalid amount or exceeds daily limit.\n");
        return 0;
    }

    // Rule 3: Minimum balance check
    if (checkMinimumBalance(balance, accountType, withdrawAmount) == 0) {
        printf("\nWITHDRAWAL FAILED: Minimum balance requirement not met.\n");
        return 0;
    }

    // If all checks passed
    balance = balance - withdrawAmount;

    printf("\nWITHDRAWAL SUCCESSFUL");
    printf("\nRemaining Balance: ₹%.2f\n", balance);

    return 0;
}
