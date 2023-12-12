#include <iostream>
using namespace std;

int main() {
    // Numbers:
    int a = 5;
    int b = 6;
    int result = a * b;
    cout << result << "\n";
    b++;
    a--;
    cout << a*b << "\n";
    cout << a-b << "\n";
    cout << a+b << "\n";
    float c = 4.22;
    float mix = a+b+c;
    cout << mix << "\n";

    // String:
    string s = "A whole new string";
    s = "A changed string.";
    cout << s << "\n";

    // Char
    char ch = 'x';
    char ch2 = 65;
    //char ch2 = "bcdef"; -> Error
    cout << ch << "\n";
    cout << ch2 << "\n";

    // Constant:
    const string s2 = "A constant";
    const string s3 = " of string";
    cout << s2 + s3 << "\n";
    //s2 = "hihi"; -> Error

    // Boolean:
    bool b1 = true;
    bool b2 = false;
    cout << b1 + b2 << "\n";
    return 0;
}
