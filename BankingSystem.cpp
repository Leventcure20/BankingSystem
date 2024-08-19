#include <iostream>
#include <string> 
#include <vector>


class Bank {
    int account_number;
    std::string account_holder;
    double balance;

public:
    // Constructor
    Bank(int acc_num, std::string acc_hold, int bal) {
        account_number = acc_num;
        account_holder = acc_hold;
        balance = bal; // Variable initialization
    }

    // Getter for account number
    int get_account_number() {
        return account_number;
    }

    // Getter for account holder
    std::string get_account_holder() {
        return account_holder;
    }

    // Getter for balance
    double get_balance() {
        return balance;
    }

    // Method to withdraw money
    void withdraw(double withdraw_amount) {
        if (withdraw_amount > balance) {
            std::cout << "Insufficient balance!" << std::endl;
        } else {
            balance -= withdraw_amount;
            std::cout<<"Your new balance is "<<balance<<std::endl; 
        }
    }
    //Method to deposit money
    void deposit(double deposit_amount) {
        balance += deposit_amount;
        std::cout<<"Hi " << account_holder<<", your balance is "<<balance<<std::endl;
    }
    void display_balance() {
        std::cout<<"Hi " << account_holder<<", your balance is "<<balance<<std::endl;
    }

    void display_info() {
        std::cout<<"Account number: "<<account_number<<std::endl;
        std::cout<<"Account holder: "<<account_holder<<std::endl;
        std::cout<<"Account balance: "<<balance<<std::endl;

    }
};

int main() {

    //declaring vectors for the different data types for each use
     std::vector<Bank> accounts = {
        Bank(1001, "Alice", 500.0),
        Bank(1002, "Bob", 300.0),
        Bank(1003, "Charlie", 700.0)
    };
    //declaring an option to let the user choose what operation they want the ATM to perform
    std::string option;
    //declaring the data types for each user
    int account_number;
    std::string account_holder;
    double balance;

    //asking the user to either create an account or continue with the user interaction
    std::cout<<"Hello there! Type 'create' if you are creating an account or 'continue' to process a transaction."<<std::endl;
    std::cin>>option;
    if (option == "create") {
        std::cout<<"Enter your account number"<<std::endl;
        std::cin>>account_number;
        std::cin.ignore(); 

        std::cout<<"Enter your account holder name"<<std::endl;
        std::getline(std::cin, account_holder);

        std::cout<<"Enter your total balance: " <<std::endl;
        std::cin>>balance;

        accounts.push_back(Bank(account_number, account_holder, balance));

        accounts[3].display_info();

        std::string option;
        std::cout<<"Type 'withdraw' to withdraw or 'deposit' to deposit."<<std::endl;
        std::cin>>option;

        if (option == "withdraw") {
            double withdraw;
            std::cout<<"How much would you like to withdraw? "<<std::endl;
            std::cin>>withdraw;
            int account_size;
            account_size = accounts.size()-1;
            accounts[account_size].withdraw(withdraw);
        } else {
            double deposit;
            int account_size;
            std::cout<<"How much would you like to deposit? "<<std::endl;
            std::cin>>deposit;

            account_size = accounts.size()-1;
            accounts[account_size].deposit(deposit);
        }
    } else if (option == "continue") {
        bool account_found = false;
        int account_number;
        std::cout<<"What is your account number? "<<std::endl;
        std::cin>>account_number;

        for (int account = 0; account<accounts.size();account++) {
            if (accounts[account].get_account_number() == account_number) {
                account_found = true;
                std::string option;
                std::cout<<"Type 'withdraw' to withdraw or 'deposit' to deposit"<<std::endl;
                std::cin>>option;
                if (option == "withdraw") {
                    double amount;
                    std::cout<<"What is the amount that you would like to withdraw? "<<std::endl;
                    std::cin>>amount;
                    accounts[account].withdraw(amount);
                } else {
                    double amount;
                    std::cout<<"What is the amount that you would like to deposit? " <<std::endl;
                    std::cin>>amount;
                    accounts[account].deposit(amount);
                }
                break;
            } 
        }
        if (!account_found) {
        std::cout << "Account not found. Press run to restart" << std::endl;
        }
    } else {
        std::cout<<"Insufficient action. Press run again to start over"<<std::endl;
    }
    return 0;
}