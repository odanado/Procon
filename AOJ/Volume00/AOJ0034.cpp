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

int l[10];
int v1,v2;
void solve() {

    int sum=0;
    rep(i,10) sum+=l[i];
    int v=v1+v2;
    double a = 1.0*sum/v;
    double b = a*v1;
    // cout<<b<<endl;
    rep(i,10) {
        if(b<=l[i]) {
            cout<<i+1<<endl;
            return;
        }
        b-=l[i];
    }
}
int main() {
    while(~scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&l[0],&l[1],&l[2],&l[3],
                &l[4],&l[5],&l[6],&l[7],&l[8],&l[9],&v1,&v2)) {

        solve();


    }
    return 0;
}

