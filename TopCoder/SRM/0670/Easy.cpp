#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>
#include <numeric>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

class Cdgame {
    int rescount(vector <int> a, vector <int> b) {
        set<ll> S;
        rep(i,a.size()) rep(j,b.size()) {
            swap(a[i],b[i]);
            ll s1=std::accumulate(all(a),0);
            ll s2=std::accumulate(all(b),0);
            printf("%d %d\n",s1,s2);
            S.insert(s1*s2);
        }

        return S.size();
    }
};

int main() {
    return 0;
}

