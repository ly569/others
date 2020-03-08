#include <stdio.h>
#define DEBUG
#ifdef DEBUG 

#define log(frm, arg...) {\
    printf("[%s : %s : %d] ", __FILE__, __func__,__LINE__);\
    printf(frm, ##arg);\
    printf("\n");\
}
#else
#define log(frm,arg...)
#endif
#define contact(a, b) a##b
int main() {
    int a = 123;
    int abcdef = 13;
    contact(abc, def) = 23;
    log("%d",abcdef);
    log("hello world");
    log("%d\n", a);
    return 0;
}