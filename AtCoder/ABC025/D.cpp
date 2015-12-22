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

int x[5][5];
bool ok(int i,int j,int a) {
    vector<int> vec1,vec2;
    vec1.pb(a);
    vec2.pb(a);
    if(i!=0) vec1.pb(x[i-1][j]);
    if(i!=4) vec1.pb(x[i+1][j]);
    if(j!=0) vec2.pb(x[i][j-1]);
    if(j!=4) vec2.pb(x[i][j+1]);
    sort(all(vec1));
    sort(all(vec2));

    if(is_sorted(all(vec1))) return false;
    if(is_sorted(all(vec2))) return false;

    reverse(all(vec1));
    reverse(all(vec2));
    if(is_sorted(all(vec1))) return false;
    if(is_sorted(all(vec2))) return false;

    return true;
}
bool ok() {
    rep(i,5) rep(j,5) {
        if(1<=i&&i<=3) {
            if(x[i-1][j]<x[i][j]&&x[i][j]<x[i+1][j]) return false;
            if(x[i-1][j]>x[i][j]&&x[i][j]>x[i+1][j]) return false;
        }
        if(1<=j&&j<=3) {
            if(x[i][j-1]<x[i][j]&&x[i][j]<x[i][j+1]) return false;
            if(x[i][j-1]>x[i][j]&&x[i][j]>x[i][j+1]) return false;
        }
    }

    return true;
}
const int MOD=1000000007;

void decode(int S) {
    rep(i,26)if(i) cout<<(S>>i&1?"1":"0");
    cout<<endl;
}
// 場所と値
int dfs(int i,int j,bool used[]) {
    if(i==5) {
        if(ok()) {
            /*
            rep(i,5) {
                rep(j,5) cout<<x[i][j]<<" ";
                cout<<endl;
            }
            cout<<endl;
            //*/
            return 1;
        }
        return 0;
    }
    if(j==5) {
        return dfs(i+1,0,used);
    }
    if(x[i][j]!=0) return dfs(i,j+1,used);
    int ret=0;
    rep(k,26) {
        if(k==0) continue;
        if(used[k]) continue;
        int t=x[i][j];
        x[i][j]=k;
        used[k]=true;
        ret+=dfs(i,j+1,used)%MOD;
        ret%=MOD;
        used[k]=false;
        x[i][j]=t;
    }

    return ret%MOD;
}

int main() {
    rep(i,5) rep(j,5) cin>>x[i][j];
    bool used[26]={};
    int cnt=0;
    rep(i,5) rep(j,5) {
        if(x[i][j]!=0) {
            cnt++;
            used[x[i][j]]=true;
        }
    }
    ll ans=dfs(0,0,used);
    cout<<ans<<endl;
    return 0;
}

