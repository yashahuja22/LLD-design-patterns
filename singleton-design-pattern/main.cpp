#include<iostream>
using namespace std;

class Logger {

    private:
        static Logger* instance;
        Logger() {
            cout << "Logger initialized." << endl;
        }

    public:
    // Delete copy constructor
    Logger(const Logger&) = delete;
    // Delete assignment operator
    Logger& operator=(const Logger&) = delete;

    // Static method to access the single instance
    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger();  // Allocate only once
        }
        return instance;
    }

    void log(const string& message) {
        cout << "Log: " << message << endl;
    }
};

// ✅ Define static variable outside the class
Logger* Logger::instance = nullptr;

int main() {

    Logger* l1 = Logger::getInstance(); // First access, creates the instance
    Logger* l2 = Logger::getInstance(); // Returns the same instance
    
    l1->log("This is the first log message.");
    l2->log("This is the second log message.");
    
    if (l1 == l2) {
        cout << "Both l1 and l2 point to the same Logger instance." << endl;
    } else {
        cout << "l1 and l2 point to different Logger instances." << endl;   
    }
    return 0;
}