// every class should be close for modification and open for extension
// we mainly use abstraction, inheritance and polymorphism with this
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

class Persistance {
private:
    ShoppingCart* cart;
public:
    virtual void save() = 0;
};

class SaveToMongo : public Persistance {
    public:
        void save() override {
            cout << "Saving to MongoDB\n";
        }
};
class SaveToSQL : public Persistance {
    public:
        void save() override {
            cout << "Saving to SQL\n";
        }
};
class SaveToFile : public Persistance {
    public:
        void save() override {
            cout << "Saving to File..\n";
        }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Dahi", 20.0));
    cart->addProduct(new Product("Rice", 150.0));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistance* mongo = new SaveToMongo();
    Persistance* sql = new SaveToSQL();
    Persistance* file = new SaveToFile();
    mongo->save();
    sql->save();
    file->save();
}