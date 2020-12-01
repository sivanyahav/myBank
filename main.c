#include "myBank.h"
#include <stdio.h>


int main()
{

    char choice;
    printf("\nPlease choose a transaction type: \n");
    printf("O-Open Account\n");
    printf("B-Balance Inquiry\n");
    printf("D-Deposit\n");
    printf("W-Withdrawal\n");
    printf("C-Close Account\n");
    printf("I-Interest\n");
    printf("P-Print\n");
    printf("E-Exit\n\n");
    scanf("    %c",   &choice);

    while (choice != 'E')
    {
        if (choice != 'O' && choice != 'B' && choice != 'D' && choice != 'W' && choice != 'C' && choice != 'I' && choice != 'P' && choice != 'E')
        {
            printf("Invalid transaction type \n\n");
        }
        if (choice == 'O')
        {
            openAccount();
        }
        if (choice == 'B')
        {
            int account_number;
            printf("Please enter account number:");
            if(scanf("%d", &account_number)==0){printf("Failed to read the account number\n");}
            else{
            
            accountBalance(account_number);
            }
        }
        if (choice == 'D')
        {
            int account_number;
            printf("Please enter account number:");
            if(scanf("%d", &account_number)==0) {printf("Failed to read the account number\n");}
            else{
            accountDeposit(account_number);
            }
        }
        if (choice == 'W')
        {
            int account_number;
            printf("Please enter account number:");
            if(scanf("%d", &account_number)==0) {printf("Failed to read the account number\n");}
            else{
            scanf("%d", &account_number);
            accountWithdraw(account_number);
            }
        }
        if (choice == 'C')
        {
            int account_number;
            printf("Please enter account number:");
            if(scanf("%d", &account_number)==0) {printf("Failed to read the account number\n");}
            else{
            closeAccount(account_number);
            }
        }
        if (choice == 'I')
        {
            float rate;
            printf("Please enter interest rate:");
            if(scanf("%f", &rate)==0) {printf("Failed to read the interest rate\n");}
            else{
            rateAccount(rate);
            }
        }
        if (choice == 'P')
        {
            printAllOpen();
        }
    printf("\nPlease choose a transaction type: \n");
    printf("O-Open Account\n");
    printf("B-Balance Inquiry\n");
    printf("D-Deposit\n");
    printf("W-Withdrawal\n");
    printf("C-Close Account\n");
    printf("I-Interest\n");
    printf("P-Print\n");
    printf("E-Exit\n\n");
    scanf("  %c",   &choice);
    }

    if (choice == 'E')
    {
        closeAll();
    }

    return 0;
}