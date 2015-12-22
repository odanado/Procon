#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

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


int R,C,K;
char s[502][502];
//y,xに最も近いxのy座標
int ary[502][502];

inline bool ok(int y0,int x0) {
    for(int x=x0-K;x<=x0+K;x++) {
        int d=K-abs(x0-x);
        // [y0-d,y0+d]にxがあるか調べたい
        if(ary[y0][x] <= d) return false;
    }

    return true;
}

int main() {
    rep(y,502) rep(x,502) ary[y][x]=INF;
    scanf("%d %d %d",&R,&C,&K);
    K--;
    rep(y,R) {
        scanf("%s",s[y]);
    }
    rep(y0,R) rep(x0,C) {
        int t=INF;
        for(int y=0;y<R;y++) {
            if(s[y][x0]=='x') {
                t=min(t,abs(y0-y));
            }
        }
        ary[y0][x0]=min(ary[y0][x0],t);

    }

    int ans=0;
    //rep(i,R) rep(j,C) printf("%d %d: %d\n",i,j,ary[i][j]);

    rep(y,R) rep(x,C) if(s[y][x]=='o') {
        if(y-K<0||x-K<0) continue;
        if(y+K>=R||x+K>=C) continue;
        if(ok(y,x)) ans++;
    }

    printf("%d\n",ans);
    return 0;
}
