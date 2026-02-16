#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int accountNumber;
    char name[50];
    char password[20];
    float balance;
} Account;

int accountExists(int accNo) {
    FILE *fp = fopen("accounts.txt", "r");
    if (fp == NULL)
        return 0;

    Account acc;
    while (fscanf(fp, "%d|%49[^|]|%19[^|]|%f\n",
                  &acc.accountNumber,
                  acc.name,
                  acc.password,
                  &acc.balance) == 4) {
        if (acc.accountNumber == accNo) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void createAccount() {
    Account acc;

    printf("Enter Account Number: ");
    scanf("%d", &acc.accountNumber);
    getchar();

    if (accountExists(acc.accountNumber)) {
        printf("Account already exists!\n");
        return;
    }

    printf("Enter Name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0';

    printf("Set Password: ");
    fgets(acc.password, sizeof(acc.password), stdin);
    acc.password[strcspn(acc.password, "\n")] = '\0';

    acc.balance = 0.0;

    FILE *fp = fopen("accounts.txt", "a");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }

    fprintf(fp, "%d|%s|%s|%.2f\n",
            acc.accountNumber,
            acc.name,
            acc.password,
            acc.balance);

    fclose(fp);

    printf("Account created successfully!\n");
}

int authenticate(int accNo, char *password, Account *acc) {
    FILE *fp = fopen("accounts.txt", "r");
    if (fp == NULL) {
        printf("No accounts found!\n");
        return 0;
    }

    while (fscanf(fp, "%d|%49[^|]|%19[^|]|%f\n",
                  &acc->accountNumber,
                  acc->name,
                  acc->password,
                  &acc->balance) == 4) {

        if (acc->accountNumber == accNo &&
            strcmp(acc->password, password) == 0) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void rewriteFile(Account updatedAcc) {
    FILE *fp = fopen("accounts.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("File error!\n");
        return;
    }

    Account acc;

    while (fscanf(fp, "%d|%49[^|]|%19[^|]|%f\n",
                  &acc.accountNumber,
                  acc.name,
                  acc.password,
                  &acc.balance) == 4) {

        if (acc.accountNumber == updatedAcc.accountNumber) {
            fprintf(temp, "%d|%s|%s|%.2f\n",
                    updatedAcc.accountNumber,
                    updatedAcc.name,
                    updatedAcc.password,
                    updatedAcc.balance);
        } else {
            fprintf(temp, "%d|%s|%s|%.2f\n",
                    acc.accountNumber,
                    acc.name,
                    acc.password,
                    acc.balance);
        }
    }

    fclose(fp);
    fclose(temp);

    fp = fopen("accounts.txt", "w");
    temp = fopen("temp.txt", "r");

    while (fgets(updatedAcc.name, sizeof(updatedAcc.name), temp)) {
        fputs(updatedAcc.name, fp);
    }

    fclose(fp);
    fclose(temp);
}

void deposit() {
    int accNo;
    char password[20];
    float amount;
    Account acc;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    getchar();

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    if (!authenticate(accNo, password, &acc)) {
        printf("Authentication failed!\n");
        return;
    }

    printf("Enter Amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    acc.balance += amount;
    rewriteFile(acc);

    printf("Deposit successful! New Balance: %.2f\n", acc.balance);
}


void withdraw() {
    int accNo;
    char password[20];
    float amount;
    Account acc;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    getchar();

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    if (!authenticate(accNo, password, &acc)) {
        printf("Authentication failed!\n");
        return;
    }

    printf("Enter Amount: ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > acc.balance) {
        printf("Invalid or insufficient balance!\n");
        return;
    }

    acc.balance -= amount;
    rewriteFile(acc);

    printf("Withdrawal successful! New Balance: %.2f\n", acc.balance);
}

void checkBalance() {
    int accNo;
    char password[20];
    Account acc;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    getchar();

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    if (authenticate(accNo, password, &acc)) {
        printf("Name: %s\nBalance: %.2f\n",
               acc.name, acc.balance);
    } else {
        printf("Authentication failed!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Banking System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
