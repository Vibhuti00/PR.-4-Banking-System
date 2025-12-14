#include <iostream>
#include <string>
using namespace std;
class BankAccount // CLASS BANK ACCOUNT
{
private:
    int accountNumber = 0;
    string accountHolderName = "";
    double balance = 0;

public:
    void deopsit(double amount) // DEOPSIT METHOD
    {
        balance += amount;
    }
    void withdraw(double amount) // WITHDRAW METHOD
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Not Enough Balance" << endl;
        }
    }
    double getBalance() // GET METHOD BALANCE
    {
        return balance;
    }
    void displayAccountInfo() // DISPLAY METHOD ACCOUNT INFORMATION
    {
        cout << "-----------------------------" << endl;
        cout << "Account Holder Name : " << accountHolderName << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Balance" << balance << endl;
    }
};
class SavingAccount : private BankAccount // DERIVED CLASS SAVING ACCOUNT
{
private:
    float rate;

public:
    void calculateInterest(float rate) // METHOD CALCULATE INTEREST RATE
    {
        rate = 10;
    }
};
class CheckingAccount : private BankAccount // DERIVED CLASS CHECKING ACCOUNT
{
private:
    double overdraft;

public:
    void checkOverdraft(double limit) // METHOD CHECK OVERDTAFT
    {
        overdraft = limit;
    }
};
class FixDepositAccount : private BankAccount // DERIVED CLASS FIX DEPOSIT ACCOUNT
{
private:
    int term;

public:
    void calculateInterest(int n) // METHOD CALCULATE TERM
    {
        term = n;
    }
};
int main()
{
    BankAccount *ba;
    int choice;
    int accountNumber;
    string accountHolderName;
    double balance;
    double limit;
    int n; // MONTHS/YERS

    cout << "Select Your Bank Account." << endl;
    cout << "1. Saving Account." << endl;
    cout << "2. Checking Account." << endl;
    cout << "3. Fixed Deposit Account." << endl;
    cout << "0. Exit." << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    cout << "Enter Your Account Number : ";
    cin >> accountNumber;
    cout << "Enter Account Holder Name : ";
    cin >> accountHolderName;
    cout << "Enter Bank Balance : ";
    cin >> balance;

    if (choice == 1)
    {
        cout << "Saving Account" << endl;
        ba = new SavingAccount();
    }
    else if (choice == 2)
    {
        cout << "Checking Account" << endl;
        ba = new CheckingAccount();
    }
    else if (choice == 3)
    {
        cout << "Fix Deposit Amount in term" << n << endl;
        ba = new FixDepositAccount();
    }
    else
    {
        cout << "Wront Choice";
    }
    do
    {
        switch (choice)
        {
        case 1:
            cout << "Deposit Amount.";
            ba->deopsit();
            break;
        case 2:
            cout << "Withdraw Amount.";
            ba->withdraw();
            break;
        case 3:
            cout << "Balance In Your Account.";
            ba->getBalance();
            break;
        case 4:
            cout << "Display Account Information.";
            ba->displayAccountInfo();
        case 0:
            cout << "Exit";
            break;
        default:
            cout << "Wrong Choice.";
        }
    } while (choice != 4);
    return 0;
}
