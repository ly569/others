#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char str[100];
    while (~scanf("%d", &n)) {
        sprintf(str, "%x", n);
        printf("%s has %lu digits\n", str, strlen(str));
    }
    return 0;
}