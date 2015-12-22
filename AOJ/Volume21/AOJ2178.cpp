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
typedef pair<P,int> Pi;
typedef long long ll;

int n;


bool bfs(int t,map<P,P> &futon,pair<P,P> f) {
    queue<Pi> que;
    que.push(Pi(f.fr,t));
    f.sc.sc=t;
    futon[f.fr]=f.sc;
    map<Pi,bool> visited;
    visited[(Pi(f.fr,t))]=true;;

    while(que.size()) {
        Pi pi = que.front(); que.pop();
        P p=pi.fr;
        //printf("[debug] %d : %d %d %d\n",t,p.fr,p.sc,pi.sc);
        rep(k,4) {
            int ny=p.fr+dy[k];
            int nx=p.sc+dx[k];
            int t=pi.sc;

            if(!futon.count(P(ny,nx))) continue;
            //if(futon[P(ny,nx)].sc!=-1) continue;

            // 同じ布団内
            if(futon[P(ny,nx)].fr==futon[p].fr) {
                if(futon[P(ny,nx)].sc!=-1&&futon[P(ny,nx)].sc!=(t^1)) return false;
                if(visited.count(Pi(P(ny,nx),t^1))) continue;
                visited[(Pi(P(ny,nx),t^1))]=true;
                futon[P(ny,nx)].sc=t^1;
                que.push(Pi(P(ny,nx),t^1));
            }
            else {
                if(futon[P(ny,nx)].sc!=-1&&futon[P(ny,nx)].sc!=t) return false;
                if(visited.count(Pi(P(ny,nx),t))) continue;
                visited[(Pi(P(ny,nx),t))]=true;
                futon[P(ny,nx)].sc=t;
                que.push(Pi(P(ny,nx),t));
            }

        }
    }

    return true;
}

void solve() {
    map<P,P> futon;
    rep(i,n) {
        P pos;
        char d;
        cin>>pos.sc>>pos.fr>>d;
        futon[pos]=P(i,-1);
        if(d=='x') {
            pos.sc+=1;
        }
        else {
            pos.fr+=1;
        }
        futon[pos]=P(i,-1);
    }
    bool f=true;
    for(auto e : futon) {
        if(e.sc.sc==-1) {
            if(!bfs(0,futon,e)) f=false;
        }
    }
    if(f) {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}

int main() {
    while(cin>>n) {
        if(n==0) break;
        solve();
    }
    return 0;
}

