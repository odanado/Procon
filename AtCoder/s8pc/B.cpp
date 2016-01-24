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

int H,W,N;
int X[11];
int Y[11];


bool ok(int x1,int y1) {
    int cnt1=0,cnt2=0;
    rep(i,N) {
        if(X[i]*y1==x1*Y[i]) return false;
        if(X[i]*y1<x1*Y[i]) cnt1++;
        else cnt2++;
    }
    //cout<<x1<<", "<<y1<<": "<<cnt1<<", "<<cnt2<<endl;

    return cnt1==cnt2;
}

int main() {
    cin>>H>>W>>N;
    rep(i,N) cin>>X[i]>>Y[i];
    set<P> ans;
    rep(i,H+1) if(i) if(ok(W,i)) ans.insert(P(W,i));
    rep(i,W+1) if(i) if(ok(i,H)) ans.insert(P(i,H));
    if(!ans.size()) {
        cout<<"-1"<<endl;
        return 0;
    }

    for(auto e:ans) {
        printf("(%d,%d)\n",e.fr,e.sc);
    }

    return 0;
}

