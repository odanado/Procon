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

int N,M;
vector<int> G[20];
vector<int> S;
struct State {
    int v;
    int s;
    int cnt;
    State(int v=0,int s=0,int cnt=0):
        v(v),s(s),cnt(cnt){}
};
ll f(int v,int cnt) {
    cout<<"f: "<<v<<", "<<cnt<<endl;
    ll ret=0;
    queue<State> que;
    que.push(State(v,1<<v,cnt));
    while(que.size()) {
        State s=que.front(); que.pop();
        printf("[debug]: %d %d %d\n",s.v,s.s,s.cnt);
        if(s.s+1==(1<<N)) {
            ret++;
        }
        for(auto u : G[s.v]) {
            int t=S[s.cnt];
            if((t>>u&1)) continue;
            if(s.s>>u&1) continue;
            que.push(State(u,s.s|1<<u,s.cnt^1));
        }
    }
    cout<<"ret: "<<ret<<endl;
    return ret;
}
ll dfs(int v,int cnt,int s) {
    if(1<<N==s+1) return 1;
    ll ret=0;
    for(auto u:G[v]) {
        if(S[cnt]>>u&1) continue;
        if(s>>u&1) continue;
        ret+=dfs(u,cnt^1,s|1<<u);
    }

    return ret;
}
int main() {
    cin>>N>>M;
    rep(i,M) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        G[x].pb(y);
        G[y].pb(x);
    }
    ll ans=0;
    rep(S1,1<<N) {
        int S2=((1<<N)-1)^S1;
        if(S1==0||S2==0) continue;
        S.clear();
        S.pb(S1);
        S.pb(S2);
        ll cnt=0;
        rep(i,N) {
            cnt=max(cnt,dfs(i,S2>>i&1,1<<i));
        }
        if(cnt>0) {
            //rep(i,N) if(S1>>i&1) cout<<i<<" ";
            //cout<<endl;
            //rep(i,N) if(S2>>i&1) cout<<i<<" ";
            //cout<<endl;
            //cout<<cnt<<endl;
            //cout<<endl;
        }

        ans+=cnt;
        /*
        rep(i,N) {
            cnt+=f(i,!(S1>>i&1));
            //cout<<"m: "<<i<<", "<<cnt<<endl;
            //if(cnt==1) return 0;
        }
        ans+=cnt;
        */
    }
    cout<<ans/2<<endl;
    return 0;
}

