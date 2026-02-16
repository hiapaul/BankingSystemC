// banking.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float balance;
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user(const char* name, float initial_balance) {
    if (user_count >= MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }
    strncpy(users[user_count].name, name, MAX_NAME_LEN);
    users[user_count].balance = initial_balance;
    user_count++;
    printf("User added: %s with balance %.2f\n", name, initial_balance);
}

void deposit(User* user, float amount) {
    if (amount < 0) {
        printf("Error: Deposit amount must be positive.\n");
        return;
    }
    user->balance += amount;
    printf("Deposited %.2f to %s's account. New balance: %.2f\n", amount, user->name, user->balance);
}

void withdraw(User* user, float amount) {
    if (amount < 0) {
        printf("Error: Withdrawal amount must be positive.\n");
        return;
    }
    if (amount > user->balance) {
        printf("Error: Insufficient funds for withdrawal.\n");
        return;
    }
    user->balance -= amount;
    printf("Withdrew %.2f from %s's account. New balance: %.2f\n", amount, user->name, user->balance);
}

void display_user(User* user) {
    printf("User: %s, Balance: %.2f\n", user->name, user->balance);
}

int main() {
    add_user("Alice", 1000.00);
    add_user("Bob", 500.00);
    deposit(&users[0], 200.00);
    withdraw(&users[1], 100.00);
    display_user(&users[0]);
    display_user(&users[1]);

    return 0;
}