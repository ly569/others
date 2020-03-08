#include <stdio.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}
int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    }
    return 0;
}
/* ax+by=gcd(a,b)
当a=b=0，x、y可取任意值
当a!=0，b=0，gcd(a,b)=a，此时可令x=1、y=1
当ab!=0，设:
ax1+by1=gcd(a,b)
bx2+(a % b)y2=gcd(b,a % b)
根据：
gcd(a,b)=gcd(b,a % b)
可得：
ax1+by1=bx2+(a % b)y2
⇒ax1+by1=bx2+(a−⌊a/b⌋∗b)y2
⇒ax1+by1=ay2+bx2−⌊a/b⌋∗by2
⇒ax1+by1=ay2+b(x2−⌊a/b⌋∗y2)
根据恒等定理可得
x1=y2, y1=x2−⌊a/b⌋∗y2
这样就可以把x1、y1用x2、y2来表示，进行递归计算，而递归结束的条件就是b=0 */