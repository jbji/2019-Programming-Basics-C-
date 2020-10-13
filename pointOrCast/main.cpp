#include <iostream>

using namespace std;
int main() {
    int a = 0;
    int & a1 = a;
    int * pa = &a;
    int b = a;
    //If we change the value of anyone above(a excluded), how would the value of a changes?
    a1=2;
    cout << "a=" << a << endl;
    cout << "a1=" << a1 << endl;
    cout << "pa=" << pa << endl;
    cout << "*pa=" << *pa << endl;
    cout << "b=" << b << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}