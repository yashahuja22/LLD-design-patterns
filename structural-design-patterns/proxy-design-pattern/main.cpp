#include<iostream>

using namespace std;

class Image {
    public: 
    virtual void display() = 0;
    virtual ~Image() = default;
};


class RealImage : public Image {
    private:
    string fileName;
    public:
    RealImage(const string& fileName) : fileName(fileName) {
        loadImage();
    }

    void loadImage() {
        cout << "loading image " << fileName << endl;
    }

    void display() override {
        cout << "displaying image " << fileName << endl;
    }
};

class ProxyImage : public Image {
    private:
    string fileName;
    RealImage* realImage = nullptr;

    public:
    ProxyImage(const string& fileName) : fileName(fileName) {}

    void display() override {
        if (realImage == nullptr) {
            realImage = new RealImage(fileName);
        }

        realImage->display();
    }

    ~ProxyImage() {
        cout << "destructor called" << endl;
        delete realImage;
    }
};

int main() {
    Image* img = new ProxyImage("yash.jpg");
    img->display();

    img->display();

    delete img;

    return 0;
}