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

void solve() {
    int a=1;
    bool f=false;
    rep(i,10) {
        if((n>>i)&1) {
            if(f) cout<<" "<<a;
            else {
                cout<<a;
                f=true;
            }

        }
        a<<=1;
    }
    cout<<endl;

}
int main() {
    while(cin>>n) {
        solve();
    }
    return 0;
}

