/*************************************************************************
	> File Name: test.cpp
	> Author: ly
	> Created Time: 2020年01月10日 星期五 19时33分09秒
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
using namespace std;
typedef long long ll;
#define MAX_N 1000000

int f1(int n) {
    return n * 2;
}

int f2(int n) {
    return n * n + 3;
}

int f3(int n) {
    return n >> 1;
}

int (*f[3])(int) = {
    f1, f2, f3
};

int main () {
    srand(time(0));
    int n;
    cin >> n;
    cout << f[rand() % 3](n) << endl;
    return 0;
}
