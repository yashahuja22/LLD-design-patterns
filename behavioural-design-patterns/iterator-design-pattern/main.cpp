#include<iostream>
#include<string>
#include<vector>

using namespace std;

class PlayList {
    public:
    virtual void addSong(const string& songName) = 0;
    virtual vector<string>& getPlaylist() = 0;
    virtual ~PlayList() = default;
};

class BollyWoodPlaylist : public PlayList {
    private:
    vector<string> list;
    public:
    void addSong(const string& songName) override {
        list.push_back(songName);
    }

    vector<string>& getPlaylist() override {
        return list;
    }
};

class PartyPlaylist : public PlayList {
    private:
    vector<string> list;
    public:
    void addSong(const string& songName) override {
        list.push_back(songName);
    }

    vector<string>& getPlaylist() override {
        return list;
    }
};

class Iterator {
    public:
    virtual bool hasNext() = 0;
    virtual string next() = 0;
    virtual ~Iterator() = default;
};

class PlaylistIterator : public Iterator {
    private:
    PlayList* playlist;
    size_t index = 0;
    public:
    PlaylistIterator(PlayList* playlist) : playlist(playlist) {}

    bool hasNext() override {
        return index < playlist->getPlaylist().size();
    }

    string next() override {
        return playlist->getPlaylist()[index++];
    }
};

int main() {
    PlayList* bollywoodPlaylist = new BollyWoodPlaylist();
    bollywoodPlaylist->addSong("Aye khuda");
    bollywoodPlaylist->addSong("Aise na mujhe");

    Iterator* it = new PlaylistIterator(bollywoodPlaylist);
    cout << "Iterating Bollywood playlist:\n";
    while (it->hasNext()) {
        cout << it->next() << endl;
    }
    
    // Always delete a dynamically allocated object before reassigning its pointer. Otherwise, you lose access to that memory — and it stays allocated → memory leak.
    delete it;

    PlayList* partyPlaylist = new PartyPlaylist();
    partyPlaylist->addSong("Payal");
    partyPlaylist->addSong("Manohari");

    it = new PlaylistIterator(partyPlaylist);
    cout << "Iterating Party playlist:\n";
    while (it->hasNext()) {
        cout << it->next() << endl;
    }

    delete it;
    delete bollywoodPlaylist;
    delete partyPlaylist;

    return 0;
}