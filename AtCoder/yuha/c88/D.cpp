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

vector<int> G[10];
map<string,int> ids;
int N;
int M;
string S[10];
string C,D;

pair<int,string> ans(INF,"");
bool used[10][10];
void dfs(int v,string s,int cnt,bool ok) {
    //cout<<v<<", "<<S1<<", "<<s<<endl;
    if(ok&&v==ids[C]) {
        ans=min(ans,mp(cnt,s));
        return;
    }
    if(cnt>ans.fr) return;
    rep(i,G[v].size()) {
        int u=G[v][i];
        bool f=D==S[v];
        if(used[v][u]) continue;
        used[v][u]=1;
        used[u][v]=1;
        dfs(u,s+S[v],cnt+1,ok|f);
        used[v][u]=0;
        used[u][v]=0;
    }
}

int main() {
    cin>>N;
    rep(i,N) {
        cin>>S[i];
        ids[S[i]]=i;
    }
    cin>>M;
    rep(i,M) {
        string A,B;
        cin>>A>>B;
        G[ids[A]].pb(ids[B]);
        G[ids[B]].pb(ids[A]);
    }
    cin>>C>>D;
    dfs(ids[C],"",0,0);
    cout<<ans.sc<<endl;
    return 0;
}

