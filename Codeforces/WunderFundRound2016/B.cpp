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
int a[51][51];
int ok(int x) {
    int m=0;
    rep(i,n) m=max(m,a[i][x]);
    rep(i,n) if(a[i][x]!=0&&a[i][x]!=m) return 0;
    rep(i,n) if(a[x][i]!=0&&a[x][i]!=m) return 0;
    return m;
}
int main() {
    cin>>n;
    vector<int> ans(n);
    rep(i,n) rep(j,n) cin>>a[i][j];
    int cnt=0;
    while(cnt+1!=n) {
        rep(i,n) {
            if(int m=ok(i)) {
                ans[i]=m;
                rep(j,n) a[i][j]=0;
                rep(j,n) a[j][i]=0;
                cnt++;
                break;
            }
        }
    }
    int m=*max_element(all(ans));
    rep(i,n) if(ans[i]==0) ans[i]=m+1;
    rep(i,n) printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');

    return 0;
}

