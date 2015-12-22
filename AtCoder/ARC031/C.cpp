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

int N;
map<int,int> B;
ll bit[100005];

ll sum(int i) {
    ll s = 0;
    while(i>0) {
        s+=bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x) {
    while(i <= N) {
        bit[i] += x;
        i += i & -i;
    }
}

int main() {
    cin>>N;
    rep(i,N) add(i+1,1);
    rep(i,N) {
        int a;
        cin>>a;
        B[a]=i+1;
    }
    ll ans = 0;
    for(auto& e : B) {
        add(e.sc,-1);
        // printf("[debug] %d : %d,%d\n", e.sc, sum(e.sc), sum(N)-sum(e.sc));
        ans += min(sum(e.sc),sum(N)-sum(e.sc));
    }
    cout<<ans<<endl;
    return 0;
}

