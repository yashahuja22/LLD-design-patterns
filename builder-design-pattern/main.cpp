#include<iostream>

using namespace std;

class Computer {
public:
    string CPU;
    string RAM = "8GB DDR4"; // Default value
    string Storage;
    string GPU;

    void display() {
        cout << "Computer Specifications:" << endl;
        cout << "CPU: " << CPU << endl;
        cout << "RAM: " << RAM << endl;
        cout << "Storage: " << Storage << endl;
        cout << "GPU: " << GPU << endl;
    }

    void setCPU(const string& cpu) {
        CPU = cpu;
    }
    void setRAM(const string& ram) {
        RAM = ram;
    }
    void setStorage(const string& storage) {
        Storage = storage;
    }
    void setGPU(const string& gpu) {
        GPU = gpu;
    }
};

// interface for the builder
// This defines the methods that concrete builders must implement
// to construct different parts of the computer.
class ComputerBuilder {
    public:
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual void buildGPU() = 0;
    virtual void display() = 0;

    virtual ~ComputerBuilder() = default; // Virtual destructor for proper cleanup
};

class GamingComputerBuilder : public ComputerBuilder {
    Computer* computer;
public:
    GamingComputerBuilder() {
        computer = new Computer();
    }
    void buildCPU() override {
        computer->setCPU("Intel Core i9");
    }
    void buildRAM() override {
        computer->setRAM("32GB DDR4");
    }
    void buildStorage() override {
        computer->setStorage("1TB SSD");
    }
    void buildGPU() override {
        computer->setGPU("NVIDIA RTX 3080");
    }

    void display() override {
        computer->display();
    }
};

class normalComputerBuilder : public ComputerBuilder {
    Computer* computer;
public:
    normalComputerBuilder() {
        computer = new Computer();
    }
    void buildCPU() override {
        computer->setCPU("Intel Core i5");
    }
    void buildRAM() override {
        computer->setRAM("16GB DDR4");
    }
    void buildStorage() override {     
        computer->setStorage("512GB SSD");
    }
    void buildGPU() override {
        computer->setGPU("NVIDIA GTX 1660");
    }
    void display() override {
        computer->display();
    }
};

class ComputerDirector {
public:
    void construct(ComputerBuilder* builder) {
        builder->buildCPU();
        builder->buildRAM();
        builder->buildStorage();
        builder->buildGPU();
    }
};

int main() {
    ComputerBuilder* builder = new GamingComputerBuilder();
    ComputerDirector director;
    director.construct(builder);

    builder->display();

    delete builder;

    builder = new normalComputerBuilder();
    director.construct(builder);
    builder->display();

    delete builder;
    return 0;
}