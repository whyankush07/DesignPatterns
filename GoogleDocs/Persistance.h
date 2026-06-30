#pragma once

#include "iostream"
#include "fstream"
#include "atomic"

using namespace std;

class Persistance {
protected:
    static atomic<int> counter;
public:
    virtual void save(string data) = 0;
};

class saveToFile : public Persistance {
public:
    void save(string data) override {
        ofstream file("Document.h");
        if (file.is_open()) {
            file << data;
            file.close();
            cout << "Document saved to Document.txt" << endl;
        } else {
            cout << "[Error]: Unable to open file for writing!" << endl;
        }
    }
};

class saveToDB : public Persistance {
public:
    void save(string data) override {
        // save later
    }
};