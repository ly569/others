/*************************************************************************
	> File Name: test2.cpp
	> Author: ly
	> Created Time: 2020年01月07日 星期二 18时55分31秒
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
#include <ctime>
using namespace std;
typedef long long ll;
#define MAX_N 1000000
//蒙特卡罗法
int main () {
    srand(time(0));
    int n = 0, m = 0;
    for (int i = 0; i < MAX_N; i++) {
        double x = rand() * 1.0 / RAND_MAX * (rand() % 2 ? 1 : -1);
        double y = rand() * 1.0 / RAND_MAX * (rand() % 2 ? 1 : -1);
        if (x * x + y * y <= 1.0) m += 1;
        n += 1;
    }
    printf("%lf\n", m * 1.0 / n * 4.0);
    return 0;
}
