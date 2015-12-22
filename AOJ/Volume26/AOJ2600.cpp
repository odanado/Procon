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

int x[100005];
int y[100005];
int n,w,h;

int main() {
    cin>>n>>w>>h;
    rep(i,n) {
        int a,b,c;
        cin>>a>>b>>c;
        x[max(0,a-c)]++;
        x[min(100004,a+c)]--;
        y[max(0,b-c)]++;
        y[min(100004,b+c)]--;
    }
    rep(i,100005) if(i) x[i]+=x[i-1];
    rep(i,100005) if(i) y[i]+=y[i-1];
    bool ok1=true;
    bool ok2=true;
    rep(i,w) ok1&=x[i]!=0;
    rep(i,h) ok2&=y[i]!=0;
    if(ok1||ok2) {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

    return 0;
}

