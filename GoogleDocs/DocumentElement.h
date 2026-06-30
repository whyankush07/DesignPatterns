#pragma once
#include "iostream"

using namespace std;

class DocumentElement {
public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement {
private:
    string text;
public:
    TextElement(string text) : text(text) {};

    string render() override {
        return text;
    }
};

class ImageElement : public DocumentElement {
private:
    string image;
public:
    ImageElement(string image) : image(image) {};

    string render() override {
        return "[Image: " + image + " ]";
    }
};

class NewLineElement : public DocumentElement {
    string render() override {
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement {
    string render() override {
        return "\t";
    }
};