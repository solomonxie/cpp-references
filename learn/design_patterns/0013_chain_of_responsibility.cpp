/**
 * Chain of Responsibility Pattern
 * 
 * Lets you pass requests along a chain of handlers. Upon receiving a request,
 * each handler decides either to process the request or to pass it to the
 * next handler in the chain.
 */
#include <iostream>
#include <string>
#include <vector>

class Handler {
public:
    virtual ~Handler() {}
    virtual Handler* setNext(Handler* handler) = 0;
    virtual std::string handle(std::string request) = 0;
};

class AbstractHandler : public Handler {
private:
    Handler* nextHandler;
public:
    AbstractHandler() : nextHandler(nullptr) {}
    Handler* setNext(Handler* handler) override {
        this->nextHandler = handler;
        return handler;
    }
    std::string handle(std::string request) override {
        if (this->nextHandler) {
            return this->nextHandler->handle(request);
        }
        return "";
    }
};

class MonkeyHandler : public AbstractHandler {
public:
    std::string handle(std::string request) override {
        if (request == "Banana") {
            return "Monkey: I'll eat the " + request + ".\n";
        } else {
            return AbstractHandler::handle(request);
        }
    }
};

class SquirrelHandler : public AbstractHandler {
public:
    std::string handle(std::string request) override {
        if (request == "Nut") {
            return "Squirrel: I'll eat the " + request + ".\n";
        } else {
            return AbstractHandler::handle(request);
        }
    }
};

int main() {
    MonkeyHandler* monkey = new MonkeyHandler;
    SquirrelHandler* squirrel = new SquirrelHandler;

    monkey->setNext(squirrel);

    std::vector<std::string> food = {"Nut", "Banana", "Cup of coffee"};
    for (const std::string& f : food) {
        std::cout << "Client: Who wants a " << f << "?" << std::endl;
        const std::string result = monkey->handle(f);
        if (!result.empty()) {
            std::cout << "  " << result;
        } else {
            std::cout << "  " << f << " was left untouched." << std::endl;
        }
    }

    delete monkey;
    delete squirrel;
    return 0;
}
