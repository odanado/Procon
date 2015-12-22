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
int g[102],b[102];

int main() {
    cin>>n>>m;
    int a;
    cin>>a;
    rep(i,a) {
        int x;
        cin>>x;
        b[x]=1;
    }
    cin>>a;
    rep(i,a) {
        int x;
        cin>>x;
        g[x]=1;
    }
    rep(i,2*n*m) {
        if(b[i%n]==1 || g[i%m]==1) {
            b[i%n]=1;
            g[i%m]=1;
        }
    }

    bool ans=true;
    rep(i,n) ans&=b[i];
    rep(i,m) ans&=g[i];
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    return 0;
}

