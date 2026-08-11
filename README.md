# 🏦 Simple Banking System in C

A simple **Banking System implemented in C** that demonstrates basic banking operations such as creating users, depositing money, withdrawing money, and displaying account balances.

This project is designed to practice **C programming fundamentals**, including structures, arrays, functions, pointers, and basic input/output operations.

## ✨ Features

* Create and store multiple users
* Set an initial account balance
* Deposit money into an account
* Withdraw money from an account
* Check account balance
* Prevent withdrawals when there are insufficient funds
* Limit the maximum number of users

## 🛠️ Technologies Used

* **C**
* Standard C Libraries:

  * `stdio.h`
  * `stdlib.h`
  * `string.h`

## 📂 Project Structure

```text
banking-system/
│
├── banking.c
└── README.md
```

## ⚙️ How to Run

### 1. Clone the repository

```bash
git clone https://github.com/your-username/banking-system.git
```

### 2. Navigate to the project directory

```bash
cd banking-system
```

### 3. Compile the program

Using GCC:

```bash
gcc bankingc -o banking
```

### 4. Run the program

On Linux/macOS:

```bash
./banking
```

On Windows:

```bash
banking.exe
```

## 💻 Example

The program creates two users and performs basic banking operations.

### Output

```text
User added: Alice with balance 1000.00
User added: Bob with balance 500.00
Deposited 200.00 to Alice's account. New balance: 1200.00
Withdrew 100.00 from Bob's account. New balance: 400.00
User: Alice, Balance: 1200.00
User: Bob, Balance: 400.00
```

## 📚 Concepts Practiced

This project helped me practice:

* Structures (`struct`)
* Arrays
* Functions
* Pointers
* String handling
* Conditional statements
* Global variables
* Basic error handling
* Compilation and execution using GCC

## 🚀 Future Improvements

Some features that could be added in future versions:

* Interactive menu-based system
* User login/authentication
* Account numbers
* Money transfer between users
* Transaction history
* Delete or update users
* File handling for persistent data storage
* Input validation
* Use of `double` instead of `float` for better monetary precision

