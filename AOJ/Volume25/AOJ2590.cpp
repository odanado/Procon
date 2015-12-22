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

typedef long long ll;
#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(long long i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

using namespace std;

ll N,M,Q;
ll ans[1003];
void plot() {
    rep(i,M) {
        ll count=0;
        ll val=0;
        rep(j,N) {
            if(((ans[i])>>j)&1LL) {
                count++;
                val=j;
            }
        }
        if(count==1) {
            if(val<10) printf("%d",val);
            else printf("%c",'A'+val-10);
        }
        else cout<<"?";
    }
    cout<<endl;
}

void update(ll& mask, string S, string B) {
    ll bit=0LL;
    rep(i,N) if(S[i]=='1') bit|=(1LL<<i);
    mask^=bit;
    // printf("%s : %X\n", S.c_str(),bit);
    rep(i,M) {
        if(B[i] == '1') {
            ans[i] &= mask;
        }
        else {
            ans[i] &= ~mask;
        }
    }
}


void solve() {
    
    rep(i,1003) ans[i]=(1LL<<N)-1LL;
    ll mask=0LL;
    string S,B;
    rep(i,Q) {
        cin>>S>>B;
        update(mask, S,B);

        // rep(i,M) cout<<ans[i]<<",";
        // cout<<endl;
    }
    plot();
}

int main() {
    while(cin>>N>>M>>Q) {
        if(N+M+Q==0) break;
        solve();
    }

    return 0;
}

