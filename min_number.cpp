#include <iostream>
using namespace std;

#define max_n 10000

int prime[max_n + 5] = {0};

void init_prime() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= max_n; j += i) {
            if(prime[j]) continue;
            prime[j] = 1;
        }
    }
    return ;
}

int main() {
    init_prime();
    int n;
    cin >> n;
    cout << prime[n];
    return 0;
}