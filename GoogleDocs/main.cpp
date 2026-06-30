#include "iostream"
#include "DocumentEditor.h"

int main() {
    Document* doc = new Document();
    Persistance* storage = new saveToFile();

    DocumentEditor* editor = new DocumentEditor(doc, storage);

    //* formalities--->>
}