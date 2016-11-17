#include <iostream>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int A[6];
int main() {
    rep(i, 6) cin >> A[i];
    sort(A, A + 4);
    sort(A + 4, A + 6);
    int ans = 0;
    rep(i, 3) ans += A[i + 1];
    ans += A[5];
    cout << ans << endl;
    return 0;
}
