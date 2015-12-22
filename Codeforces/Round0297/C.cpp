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

int n;
int L[100005];
set<int> S;
set<int> S2;
ll func() {
    ll ans1=0;
    rep(i,n) {
        int x=L[i];
        int idx=lower_bound(L,L+n,x)-L;
        if(i!=idx&&x==L[idx]&&ans1<x) {
            S.clear();
            ans1=x;
            S.insert(i);
            S.insert(idx);
        }
        x--;
        idx=lower_bound(L,L+n,x)-L;
        if(i!=idx&&x==L[idx]&&ans1<x) {
            S.clear();
            ans1=x;
            S.insert(i);
            S.insert(idx);
        }
    }
    return ans1;
}
int main() {
    cin>>n;
    rep(i,n) cin>>L[i];
    sort(L,L+n);

    ll ans1=func();
    ll ans2=0;

    rep(i,n) {
        if(S.count(i)) continue;
        int x=L[i];
        int idx=lower_bound(L,L+n,x)-L;
        if(S.count(idx)) continue;
        if(i!=idx&&x==L[idx]&&ans2<x) {
            ans2=x;
        }

        x--;
        idx=lower_bound(L,L+n,x)-L;
        if(S.count(idx)) continue;
        if(i!=idx&&x==L[idx]&&ans2<x) {
            ans2=x;
        }

    }


    cout<<ans1*ans2<<endl;


    return 0;
}

