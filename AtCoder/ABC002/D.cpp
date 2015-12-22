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

int N,M;
bool mat[20][20];

int bitcount(int a) {
    int res=0;
    while(a) {
        if(a&1) res++;
        a>>=1;
    }
    return res;
}
int main() {
    cin>>N>>M;
    int ans = 0;
    rep(i,M) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        mat[x][y]=mat[y][x]=true;
    }
    rep(i,(1<<N)) {
        bool flag = true;
        rep(j,N) {
            if(!((i>>j)&1)) {
                continue;
            }
            rep(k,N) {
                if(j==k) continue;
                if(!((i>>k)&1)) {
                    continue;
                }
                if(!mat[j][k]) flag=false;
            }
        }
        if(flag) ans=max(ans,bitcount(i));

    }
    cout<<ans<<endl;
    return 0;
}

