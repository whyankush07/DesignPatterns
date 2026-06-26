// every class should follow only one respnsibility
#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) : name(name), price(price) {};
};

class ShoppingCart {
private:
    vector<Product*> products;
public:
    void addProduct(Product* p) {
        products.push_back(p);
    }

    const vector<Product*>& getProducts() {
        return products;
    }

    double calculateTotalPrice() {
        int total = 0;
        for (auto it: products) {
            total += it->price;
        }
        return total;
    }
};

class ShoppingCartPrinter {
private:
    ShoppingCart* cart;
public:
    ShoppingCartPrinter(ShoppingCart* cart) : cart(cart) {}

    void printInvoice() {
        for (auto it: cart->getProducts()) {
            cout << "Name: " << it->name << ", price: " << it->price << "\n";
        }
        cout << "Total Price: $" << cart->calculateTotalPrice() << "\n";
    }
};

class ShoppingCartStorage {
private:
    ShoppingCart* cart;
public:
    void saveToSQLDatabase() {
        cout << "saving to sql database...\n";
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Dahi", 20.0));
    cart->addProduct(new Product("Rice", 150.0));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* storage = new ShoppingCartStorage();
    storage->saveToSQLDatabase();
}