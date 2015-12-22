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
 
 
template<class T>
struct BIT {
    typedef T int_type;
    static const size_t SIZE = 1<<10;
    int_type data[SIZE];
    BIT() {
        memset(data,0,sizeof(data));
    }
    void add(size_t i, int_type x) {
        while(i<=SIZE){
            data[i]+=x;
            i+=i&-i;
        }
    }
    int_type sum(size_t i) {
        int_type ret=0;
        while(i) {
            ret+=data[i];
            i-=i&-i;
        }

        return ret;
    }
    int_type sum(size_t l, size_t r) {
        return sum(r)-sum(l-1);
    }
};

BIT<int> bit[502];
int R,C,K;
char s[502][502];
 
inline bool ok(int y0,int x0) {
    for(int x=x0-K;x<=x0+K;x++) {
        int d=K-abs(x0-x);
        // [y0-d,y0+d]にxがあるか調べたい
        if(bit[x].sum(y0-d+1,y0+d+1)>0) return false;
    }

    //printf("%d %d\n",y0,x0);
 
    return true;
}
 
int main() {
    scanf("%d %d %d",&R,&C,&K);
    K--;
    rep(y,R) {
        scanf("%s",s[y]);
        rep(x,C)if(s[y][x]=='x') bit[x].add(y+1,1);
    }
 
    int ans=0;
 
    rep(y,R) rep(x,C) if(s[y][x]=='o') {
        if(y-K<0||x-K<0) continue;
        if(y+K>=R||x+K>=C) continue;
        if(ok(y,x)) ans++;
    }
 
    printf("%d\n",ans);
    return 0;
}
