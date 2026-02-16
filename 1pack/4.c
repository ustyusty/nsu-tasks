#include <stdio.h>
int evklid(int a, int b) {
    if (b == 0) {
        return a;
    }
    return evklid(b, a % b);
}
int main() {
    int a, b, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", evklid(a, b));
    }
    return 0;
}
