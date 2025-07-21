#include<iostream>
#include<unordered_map>

using namespace std;

class Character {
    private:
        char symbol;

    public:
    Character(char c) : symbol(c) {}

    void display(int x, int y) {
        cout << "Displaying '" << symbol << "' at (" << x << ", " << y << ")" << endl;
    }
};


class CharacterFactory {
    private:
    unordered_map<char, Character*> map;
    
    public:
    Character* getCharacter(char c) {
        if (map.find(c) == map.end()) {
            cout << c << " new object created" << endl; 
            map[c] = new Character(c);
        }
        return map[c];
    }

    ~CharacterFactory() {
        cout << "destructor called";
        for (auto& item : map) {
            delete item.second;
        }
    }
};
int main() {
    CharacterFactory factory;
    string str = "HELLO";
    int x = 0;

    for (auto i : str) {
        Character* c = factory.getCharacter(i);
        c->display(x, 1);
        x++;
    }

    return 0;
}