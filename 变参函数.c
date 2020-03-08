#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int max_int(int n, ...) {
    va_list arg;
    va_start(arg, n);
    int ans = INT32_MIN;
    while (n--) {
        int temp = va_arg(arg, int);
        temp > ans && (ans = temp);
    }
    va_end(arg);
    return ans;
}

int main() {
    printf("%d\n",max_int(3, 3, 5, 16));
    printf("%d\n",max_int(3, 3, 5, 16, 21));
    printf("%d\n",max_int(3, 3, 5, 16, -32));
    return 0;
}