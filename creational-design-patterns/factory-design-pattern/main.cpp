#include<iostream>

using namespace std;
class Vehicle {
    public:
    virtual void printVehicle() = 0;
    virtual ~Vehicle() {}
};

class TwoWheeler : public Vehicle {
    public:
    void printVehicle() override {
        cout<< "I am two wheeler" << endl;
    }
};

class FourWheeler : public Vehicle {
    public:
    void printVehicle() override {
        cout<< "I am four wheeler" << endl;
    }
};

class EightWheeler : public Vehicle {
    public:
    void printVehicle() override {
        cout<< "I am eight wheeler" << endl;
    }
};

class ThreeWheeler : public Vehicle {

    public: 
    void printVehicle() override {
        cout<< "I am three wheeler" << endl;
    }

};


class VehicleFactory {
    public:
    virtual Vehicle* createVehicle() = 0;
    virtual ~VehicleFactory() {}
};

class TwoWheelerFactory : public VehicleFactory {
    public:
    Vehicle* createVehicle() override {
        return new TwoWheeler();
    }
};

class FourWheelerFactory : public VehicleFactory {
    public:
    Vehicle* createVehicle() override {
        return new FourWheeler();
    }
};

class EightWheelerFactory : public VehicleFactory {
    public:
    Vehicle* createVehicle() override {
        return new EightWheeler();
    }
};

class ThreeWheelerFactory : public VehicleFactory {
    public: 
    Vehicle* createVehicle() override {
        return new ThreeWheeler();
    }
};

class Client {
    private:
    Vehicle* pVehicle;

    public:
    Client(VehicleFactory* factory) {
        pVehicle = factory->createVehicle();
    }

    Vehicle* getVehicle() {
        return pVehicle;
    }

    ~Client() {
        delete pVehicle;
    }
};

int main() {

    VehicleFactory* twoWheelerFactory = new TwoWheelerFactory();
    Client* twoWheelerClient = new Client(twoWheelerFactory);
    Vehicle* twoWheeler = twoWheelerClient->getVehicle();
    twoWheeler->printVehicle();

    VehicleFactory* fourWheelerFactory = new FourWheelerFactory();
    Client* fourWheelerClient = new Client(fourWheelerFactory);
    Vehicle* fourWheeler = fourWheelerClient->getVehicle();
    fourWheeler->printVehicle();

    VehicleFactory* threeWheelerFactory = new ThreeWheelerFactory();
    Client* threeWheelerClient = new Client(threeWheelerFactory);
    Vehicle* threeWheeler = threeWheelerClient->getVehicle();
    threeWheeler->printVehicle();


    delete twoWheelerFactory;
    delete twoWheelerClient;
    delete fourWheelerFactory;
    delete fourWheelerClient;
    delete threeWheelerFactory;
    delete threeWheelerClient;
    return 0;
}