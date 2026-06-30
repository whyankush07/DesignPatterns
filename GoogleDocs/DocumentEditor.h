#include "Document.h"
#include "Persistance.h"
#include "vector"

using namespace std;

class DocumentEditor {
private:
    Document* document;
    Persistance* db;
    string renderedDocument;
public:
    DocumentEditor(Document* doc, Persistance* db){
        this->document = doc;
        this->db = db;
    }

    void addText(string text) {
        document->addElement(new TextElement(text));
    }

    void addImage(string path) {
        document->addElement(new ImageElement(path));
    }

    void addNewLine() {
        document->addElement(new NewLineElement());
    }

    void addTabSpace() {
        document->addElement(new TabSpaceElement());
    }

    string renderDocument() {
        if (renderedDocument.empty()) {
            renderedDocument = document->render();
        }
        renderedDocument;
    }

    void saveDocument() {
        db->save(renderDocument());
    }
};