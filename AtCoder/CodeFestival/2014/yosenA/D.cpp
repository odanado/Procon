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

string A;
int N;
ll B;
bool used[20];
ll ans = INF;
ll ans_t;

bool ok(ll n) {
    bool f[20]={};
    int cnt=0;
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    rep(i,s.size()) f[s[i]-'0']=true;
    rep(i,10) if(f[i]) cnt++;
    return cnt<=B;
}
void dfs(ll pos,ll cnt,ll m) {
    //cout<<pos<<","<<cnt<<","<<m<<endl;
    if(pos==A.size()) {
        if((N-m)>=0&&ok(m)) {
            //cout<<pos<<","<<cnt<<","<<m<<endl;
            ans = min(ans,abs(N-m));
            ans_t = m;
        }
        return;
    }
    ll r = A.size()-pos-1;
    rep(i,10) {
        if(cnt!=B) {
            if(!used[i]) {
                used[i]=true;
                dfs(pos+1,cnt+1,m+i*pow(10,r));
                used[i]=false;
            }
            else {
                dfs(pos+1,cnt,m+i*pow(10,r));
            }
        }
        else {
            rep(j,10) 
                if(used[j])
                    dfs(pos+1,cnt,m+j*pow(10,r));
        }
    }

}
ll cnv(string s) {
    stringstream ss;
    ll ret=0;
    ss<<s;
    ss>>ret;
    return ret;
}
int main() {
    cin>>A>>B;
    if(A.size()>6) return 0;
    N = cnv(A);
    //cout<<N<<endl;
    dfs(0,0,0);
    cout<<ans<<endl;
//cout<<abs(ans_t)<<endl;
    return 0;
}

