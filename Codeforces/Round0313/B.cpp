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

int a1,b1;
int a2,b2;
int a3,b3;
int a[1003][1003];

bool fill(int y0,int x0,int H,int W) {
    for(int y=y0;y<y0+H;y++) for(int x=x0;x<x0+W;x++) {
        if(a[y][x]==1) return false;
        a[y][x]=1;
    }

    return true;
}

bool ok() {
    rep(i,1003) rep(j,1003) a[i][j]=1;
    rep(i,a1) rep(j,b1) a[i][j]=0;
    if(!fill(0,0,a2,b2)) return false;
    rep(y,a1) rep(x,b1) {
        if(a[y][x]==0) if(fill(y,x,a3,b3)) {
            //cout<<y<<","<<x<<endl;
            return true;
        }
    }

    return false;
}

int main() {
    cin>>a1>>b1;
    cin>>a2>>b2;
    cin>>a3>>b3;
    if(ok()) {
        cout<<"YES"<<endl;
        return 0;
    }
    swap(a2,b2);
    if(ok()) {
        cout<<"YES"<<endl;
        return 0;
    }
    swap(a3,b3);
    if(ok()) {
        cout<<"YES"<<endl;
        return 0;
    }
    swap(a2,b2);
    if(ok()) {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}

