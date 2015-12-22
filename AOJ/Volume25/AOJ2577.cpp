#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<cstdio>

using namespace std;

const int INF=100000;
#define rep(i,n) for(int i=0;i<(n);i++)

char map[100][100];
int r[11];
int h,w,d,n;

bool flag[100][100];
int dist[100][100];

// 図面のマスク
void f(int x,int y,int k) {
    int sup;
    int inf;

    int temp[100][100]={};

    if(k==0) {
        sup=r[0];
        inf=-1;
    }
    else if(k==d) {
        sup=100000;
        inf=r[d-1];
    }
    else {
        sup=r[k];
        inf=r[k-1];
    }

    rep(i,h) rep(j,w) {
        int dx = abs(x-i);
        int dy = abs(y-j);

        if(dy<=sup && dx<=sup) {
            temp[i][j]=1;

        }
    }
    rep(i,h) rep(j,w) {
        int dx = abs(x-i);
        int dy = abs(y-j);

        if((inf>=dx && inf>=dy)) temp[i][j]=0;
    }

    rep(i,h) {
        rep(j,w) {
            flag[i][j]&=temp[i][j];
        }
    }
}

//たどり着けるか
void f2() {
    int sx,sy;

    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    rep(i,100) rep(j,100) dist[i][j]=INF;
    rep(i,h) rep(j,w) {
        if(map[i][j]=='D') {
            sx=i;
            sy=j;
        }
    }
    dist[sx][sy]=0;

    queue<pair<int,int> > que;
    que.push(make_pair(sx,sy));

    while(que.size()) {
        pair<int,int> p = que.front(); que.pop();
        rep(i,4) {
            int nx=dx[i]+p.first;
            int ny=dy[i]+p.second;
            if(0<=nx&&nx<h&&0<=ny&&ny<w && map[nx][ny]!='#' && dist[nx][ny]==INF) {
                dist[nx][ny] = dist[p.first][p.second] + 1;
                que.push(make_pair(nx,ny));
            }
        }
    }


}

int main() {
    cin>>h>>w>>d>>n;
    rep(i,100) rep(j,100) map[i][j]='#';
    rep(i,h) cin>>map[i];
    rep(i,d) cin>>r[i];

    rep(i,h) rep(j,w) if(map[i][j]!='#') flag[i][j]=1;
    rep(i,n) {
        int x,y,k;
        cin>>x>>y>>k;
        swap(x,y);
        f(x,y,k);
    }
    int cnt=0;
    rep(i,h) {
        rep(j,w) {
            if(flag[i][j]) cnt++;
            //cout<<flag[i][j]<<" ";
        }
        //cout<<endl;
    }

    f2();
    bool a,b;
    a=b=false;
    rep(i,h) rep(j,w) {
        if(dist[i][j]!=INF && flag[i][j]) a=true;
        if(dist[i][j]==INF && flag[i][j]) b=true;
    }
    if(a&&b) cout<<"Unknown"<<endl;
    if(a&&!b) cout<<"Yes"<<endl;
    if(!a&&b) cout<<"No"<<endl;
    if(!a&&!b) cout<<"Broken"<<endl;



    return 0;
}
