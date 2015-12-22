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

int N;
map<P,int> points;
P ary[4][4] = {
    {P(0,0),P(0,-1),P(-1,0),P(-1,-1)},
    {P(0,0),P(0,-1),P(1,0),P(1,-1)},
    {P(0,0),P(0,1),P(1,0),P(1,1)},
    {P(0,0),P(0,1),P(-1,0),P(-1,1)}
};
P operator+(P a,P b) {
    return P(a.fr+b.fr,a.sc+b.sc);
}
int main() {
    vector<P> vec;
    cin>>N;
    rep(i,N) {
        int x,y,w;
        cin>>x>>y>>w;
        vec.pb(P(x,y));
        points[P(x,y)]=w;
    }
    int ans=0;
    for(auto point : vec) {
        P p=point;
        rep(i,4) {
            int t=0;
            rep(j,4) {
                t+=points[p+ary[i][j]];
            }
            ans=max(ans,t);
        }
    }

    cout<<ans<<" / 1"<<endl;
    return 0;
}

