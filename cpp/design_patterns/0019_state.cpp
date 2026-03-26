/**
 * State Pattern
 * 
 * Lets an object alter its behavior when its internal state changes.
 * It appears as if the object changed its class.
 */
#include <iostream>
#include <string>
#include <typeinfo>

class Context;

class State {
protected:
    Context* context;
public:
    virtual ~State() {}
    void setContext(Context* c) { context = c; }
    virtual void handle1() = 0;
    virtual void handle2() = 0;
};

class Context {
    State* state;
public:
    Context(State* s) : state(nullptr) { transitionTo(s); }
    ~Context() { delete state; }
    void transitionTo(State* s) {
        if (state != nullptr) delete state;
        state = s;
        state->setContext(this);
    }
    void request1() { state->handle1(); }
    void request2() { state->handle2(); }
};

class ConcreteStateA : public State {
public:
    void handle1() override;
    void handle2() override { std::cout << "StateA handles request2." << std::endl; }
};

class ConcreteStateB : public State {
public:
    void handle1() override { std::cout << "StateB handles request1." << std::endl; }
    void handle2() override;
};

void ConcreteStateA::handle1() {
    std::cout << "StateA handles request1, transitioning to StateB." << std::endl;
    context->transitionTo(new ConcreteStateB);
}

void ConcreteStateB::handle2() {
    std::cout << "StateB handles request2, transitioning to StateA." << std::endl;
    context->transitionTo(new ConcreteStateA);
}

int main() {
    Context* context = new Context(new ConcreteStateA);
    context->request1();
    context->request2();
    delete context;
    return 0;
}
