#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    int N;
    ll a, b;
    cin >> N;
    while (N--) {
        cin >> a >> b;
        double t = b * log10(a);
        ll radix = (ll)t;
        ll ans = 10 * pow(10, t - radix);
        printf("%lld %lld %lld\n", ans / 10, ans % 10, radix);
    }
}
