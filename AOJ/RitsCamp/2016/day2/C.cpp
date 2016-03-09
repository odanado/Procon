#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
vector<int> G[1003];
int N,M;
bool visited[1003];

void dfs(int v,int &cnt) {
    if(visited[v]) return;

    cnt++;
    visited[v]=true;
    for(auto u:G[v]) {
        if(visited[u]) continue;
        dfs(u,cnt);
    }

}

int main() {
    cin>>N>>M;
    rep(i,M) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans=0;
    rep(i,N) {
        if(visited[i]) continue;
        int cnt=0;
        dfs(i,cnt);
        if(cnt==1) ans++;
        else ans--;
    }
    cout<<abs(ans)<<endl;
    return 0;
}
