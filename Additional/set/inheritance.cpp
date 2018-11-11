#include <iostream>
#include <vector>
using namespace std;

class Animal {
public: 
    virtual void Say() = 0;
};

class Tail {
    void Move() {};
};

// Dog *is* Animal
class Dog : public Animal {
public:
    void Say() { cout << "Woof" << endl; }
    void Run() { tail.Move(); cout << "->->->" << endl; }

private:
    // Dog *has* Tail
    Tail tail;
};

class Cat : public Animal {
public:
    void Say() { cout << "Meow" << endl; }
};

int main() { 
    Dog dog;
    Cat cat;
    vector<Animal*> animals(2);
    animals[0] = &dog;
    animals[1] = &cat;
    for (size_t i = 0; i < animals.size(); i++) {
        animals[i]->Say();
    }
    return 0;
}
