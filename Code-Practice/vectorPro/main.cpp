#include<iostream>
#include"learn-test.h"

int main(void) {
    using namespace std;
    const int N = 10;
    // cout << &N <<endl;
    // test();
    int a= 10;
    int* b  =&a;
    int*& c = b;
    cout << *c << endl;
}
