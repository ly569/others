#include <iostream>
using namespace std;

//#define offset(T, item)(long long)(&(((T *)(NULL)) -> item))

#define offset(T, item) ({\
    T temp;\
    (char *)&(temp.item) - (char *)&temp;\
})

struct Data {
    char a;
    short b;
    char c;
    double d;
};

int main() {
    cout << offset(struct Data, a) << endl;
    cout << offset(struct Data, b) << endl;
    cout << offset(struct Data, c) << endl;
    cout << offset(struct Data, d) << endl;
    return 0;
}