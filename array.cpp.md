==array.cpp==

```c
#include <stdio.h>

int func(int (*a)[200][300]) {
    printf("a = %p, a + 1 = %p\n", a, a + 1);
    return 0;
}


int main() {
    int arr[100][200][300];
    printf("arr = %p, &arr[0] = %p\n", arr, &arr[0]);
    printf("arr + 1 = %p, arr + 2 = %p\n", arr + 1, arr + 2);
    char *p = (char *)arr;
    printf("p + 1 = %p, p + 2 = %p\n", p + 1, p + 2);
    int n = 0;
    func(arr);
    printf("arr = %lu", sizeof(arr));
    return 0;
}
```

