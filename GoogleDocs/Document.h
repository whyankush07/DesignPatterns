#pragma once
#include "vector"
#include "DocumentElement.h"

using namespace std;

class Document {
private:
    vector<DocumentElement*> elements;
public:
    void addElement(DocumentElement* element) {
        elements.push_back(element);
    }

    string render() {
        string result;
        for (auto element : elements) {
            result += element->render();
        }
        return result;
    }
};