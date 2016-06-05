#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int f(int y, int m, int d) {
    if (m <= 2) y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + 153 * (m + 1) / 5 + d - 428;
}
int main() {
    int y1, m1, d1;
    int y2, m2, d2;
    while(1) {
        cin >> y1 >> m1 >> d1;
        cin >> y2 >> m2 >> d2;
        if(y1==-1) break;
        cout << f(y2, m2, d2) - f(y1, m1, d1) << endl;
    }
}
