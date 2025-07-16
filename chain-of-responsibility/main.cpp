#include<iostream>

using namespace std;

// Enum for Priority
enum class Priority {
    BASIC, INTERMEDIATE, CRITICAL
};

// Request class
class Request {
    private:
    Priority priority;

    public:
    Request(Priority p) : priority(p) {}

    Priority getPriority() const {
        return priority;
    }
};

// Handler Interface (Abstract Base Class)
class SupportHandler {
    public:
    virtual void setNextHandler(SupportHandler* nextHandler) = 0;
    virtual void handleRequest(const Request& r) = 0;
};

// Level 1 Support
class Level1SupportHandler : public SupportHandler {
    private:
        SupportHandler* nextHandler;
    public: 
    void setNextHandler(SupportHandler* nextHandler) override {
        this->nextHandler = nextHandler;
    }

    void handleRequest(const Request& r) override {
        if (r.getPriority() == Priority::BASIC) {
            cout << "Issue handled by level 1 support" << endl;
        } else if (nextHandler != nullptr) {
            nextHandler->handleRequest(r);
        }
    }
};

// Level 2 Support
class Level2SupportHandler : public SupportHandler {
    private:
    SupportHandler* nextHandler;

    public:
    void setNextHandler(SupportHandler* nextHandler) override {
        this->nextHandler = nextHandler;
    }

    void handleRequest(const Request& r) override {
        if (r.getPriority() == Priority::INTERMEDIATE) {
            cout << "Issue handled by level 2 support" << endl;
        } else if (nextHandler != nullptr) {
            nextHandler->handleRequest(r);
        }
    }
};

// Level 3 Support
class Level3SupportHandler : public SupportHandler {
    private: 
    SupportHandler* nextHandler;

    public: 
    void setNextHandler(SupportHandler* nextHandler) override {
        // No next handler for Level 3
    }

    void handleRequest(const Request& r) override {
        if (r.getPriority() == Priority::CRITICAL) {
            cout << "Issue handled by level 3 support" << endl;
        } else {
            cout << "Issue cannot be handled" << endl;
        }
    }
};

int main()  {
    // Create handlers
    SupportHandler* level1 = new Level1SupportHandler();
    SupportHandler* level2 = new Level2SupportHandler();
    SupportHandler* level3 = new Level3SupportHandler();

    // Chain the handlers
    level1->setNextHandler(level2);
    level2->setNextHandler(level3);

    // Create Requests
    Request r1(Priority::BASIC);
    Request r2(Priority::INTERMEDIATE);
    Request r3(Priority::CRITICAL);

    // Start handling from level 1
    level1->handleRequest(r1);
    level1->handleRequest(r2);
    level1->handleRequest(r3);

    return 0;
}