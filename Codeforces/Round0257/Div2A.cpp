#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdint>
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
int n,m;
int a[103];
int b[103];
bool f[103];

int main() {
    int ans = 1;
    int cnt = 0;
    cin>>n>>m;
    rep(i,n) cin>>a[i];
    while(cnt != n) {
        rep(i,n) {
            b[i]+=m;
            if(!f[i] && a[i]<=b[i]) {
                f[i]=true;
                cnt++;
                ans = i+1;
            }
        }
    }
    cout<<ans<<endl;


    return 0;
}

