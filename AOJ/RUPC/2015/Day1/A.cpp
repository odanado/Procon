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

int n;


struct Player {
    int f;
    int a;
    int x,y;
    int t;
};
int dist(Player p1,Player p2) {
    return ((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
vector<Player> player;
int main() {
    cin>>n;
    rep(i,n) {
        int f,a,t,x,y;
        cin>>f>>a>>t>>x>>y;
        Player p;
        p.f=f;
        p.a=a;
        p.x=x;
        p.y=y;
        p.t=t;
        player.pb(p);

    }
    int ans1[2];
    double ans2[2];
    ans1[0]=ans1[1]=-1;
    ans2[0]=ans2[1]=-1;
    rep(i,player.size()) {
        int j=i+1;
        if(j==player.size()) break;
        if(player[i].a==player[j].a) continue;
        if(player[i].t!=player[j].t) continue;

        int t=player[i].t;
        int d=dist(player[i],player[j]);
        if(ans1[t]<d) {
            ans1[t]=d;
            ans2[t]=abs(player[i].f-player[j].f);
        }
        if(ans1[t]==d) {
            ans2[t]=min(ans2[t],1.0*abs(player[i].f-player[j].f));

        }
    }
    rep(t,2) {
        double tmp=ans1[t];
        if(tmp!=-1) tmp=sqrt(1.0*tmp);
        if(ans2[t]!=-1) ans2[t]/=60;
        printf("%.8f %.8f\n",tmp,ans2[t]);
    }
    return 0;
}

