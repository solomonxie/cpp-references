/**
 * Observer Pattern
 * 
 * Lets you define a subscription mechanism to notify multiple objects about
 * any events that happen to the object they're observing.
 */
#include <iostream>
#include <list>
#include <string>

class IObserver {
public:
    virtual ~IObserver() {}
    virtual void update(const std::string& message) = 0;
};

class ISubject {
public:
    virtual ~ISubject() {}
    virtual void attach(IObserver* observer) = 0;
    virtual void detach(IObserver* observer) = 0;
    virtual void notify() = 0;
};

class Subject : public ISubject {
    std::list<IObserver*> observers;
    std::string message;
public:
    void attach(IObserver* observer) override { observers.push_back(observer); }
    void detach(IObserver* observer) override { observers.remove(observer); }
    void notify() override {
        for (auto observer : observers) observer->update(message);
    }
    void createMessage(std::string m = "Empty") {
        message = m;
        notify();
    }
};

class Observer : public IObserver {
    std::string name;
public:
    Observer(std::string n) : name(n) {}
    void update(const std::string& message) override {
        std::cout << "Observer " << name << " received: " << message << std::endl;
    }
};

int main() {
    Subject* subject = new Subject;
    Observer* ob1 = new Observer("1");
    Observer* ob2 = new Observer("2");

    subject->attach(ob1);
    subject->attach(ob2);

    subject->createMessage("Hello World!");
    subject->detach(ob1);
    subject->createMessage("New Message");

    delete ob1;
    delete ob2;
    delete subject;
    return 0;
}
