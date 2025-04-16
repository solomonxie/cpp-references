#include <iostream>
using namespace std;


struct Person {
    string name;
    int age;
    bool gender;
};


int main() {
    Person me;
    me.name = "Jason";
    me.age = 18;
    me.gender = 1;
    cout << me.name << "\n";
    cout << me.age << "\n";
    cout << me.gender << "\n";
    return 0;
}
