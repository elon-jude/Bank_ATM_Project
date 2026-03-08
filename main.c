#include <stdio.h>
#include <stdlib.h>

int main()
{
    // -------------------------------
    //  Very simple ATM simulation
    // -------------------------------
    
    int pin = 1234;   int choice;          // secret PIN (hard-coded for simplicity) & choose variable for menu selection
    int entered_pin;
    float balance = 0.0;      // starting balance
    float amount;
    char name[50];          // variable to store user's name (not used in logic, just for fun)
    
    FILE *file;
    char users[] = "users";

    // Try to read previous balance from file
    file = fopen("users.txt", "r");
    if (file != NULL)
    {
        fscanf(file, "%f", &balance);
        fclose(file);
        printf("Hello user:", name);
        printf("Previous balance loaded: %.2f\n", balance);
    }
    else
    {
        printf("No previous data found. Starting with 0.00\n");
    }

    // === PIN check ===
    printf("\n=== Welcome to Mini ATM ===\n");
    printf("Enter PIN: ");
    scanf("%d", &entered_pin);

    printf("Enter the user name on the card: ");
    scanf("%s", name);
    if (entered_pin != pin)
    {
        printf("Wrong PIN!\n");
        printf("Program will now close.\n");
        return 0;
    }else
    {
    printf("PIN correct. Access granted.\n\n");
    }
    // === Main menu loop ===
    do
    {
        printf("\n");
        printf("1. Check balance\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Exit\n");
        printf("Your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Your current balance: %.2f GHS\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                
                if (amount > 0)
                {
                    balance += amount;
                    printf("Deposit successful. New balance: %.2f GHS\n", balance);
                }
                else
                {
                    printf("Invalid amount!\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                
                if (amount > 0 && amount <= balance)
                {
                    balance -= amount;
                    printf("Withdrawal successful. New balance: %.2f GHS\n", balance);
                }
                else if (amount > balance)
                {
                    printf("Not enough money in account!\n");
                }
                else
                {
                    printf("Invalid amount!\n");
                }
                break;

            case 4:
                printf("Thank you. Goodbye.\n");
                break;

            default:
                printf("Wrong choice. Please select 1-4.\n");
        }

        // Save balance after every operation
        file = fopen("users.txt", "w");
        if (file != NULL)
        {
            fprintf(file, "hello %s\n", name); 
            fprintf(file,"your balance is: $%.2f", balance); 
            fclose(file);  
        }
        else
        {
            printf("Warning: Could not save balance!\n");
        }

    } while (choice != 4);

    return 0;
}