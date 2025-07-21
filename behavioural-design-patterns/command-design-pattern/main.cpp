#include<iostream>
#include<stack>

using namespace std;

class Command {
    public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

class Device {
    public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Device() = default;
};

class TV : public Device {
    public:
    void turnOn() override {
        cout << "TV Turned ON" << endl;
    }

    void turnOff() override {
        cout << "TV Turned OFF" << endl;
    }
};

class Radio : public Device {
    public:
    void turnOn() override {
        cout << "Radio Turned ON" << endl;
    }

    void turnOff() override {
        cout << "Radio Turned OFF" << endl;
    }
};

class TurnOnCommand : public Command {
    private:
    Device* device;
    public:
    TurnOnCommand(Device* d) : device(d) {}

    void execute() override {
        device->turnOn();
    }

    void undo() override {
        device->turnOff();
    }
};

class TurnOffCommand : public Command {
    private:
    Device* device;
    public:
    TurnOffCommand(Device* d) : device(d) {}

    void execute() override {
        device->turnOff();
    }

    void undo() override {
        device->turnOn();
    }
};


class Remote {
    private:
    stack<Command*> st;
    public:
    void execute(Command* cmd) {
        cmd->execute();
        st.push(cmd);
    }

    void undo() {
        if (!st.empty()) {
            Command* lastCmd = st.top();
            st.pop();
            cout << "undo operation : ";
            lastCmd->undo();
        } else {
            cout << "Nothing to undo." << endl;
        }
    }
};

int main() {

    Device* tv = new TV();

    Command* turnOnTv = new TurnOnCommand(tv);
    Command* turnOffTv = new TurnOffCommand(tv);

    Remote r;

    r.execute(turnOnTv);

    r.execute(turnOffTv);

    Device* radio = new Radio();

    Command* turnOnRadio = new TurnOnCommand(radio);
    Command* turnOffRadio = new TurnOffCommand(radio);

    r.execute(turnOnRadio);

    r.execute(turnOffRadio);


    r.undo();
    r.undo();
    r.undo();

    delete tv;
    delete turnOnTv;
    delete turnOffTv;

    delete radio;
    delete turnOnRadio;
    delete turnOffRadio;

    return 0;
}