#include <stdio.h>
#define swap(a,b) {long long int tmp = a; a = b; b = tmp;}
typedef struct {
    long long a, b;
} Frac;
long long int gcd(long long int a, long long int b){
    if(a<0LL)a*=-1LL;
    if(b<0LL)b*=-1LL;
    if(a < b)swap(a, b);
    if(a%b == 0LL)return b;
    else return gcd(b, a%b);
}
Frac normal(long long a, long long b) {
    if(a == 0)return (Frac){0, 1};
    long long int tmp = gcd(a,b);
    return (Frac){a/tmp, b/tmp};
}
Frac add(Frac x, Frac y) {
    x = normal(x.a, x.b);
    y = normal(y.a, y.b);
    Frac z = {x.a*y.b + x.b*y.a, x.b*y.b};
    z = normal(z.a, z.b);
    return z;
}
Frac subtract(Frac x, Frac y) {
    x = normal(x.a, x.b);
    y = normal(y.a, y.b);
    Frac z = {x.a*y.b - x.b*y.a, x.b*y.b};
    z = normal(z.a, z.b);
    return z;
}
Frac multipy(Frac x, Frac y) {
    x = normal(x.a, x.b);
    y = normal(y.a, y.b);
    Frac z = {x.a*y.a, x.b*y.b};
    z = normal(z.a, z.b);
    return z;
}
Frac divide(Frac x, Frac y) {
    x = normal(x.a, x.b);
    y = normal(y.a, y.b);
    Frac z = {x.a*y.b, x.b*y.a};
    z = normal(z.a, z.b);
    return z;
}
int main() {
    int cmd, x, y, z, w;
    Frac a, b, c;
    scanf("%d", &cmd);
    scanf("%d %d %d %d", &x, &y, &z, &w);
    a = normal(x, y), b = normal(z, w);
    if (cmd == 1) {
        c = add(a, b);
    } else if (cmd == 2) {
        c = subtract(a, b);
    } else if (cmd == 3) {
        c = multipy(a, b);
    } else if (cmd == 4) {
        c = divide(a, b);
    }
    printf("%lld / %lld\n", c.a, c.b);
    return 0;
}