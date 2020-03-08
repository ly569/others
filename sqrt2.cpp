/*************************************************************************
	> File Name: sqrt2.cpp
	> Author: ly
	> Created Time: 2020年01月07日 星期二 19时29分32秒
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
#define EPS 1e-7

double f(double x, double n) {
    return x * x - n;
}

double f_prime(double x) {
    return 2 * x;
}

double init(double n) {
    double x = 1.0;
    int cnt = 0;
    while (fabs(f(x, n)) > EPS) {
        x = x - f(x, n) / f_prime(x);
        cnt += 1;
    }
    printf("run %d steps\n", cnt);
    return x;
}

int main () {
    double x;
    scanf("%lf", &x);
    printf("%lf\n", init(x));
    return 0;
}
