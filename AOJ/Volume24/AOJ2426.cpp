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

int n,m;
int sum[5003][5003];
int x[5003],y[5003];
vector<int> comp(int *a) {
    vector<int> vec;
    rep(i,n) vec.pb(a[i]);
    sort(all(vec));
    vec.erase(unique(all(vec)),vec.end());

    return vec;
}
int conv(vector<int> &vec,int x) {
    return lower_bound(all(vec),x)-vec.begin();
}
int main() {
    cin>>n>>m;
    rep(i,n) {
        cin>>x[i]>>y[i];
    }
    vector<int> comp_x=comp(x);
    vector<int> comp_y=comp(y);

    rep(i,n) {
        //printf("%d %d -> ",y[i],x[i]);
        int nx=conv(comp_x,x[i]);
        int ny=conv(comp_y,y[i]);
        //printf("%d %d\n",ny,nx);
        sum[ny+1][nx+1]++;
    }

    rep(i,comp_y.size()+1) rep(j,comp_x.size()+1) if(i&&j) {
        sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    }

    rep(i,m) {
        int x1,x2;
        int y1,y2;
        cin>>x1>>y1>>x2>>y2;
        x1=conv(comp_x,x1);
        x2=conv(comp_x,x2+1);
        y1=conv(comp_y,y1);
        y2=conv(comp_y,y2+1);
        printf("%d\n",sum[y2][x2]-sum[y2][x1]-sum[y1][x2]+sum[y1][x1]);
    }

    return 0;
}

