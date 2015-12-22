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
typedef long long ll;
typedef pair<ll ,ll > P;

ll cross(P p1,P p2) {
    ll m1=max(p1.fr,p2.fr);
    ll m2=min(p1.sc,p2.sc);

    return max(0LL,m2-m1);
}

int main() {
    vector<P> segs;
    P seg;
    seg.sc=INF;
    int n;
    cin>>n;
    rep(i,n) {
        P p;
        int h,m,s,mm;
        scanf("%2d:%2d:%2d.%3d",&h,&m,&s,&mm);
        p.fr=mm+s*1000+m*1000*60+h*1000*60*60;
        scanf("%2d:%2d:%2d.%3d",&h,&m,&s,&mm);
        p.sc=mm+s*1000+m*1000*60+h*1000*60*60;
        segs.pb(p);
    }

    rep(i,n) {
        //printf("%d %d\n",segs[i].fr,segs[i].sc);
        if(segs[i].fr>segs[i].sc) {
            ll d=segs[i].fr-segs[i].sc;
            if(d<=1000) {
                seg.fr=max(seg.fr,segs[i].fr);
                seg.sc=min(seg.sc,segs[i].sc+1000);
            }
        }
    }
    rep(i,n) {
        ll d=segs[i].fr-segs[i].sc;
        d=abs(d);
        if(segs[i].fr<segs[i].sc) {
            ll t=cross(segs[i],seg);
            if(t&&t!=seg.sc-seg.fr) {
                cout<<"-1"<<endl;
                continue;
            }
            if(t) {
                t=max(t,1000LL);
                d+=t;
            }
            cout<<d<<endl;
        }
        else {
            if(d>1000) cout<<"-1"<<endl;
            else cout<<d<<endl;
        }
    }

    return 0;
}

