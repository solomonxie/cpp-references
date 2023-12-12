#include <iostream>
using namespace std;

int main() {
    string names[] = {"Jason", "James", "TomTomTomTomTomTomTomTomTomTomTom"};
    cout << sizeof(names) << "\n";
    cout << sizeof(string) << "\n";
    for (int i=0; i <= sizeof(names)/sizeof(string); i++) {
        cout << names[i] << "\n";
    }
    return 0;
}
