#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ACCOUNTS 100
// Structure for account details
typedef struct 
{
int accountNumber;
char name[50];
float balance;
} Account;
// Array to hold all accounts
Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;
// Function to create a new account
void createAccount() {
printf("Enter account number: ");
scanf("%d", &accounts[numAccounts].accountNumber);
printf("Enter name: ");
scanf("%s", accounts[numAccounts].name);
printf("Enter initial balance: ");
scanf("%f", &accounts[numAccounts].balance);
numAccounts++;
printf("Account created successfully.\n");
}
// Function to deposit money
void deposit() {
int accountNumber;
float amount;
printf("Enter account number: ");
scanf("%d", &accountNumber);
printf("Enter amount to deposit: ");
scanf("%f", &amount);
for (int i = 0; i < numAccounts; i++) {
if (accounts[i].accountNumber == accountNumber) {
accounts[i].balance += amount;
printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
return;
}
}
printf("Account not found.\n");
}
// Function to withdraw money
void withdraw() {
int accountNumber;
float amount;
printf("Enter account number: ");
scanf("%d", &accountNumber);
printf("Enter amount to withdraw: ");
scanf("%f", &amount);
for (int i = 0; i < numAccounts; i++) {
if (accounts[i].accountNumber == accountNumber) {
if (accounts[i].balance >= amount) {
accounts[i].balance -= amount;
printf("Withdrawal successful. New balance: %.2f\n",
accounts[i].balance);
} else {
printf("Insufficient balance.\n");
}
return;
}
}
printf("Account not found.\n");
}
// Function to check balance
void checkBalance() {
int accountNumber;
printf("Enter account number: ");
scanf("%d", &accountNumber);
for (int i = 0; i < numAccounts; i++) {
if (accounts[i].accountNumber == accountNumber) {
printf("Account balance: %.2f\n", accounts[i].balance);
return;
}
}
printf("Account not found.\n");
}
// Function to display all account details
void displayAll() {
for (int i = 0; i < numAccounts; i++)
printf("Account number: %d, Name: %s, Balance: %.2f\n",
accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
}
int main()
{
int choice;
while (1)
{
printf("\nBank Management System\n");
printf("1. Create Account\n");
printf("2. Deposit\n");
printf("3. Withdraw\n");
printf("4. Check Balance\n");
printf("5. Display All Accounts\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
createAccount();
break;
case 2:
deposit();
break;
case 3:
withdraw();
break;
case 4:
checkBalance();
break;
case 5:
displayAll();
break;
case 6:
exit(0);
default:
printf("Invalid choice.\n");
}
}
return 0;
}
