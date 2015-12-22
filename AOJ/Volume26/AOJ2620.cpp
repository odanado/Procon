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
int W,H,N;
P s,t;
int steps[1003][1003];
int dp[1003][1003];

int cnv(char c) {
    if(c=='R') return 0;
    if(c=='D') return 1;
    if(c=='L') return 2;
    return 3;
}

void normalize(int &a,int s,int t) {
    a=max(s,a);
    a=min(t,a);
}

P walk(P pos,string s) {
    rep(i,s.size()) {
        int k=cnv(s[i]);
        int ny=pos.fr+dy[k];
        int nx=pos.sc+dx[k];
        
        if(!(0<=ny&&ny<H)) continue;
        if(!(0<=nx&&nx<W)) continue;
        //printf("[move] %c %d %d\n",s[i],ny,nx);

        //printf("[++] %c %d %d\n",s[i],pos.fr*2+dy[k]+1,pos.sc*2+dx[k]+1);
        steps[pos.fr*2+dy[k]+1][pos.sc*2+dx[k]+1]++;
        pos=P(ny,nx);
    }
    return pos;
}

int main() {
    cin>>W>>H>>N;
    cin>>s.fr>>s.sc;
    cin>>t.fr>>t.sc;

    swap(t.fr,t.sc);
    swap(s.fr,s.sc);
    rep(i,N) {
        P pos;
        int t;
        string s;
        cin>>pos.fr>>pos.sc;
        swap(pos.fr,pos.sc);
        cin>>t;
        cin>>s;
        rep(j,t) pos=walk(pos,s);

    }
    rep(i,1003) rep(j,1003) dp[i][j]=INF;

    s.fr*=2; s.sc*=2;
    t.fr*=2; t.sc*=2;
    typedef pair<int,P> Pi;
    priority_queue<Pi,vector<Pi>,greater<Pi> > que;
    que.push(Pi(0,s));
    dp[s.fr][s.sc]=0;
    while(que.size()) {
        Pi pi=que.top(); que.pop();
        P p=pi.sc;
        rep(k,4) {
            int ny=p.fr+dy[k];
            int nx=p.sc+dx[k];
            int ny2=ny+dy[k];
            int nx2=nx+dx[k];
            if(!(0<=ny2&&ny2<2*H+1)) continue;
            if(!(0<=nx2&&nx2<2*W+1)) continue;

            if(dp[ny2][nx2]>dp[p.fr][p.sc]+steps[ny][nx]) {
                dp[ny2][nx2]=dp[p.fr][p.sc]+steps[ny][nx];
                que.push(Pi(dp[ny2][nx2],P(ny2,nx2)));
            }
        }
    }

    /*
    rep(y,2*H+1) {
        rep(x,2*W+1) cout<<steps[y][x]<<" ";
        cout<<endl;
    }

    rep(y,2*H+1) {
        rep(x,2*W+1) printf("%10d ",dp[y][x]);
        cout<<endl;
    }
    //*/
    cout<<dp[t.fr][t.sc]<<endl;

    return 0;
}

