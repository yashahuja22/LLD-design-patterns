#include<iostream>
#include<string>
#include<vector>

using namespace std;

class FileSystem {
    public:
        virtual void showDetails() = 0;
        virtual ~FileSystem() = default;
};

class File : public FileSystem {
    private:
        string name;

    public:
        File(const string& n) : name(n) {}

        void showDetails() override {
            cout << "File: " << name << endl;
        }
};

class Folder : public FileSystem {
    private: 
        string name;
        vector<FileSystem*> items;
    
    public:
    Folder(const string& n) : name(n) {}

    void add(FileSystem* item) {
        items.push_back(item);
    }
 
    void showDetails() override {
        cout << "Folder: " << name << endl;
        for (auto item : items) {
            item->showDetails();
        }
    }

    ~Folder() {
        for (auto item : items) {
            delete item;
        }
    }
};

int main() {
    FileSystem* mainFile = new File("main.go");
    FileSystem* modFile = new File("go.mod");
    FileSystem* sumFile = new File("go.sum");

    Folder* syncFolder = new Folder("Sync");

    Folder* handlerFolder = new Folder("handler");
    FileSystem* handlerFile = new File("handlers.go");

    syncFolder->add(mainFile);
    syncFolder->add(modFile);
    syncFolder->add(sumFile);

    // syncFolder->showDetails();

    handlerFolder->add(handlerFile);

    syncFolder->add(handlerFolder);

    syncFolder->showDetails();

    delete syncFolder;
    return 0;
}