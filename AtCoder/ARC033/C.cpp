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

const int N = 200005;
ll bit[N];

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

int Q;

int main() {
    cin>>Q;
    rep(i,Q) {
        int t,x;
        cin>>t>>x;
        if(t==1) add(x,1);
        else {
            int l=0,r=N;
            while(r-l>1) {
                int mid = (l+r)/2;
                if(x <= sum(mid)) r=mid;
                else l=mid;
            }

            cout<<r<<endl;
            add(r,-1);
        }

    }
    return 0;
}

