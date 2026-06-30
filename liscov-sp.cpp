// every child class should be substitutable for parent class
#include "iostream"

using namespace std;

class NonWithDrawAbleAccount {
public:
    virtual void deposit(double amount)= 0;
};

class WithDrawAbleAccount : public NonWithDrawAbleAccount {
public:
    virtual void withdraw(double amount) = 0;
};
class SavingsAccount: public WithDrawAbleAccount {
private:
    double balance;
public:
    void deposit(double amount) override {
        if (amount <= 0) {
            throw logic_error("Amount should be positive!!");
        }
        this->balance += amount;
    }

    void withdraw(double amount) override {
        if (amount > this->balance) {
            throw logic_error("Insifficient balance!");
        }
        this->balance -= amount;
    }
};

class CurrentAccount: public WithDrawAbleAccount {
private:
    double balance;
public:
    void deposit(double amount) override {
        if (amount <= 0) {
            throw logic_error("Amount should be positive!!");
        }
        this->balance += amount;
    }

    void withdraw(double amount) override {
        if (amount > this->balance) {
            throw logic_error("Insifficient balance!");
        }
        this->balance -= amount;
    }
};

class FDAccount: public NonWithDrawAbleAccount {
private:
    double balance;
public:
    void deposit(double amount) override {
        if (amount <= 0) {
            throw logic_error("Amount should be positive!!");
        }
        this->balance += amount;
    }
};

// Signature Rules
// 1. Method Aargument Rule -> override function of child class should have same argument type as that of parent class 
// 2. Return Type Rule -> override function of child class should have same or narrower return type of parent class e.g Animal* or Dog*
// 3. Exception Error -> chlid class should throw sub-class-error of parent class or same error, not of diffenent error class or their subtypes [noexcept(false)]