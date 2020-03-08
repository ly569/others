#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
	cout << "1";
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            i /= 2;
        } else if (i % 3 == 0) {
            i /= 3;
        } else if (i % 5 == 0) {
            i /=5;
        }
        cout << i <<endl;
    }
    return 0;
}