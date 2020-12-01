#include <stdio.h>
#include "myBank.h"
#define N 50
double accounts[N][2];
/*
Two-dimensional array for account management
50 rows for the amount of possible accounts
2 columns for account balance and account balance
*/
int accountNum = 0; //Count how many open accounts

void openAccount()
{
    if (accountNum < 50) //Checks if the account balance is incomplete
    {
        double amount;
        printf("Please enter amount for deposit:");
        if(scanf("%lf", &amount)==0) {printf ("Failed to read the amount\n\n");}
        else{
        if(amount<0){printf("Invalid Amount\n\n");}
        else{

        int ind;
        for (int i = 0; i < N; i++)
        {
            if (accounts[i][0] == 0)//Checks where the first line is that the account is closed
            {
                ind = i;
                break;
        
            }
        }
        accounts[ind][0] = 1;      // To update the status 1=Open account / 0=close account
        accounts[ind][1] = amount; // To update the amount in this account
        accountNum++;
        int account = 901 + ind;
        printf("New account number is: %d \n\n", account);
          }
        }
    }
    else
    {
    printf("Sorry! the bank is full\n\n");
    }
}

void accountBalance(int account_number)
{
    if (account_number <= 950 && account_number >= 901)//Input test
    {
        int indxAccount = account_number - 901;
        if (accounts[indxAccount][0] == 1)//Check if an open account is otherwise done nothing
        {
            double amount;
            amount = accounts[indxAccount][1];
            //go to the correct line according to the index and account_number 
            //And checks what the value is in the balance column
            printf("The balance of account number %d is: %0.2lf\n\n", account_number, amount);
        }
        else{
        printf("This account is closed \n\n");
        }
    }
    else{
    printf("Invalid account number \n\n");
    }
}

void accountDeposit(int account_number)
{
    if (account_number <= 950 && account_number >= 901)
    {
        int indxAccount = account_number - 901;
        if (accounts[indxAccount][0] == 1)
        {
            double deposit;
            double oldAmount = accounts[indxAccount][1];
            printf("Please enter the amount to deposit: ");
            if(scanf("%lf", &deposit)==0) {printf("Failed to read the amount\n\n");}
            else{
            if(deposit<0){printf("Cannot deposit a negative amount\n\n");}
            else{
            accounts[indxAccount][1] = oldAmount + deposit; //Adds money to the account
            double newAmount = accounts[indxAccount][1];
            printf("The new balance is: %0.2lf \n\n", newAmount);
            }
            }
        }
        else{
        printf("This account is closed \n\n");
        }
    }
    else{
    printf("Invalid account number \n\n");
    }
}

void accountWithdraw(int account_number)
{
    if (account_number <= 950 && account_number >= 901)
    {
        int indxAccount = account_number - 901;
        if (accounts[indxAccount][0] == 1)
        {
            double withdraw;
            double oldAmount = accounts[indxAccount][1];
            printf("Please enter the amount to withdraw:");
            if(scanf("%lf", &withdraw)==0){ printf("Failed to read the amount\n\n");}
            else{
                if(withdraw<0){printf("Cannot withdraw a negative amount\n\n");}
                else{
            if (withdraw <= oldAmount)//Checks if there is enough money in the account
            {
                accounts[indxAccount][1] = oldAmount - withdraw;//Takes money into account
                double newAmount = accounts[indxAccount][1];
                printf("The new balance is: %0.2lf \n\n", newAmount);
            }
            else{
            printf("Cannot withdraw more than the balance\n\n");
            }
            }
            }
        }
        else{
        printf("This account is closed \n\n");
        }
    }
    else{
    printf(" Invalid account number \n\n");
    }
}

void closeAccount(int account_number)
{
    if (account_number <= 950 && account_number >= 901)
    {
        int indxAccount = account_number - 901;
        if (accounts[indxAccount][0] == 1)
        {
            accounts[indxAccount][0] = 0;// To update the status 1=Open account / 0=close account
            accountNum--;//Decreases the number of open accounts
            printf(" Closed account number %d \n\n", account_number);
        }
        else{
        printf("This account is already closed \n\n");
        }
    }
    else{
    printf(" Invalid account number \n\n");
    }
}

void rateAccount(float rate)
{
    if(rate<0) {printf("Invalid interest rate\n\n");}
    else{
        for (int i = 0; i < N; i++)
        {
            double oldAmount = accounts[i][1];
            if (accounts[i][0] == 1)
            {
                accounts[i][1] = oldAmount + (oldAmount * rate) / 100;
            }
        }
    }
}

void printAllOpen()
{
    for (int i = 0; i < N; i++)
    {
        //Goes through the array and prints only the open accounts
        double balance = accounts[i][1];
        int account = 901 + i;
        if (accounts[i][0] == 1)
        {
            printf("The balance of account number %d is: %0.2lf\n", account, balance);
            
        }
    }
}

void closeAll()
{
    for (int i = 0; i < N; i++)
    {//Goes through the array and updates the status to close
        accounts[i][0] = 0;// To update the status 1=Open account / 0=close account
    }
    
}
