#include <iostream>
using namespace std;

int add(int a, int b, int c=0);
float add(float a, float b, float c=0);


void process_n(int &n) {
    n *= 2;
}


void process_array(int nlist[]) {
    // Array is passed as an reference
    nlist[0] *= 3;
}


int main() {
    int res = add(4, 5);
    cout << res << "\n";
    cout << add(4, 5, 2) << "\n";
    float a = 4.1, b = 5.2;
    cout << add(a, b) << "\n";
    // cout << add(4.1, 5.2) << "\n"; -> Error

    // Pass reference to func
    int n = 3;
    process_n(n);
    cout << "n(after): " << n << "\n";

    // Pass array as reference
    int nlist[] = {3, 4, 5};
    process_array(nlist);
    cout << "nlist(after): " << nlist[0] << "\n";

    return 0;
}


int add(int a, int b, int c) {
    int res = a + b + c;
    return res;
}


float add(float a, float b, float c) {
    float res = a + b + c;
    return res;
}
