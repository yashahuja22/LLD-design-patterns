#include<iostream>

using namespace std;

class Printer {
    public:
    virtual void print(const string& text, int noOfCopies) = 0;
};

class OldPrinter {
    public: 
    void oldPrinterFunction(const string& text) {
        cout << text << endl;
    }
};

class PrinterAdapter : public Printer {
    private:
    OldPrinter* oldPrinter;

    public:
    PrinterAdapter(OldPrinter* old) : oldPrinter(old) {}

    void print(const string& text, int noOfCopies) override {

        cout << "printing using old printer" << endl;
        for (int i = 1; i <= noOfCopies; ++i)
            oldPrinter->oldPrinterFunction(text);
            
    }
};


int main () {
    OldPrinter* oldPrinter;

    Printer* p = new PrinterAdapter(oldPrinter);

    p->print("Hello", 10);

    return 0;
}