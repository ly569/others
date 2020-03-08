==binary_search.cpp==

```c
#include <stdio.h>

int binary_search(int *arr, int head, int tail, int x) {
    if (head > tail) return -1;
    int mid = (head + tail) >> 1;
    if (arr[mid] == x) return mid;
    else if (arr[mid] < x) head = mid + 1;
    else tail = mid - 1;
    return binary_search(arr, head, tail, x);
}

//0000000000011111111111111 找第一个"1"
int binary_search1(int *arr, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] >= x) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}
// 11111111111111000000000000 找最后一个'1'

int binary_search2(int *arr, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (arr[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

int main() {
    int arr[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int x;
    //scanf("%d", &x);
    printf("%d\n", binary_search2(arr, n));
    return 0;
}
```

