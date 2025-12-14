#include <iostream>
#include <string>
using namespace std;
class BankAccount // BASE CLASS
{
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }
    virtual void deposit(double amount)
    {
        balance += amount;
    }
    virtual void withdraw(double amount)
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
    double getBalance()
    {
        return balance;
    }
    virtual void displayAccountInfo()
    {
        cout << endl
             << "-----------------------------" << endl;
        cout << "Account Holder Name : " << accountHolderName << endl;
        cout << "Account Number      : " << accountNumber << endl;
        cout << "Account Balance     : " << balance << endl;
    }
    virtual ~BankAccount() {}
};
class SavingAccount : public BankAccount // SAVING ACCOUNT
{
private:
    float rate;

public:
    SavingAccount(int accNo, string name, double bal, float r) : BankAccount(accNo, name, bal)
    {
        rate = r;
    }
    void calculateInterest()
    {
        double interest = balance * rate / 100;
        balance += interest;
    }
};
class CheckingAccount : public BankAccount // CHECKING ACCOUNT
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit) : BankAccount(accNo, name, bal)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override
    {
        if (amount <= balance + overdraftLimit)
        {
            balance -= amount;
        }
        else
        {
            cout << "Overdraft limit exceeded" << endl;
        }
    }
};
class FixDepositAccount : public BankAccount // FIXED DEPOSIT ACCOUNT
{
private:
    int term;

public:
    FixDepositAccount(int accNo, string name, double bal, int t) : BankAccount(accNo, name, bal)
    {
        term = t;
    }
    void calculateInterest()
    {
        double interest = balance * 0.08 * term;
        balance += interest;
    }
};
int main() // MAIN FUNCTION
{
    BankAccount *ba = nullptr;
    int choice;
    int accountNumber;
    string accountHolderName;
    double balance;
    double amount;
    cout << endl
         << "-------------------------------" << endl;
    cout << "Select Your Bank Account" << endl;
    cout << "1. Saving Account" << endl;
    cout << "2. Checking Account" << endl;
    cout << "3. Fixed Deposit Account" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;
    cout << endl
         << "-------------------------------" << endl;
    cout << "Enter Account Number : ";
    cin >> accountNumber;
    cout << "Enter Account Holder Name : ";
    cin >> accountHolderName;
    cout << "Enter Initial Balance : ";
    cin >> balance;
    if (choice == 1)
    {
        float rate;
        cout << "Enter Interest Rate : ";
        cin >> rate;
        ba = new SavingAccount(accountNumber, accountHolderName, balance, rate);
    }
    else if (choice == 2)
    {
        double limit;
        cout << "Enter Overdraft Limit : ";
        cin >> limit;
        ba = new CheckingAccount(accountNumber, accountHolderName, balance, limit);
    }
    else if (choice == 3)
    {
        int term;
        cout << "Enter Term (years) : ";
        cin >> term;
        ba = new FixDepositAccount(accountNumber, accountHolderName, balance, term);
    }
    else
    {
        cout << "Wrong Choice";
        return 0;
    }
    int option;
    do
    {
        cout << endl
             << "-------------------------------" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Display Info" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter option : ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter Amount : ";
            cin >> amount;
            ba->deposit(amount);
            break;
        case 2:
            cout << "Enter Amount : ";
            cin >> amount;
            ba->withdraw(amount);
            break;
        case 3:
            cout << "Balance : " << ba->getBalance() << endl;
            break;
        case 4:
            ba->displayAccountInfo();
            break;
        case 0:
            cout << "Thank You";
            break;
        default:
            cout << "Choose Wrong Option";
        }
    } while (option != 0);
    return 0;
}
