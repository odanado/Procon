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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;
const ll INF=5e18;

ll cnv(char c) {
    if(isdigit(c)) return c-'0';
    else return c-'A'+10;
}

ll cnv(string S) {
    ll radix = 0;
    rep(i,S.size()) radix = max(cnv(S[i]),radix);
    radix++;
    ll ret=0;
    ll base = 1;
    rep(i,S.size()) {
        int j=S.size()-i-1;
        ret+=base*cnv(S[j]);
        base*=radix;
    }

    //cout<<S<<": "<<radix<<", "<<ret<<endl;
    return ret;
}

int main() {
    int N;
    cin>>N;
    ll ans=INF;
    rep(i,N) {
        string S; cin>>S;
        ans=min(ans,cnv(S));
    }
    cout<<ans<<endl;
    return 0;
}

