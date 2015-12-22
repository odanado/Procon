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
int h[100005];
int add1[100005];
int add2[100005];

int main() {
    cin>>N;
    rep(i,100005) h[i]=INF;
    rep(i,N) cin>>h[i];
    rep(i,N) {
        if(i!=0&&h[i-1]<h[i]) add1[i]+=add1[i-1]+1;
        else add1[i]=0;
    }
    for(int i=N-2;i>=0;i--) {
        if(h[i+1]<h[i]) add2[i]+=add2[i+1]+1;
        else add2[i]=0;
    }
    rep(i,N) {
        cout<<add1[i]<<","<<add2[i]<<endl;
        cout<<add1[i]+add2[i]<<endl;
    }
    return 0;
}

