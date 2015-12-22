#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;

const int INF = 100000008;
int w,h;
int dist[102][102];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void solve() {
    vector<string> vec(2*h-1);
    rep(i,102) rep(j,102) dist[i][j]=INF;

    getchar();
    rep(i,2*h-1) {
        string ss;
        getline(cin,ss);
        vec[i] = ss;
    }

    queue<P> que;
    que.push(P(0,0));
    dist[0][0] = 0;

    while(que.size()) {
        P p = que.front(); que.pop();
        int x = p.first;
        int y = p.second;
        //cout<<"s : "<<x<<","<<y<<endl;
        rep(i,4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //if(0<=nx && 0<=ny ) cout<<nx<<","<<ny<<" : "<<vec[nx][ny]<<endl;
            if(0<=nx&&nx<2*h-1 && 0<=ny&&ny<vec[nx].size() && 
                    vec[nx][ny]=='0' && dist[nx+dx[i]][ny+dy[i]] == INF) {
                //cout<<nx<<","<<ny<<" : "<<vec[nx][ny]<<endl;
                dist[nx+dx[i]][ny+dy[i]] = dist[x][y] + 1;
                que.push(P(nx+dx[i],ny+dy[i]));
            }
        }

    }
    int ans = dist[2*(h-1)][2*(w-1)];
    ans = ans == INF? 0 : ans + 1;
    cout<<ans<<endl;
    /*
    rep(i,2*h) {
        rep(j,2*w) {
            cout<<dist[i][j++]<<" ";
        }
        i++;
        cout<<endl;
    }
    */



}

int main() {
    while(cin>>w>>h) {
        if(w+h==0) return 0;
        solve();
    }

    return 0;
}
