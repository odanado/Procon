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

ll n,m;
ll a[1000006];

bool visited[1003][1003][1];
bool dp[1003][1003][1];

bool dfs(int pos,int sum,bool f) {
    if(pos==n) {
        if(f&&sum%m==0) return true;
        else return false;
    }
    if(visited[pos][sum][f]) return dp[pos][sum][f];
    bool ret=false;
    ret|=dfs(pos+1,sum,f);
    ret|=dfs(pos+1,(sum+a[pos])%m,true);

    visited[pos][sum][f]=true;
    return dp[pos][sum][f]=ret;
}

int main() {
    cin>>n>>m;
    rep(i,n) cin>>a[i];
    rep(i,n) a[i]=a[i]%m;
    sort(a,a+n);
    if(n<m) {
        if(dfs(0,0,0)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return 0;
    }
    bool f=false;
    int cnt[1003]={};
    rep(i,n) f|=a[i]==0;
    rep(i,n) cnt[a[i]]++;
    rep(i,m) f|=cnt[i]==m;
    if(f) {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}

