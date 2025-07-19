#include<iostream>
using namespace std;

class Device {
    public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    virtual ~Device() = default;
};

class Tv : public Device {
    public:

    void turnOn() override {
        cout << "TV is turned ON" << endl;
    }

    void turnOff() override {
        cout << "TV is turned OFF" << endl;
    }
};

class Radio : public Device {

    void turnOn() override {
        cout << "Radio is turned ON" << endl;
    }

    void turnOff() override {
        cout << "Radio is turned OFF" << endl;
    }
};

class Remote {
    protected:
    Device* d;

    public:
    Remote(Device* dev) : d(dev) {} 

    virtual void turnOn() {
        d->turnOn();
    }

    virtual void turnOff() {
        d->turnOff();
    }

    virtual ~Remote() = default;
};

int main() {

    Device* tv = new Tv();
    Remote* tvRemote = new Remote(tv);
    tvRemote->turnOn();
    tvRemote->turnOff();

    Device* radio = new Radio();
    Remote* radioRemote = new Remote(radio);
    radioRemote->turnOn();
    radioRemote->turnOff();

    return 0;
}