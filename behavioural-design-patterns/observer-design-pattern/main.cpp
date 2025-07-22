#include<iostream>
#include<vector>

using namespace std;

class Observer {
    public:
    virtual void update(const string& videoTitle) = 0;
    virtual ~Observer() = default;
};

class Subject {
    public:
    virtual void subscribeChannel(Observer* ob) = 0;
    virtual void unsubscribeChannel(Observer* observer) = 0;
    virtual void notifyAll(const string& videoTitle) = 0;

    virtual ~Subject() = default;
};

class YouTubeChannel : public Subject {
    private:
    vector<Observer*> subscribers;

    public:
    void subscribeChannel(Observer* ob) override {
        subscribers.push_back(ob);
    }

    void unsubscribeChannel(Observer* observer) override {
        subscribers.erase(remove(subscribers.begin(), subscribers.end(), observer), subscribers.end());
    }

    void notifyAll(const string& videoTitle) override {
        for (auto subscriber : subscribers) {
            subscriber->update(videoTitle);
        }
    }

    void uploadVideo(const string& title) {
        cout << "Channel uploaded a new video: " << title << endl;
        notifyAll(title);
    }
};

class Subcribers : public Observer {
    private:
    string name;
    public:
    Subcribers(const string& name) : name(name) {}

    void update(const string& videoTitle) override {
        cout << "Hey " << name << "!" << " New video uploaded:" << videoTitle << endl;
    }
};

int main() {
    YouTubeChannel YashIsLive;

    Observer* dinu = new Subcribers("dinu");
    Observer* motu = new Subcribers("motu");

    YashIsLive.subscribeChannel(dinu);
    YashIsLive.subscribeChannel(motu);

    YashIsLive.uploadVideo("Yash Is Back!!");

    YashIsLive.unsubscribeChannel(motu);

    YashIsLive.uploadVideo("Yash Is Back!!");

    delete dinu;
    delete motu;
    
    return 0;
}