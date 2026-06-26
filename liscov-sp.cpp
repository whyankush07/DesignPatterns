// every child class should be substitutable for parent class
#include "iostream"

using namespace std;

class NonWithDrawAbleAccount {
protected:
    double balance;
public:
    virtual void deposit(double amount)= 0;
};

class WithDrawAbleAccount : public NonWithDrawAbleAccount {
public:
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount: public WithDrawAbleAccount {
public:
    void deposit(double amount) override {
        if (amount <= 0) {
            throw runtime_error("Amount should be positive!!");
        }
        this->balance += amount;
    }

    void withdraw(double amount) override {
        if (amount > this->balance) {
            throw runtime_error("Insifficient balance!");
        }
        this->balance -= amount;
    }
};

class CurrentAccount: public WithDrawAbleAccount {
public:
    void deposit(double amount) override {
        if (amount <= 0) {
            throw runtime_error("Amount should be positive!!");
        }
        this->balance += amount;
    }

    void withdraw(double amount) override {
        if (amount > this->balance) {
            throw runtime_error("Insifficient balance!");
        }
        this->balance -= amount;
    }
};

class FDAccount: public NonWithDrawAbleAccount {
public:
    void deposit(double amount) override {
        if (amount <= 0) {
            throw runtime_error("Amount should be positive!!");
        }
        this->balance += amount;
    }
};