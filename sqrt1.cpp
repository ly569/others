/*************************************************************************
	> File Name: test.cpp
	> Author: ly
	> Created Time: 2020年01月07日 星期二 18时15分13秒
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

double init(double x) {
    double l = 0, r = (x <= 1.0 ? 1.0 : x);
//    for (int i = 0, i < 10000; i++){}
    while (r - l > EPS) {
        double mid = (l + r) / 2.0;
        if (mid * mid <= x) l = mid;
        else r = mid;
    }
    return l;
}

int main () {
    double x;
    scanf("%lf", &x);
    printf("%lf\n", init(x));
    return 0;
}
