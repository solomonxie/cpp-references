/**
 * Memento Pattern
 * 
 * Lets you save and restore the previous state of an object without revealing
 * the details of its implementation.
 */
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Memento {
    std::string state;
    std::string date;
public:
    Memento(std::string s) : state(s) {
        std::time_t now = std::time(0);
        this->date = std::ctime(&now);
    }
    std::string getState() const { return state; }
    std::string getName() const { return date + " / (" + state.substr(0, 9) + "...)"; }
};

class Originator {
    std::string state;
public:
    Originator(std::string s) : state(s) { std::cout << "Originator: Initial state: " << state << std::endl; }
    void doSomething() {
        state = "State_" + std::to_string(rand() % 1000);
        std::cout << "Originator: State changed to: " << state << std::endl;
    }
    Memento* save() { return new Memento(state); }
    void restore(Memento* memento) {
        state = memento->getState();
        std::cout << "Originator: State restored to: " << state << std::endl;
    }
};

class Caretaker {
    std::vector<Memento*> mementos;
    Originator* originator;
public:
    Caretaker(Originator* o) : originator(o) {}
    void backup() { mementos.push_back(originator->save()); }
    void undo() {
        if (mementos.empty()) return;
        Memento* memento = mementos.back();
        mementos.pop_back();
        originator->restore(memento);
        delete memento;
    }
};

int main() {
    Originator* originator = new Originator("Super-duper-super-puper-mega");
    Caretaker* caretaker = new Caretaker(originator);

    caretaker->backup();
    originator->doSomething();

    caretaker->backup();
    originator->doSomething();

    caretaker->undo();
    caretaker->undo();

    delete originator;
    delete caretaker;
    return 0;
}
