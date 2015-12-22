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

int main() {
    int n,m;
    cin>>n>>m;
    int t = (n+1)/2;
    int ans = t;
    if(t==0) {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=t;i<=n;i++) {
        if(i % m == 0) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;

    return 0;
}

