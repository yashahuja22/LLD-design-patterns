#include<iostream>
#include<string>
#include<vector>

using namespace std;

class User; // ✅ Forward declaration

class ChatRoom {
    public:
    virtual void send(User* sender, const string& message) = 0;
    virtual void registerUser(User* u) = 0;
    virtual ~ChatRoom() = default;
};

class User {
    private:
    ChatRoom* chatRoom = nullptr;
    string name;

    public:
    User(const string& name) : name(name) {}

    void setChatRoom(ChatRoom* chatRoom) {
        this->chatRoom = chatRoom;
        this->chatRoom->registerUser(this);
    }

    void send(const string& message) {
        if (chatRoom != nullptr) {
            chatRoom->send(this, message);
        } else {
            cout << name << " is not registered with any chatroom" << endl;
        }
    }

    void receive(const string& from, const string& message) {
        cout << name << " received message from " << from << ": " << message << endl;
    }

    string getName() {
        return name;
    }
};

class MatrixGroup : public ChatRoom {
    private:
    vector<User*> groupMembers;
    public:

    void registerUser(User* u) override {
        groupMembers.push_back(u);
    }

    void send(User* sender, const string& message) override {
        for (auto u : groupMembers) {
            if (u != sender)
                u->receive(sender->getName(),message);
        }
    }
};

int main() {
    User* alice = new User("Alice");
    User* bob = new User("Bob");

    ChatRoom* matrixGrp = new MatrixGroup();
    alice->setChatRoom(matrixGrp);
    bob->setChatRoom(matrixGrp);

    alice->send("Hello Everyone!!");

    bob->send("Hi Alice");

    delete alice;
    delete bob;
    delete matrixGrp;

    return 0;
}