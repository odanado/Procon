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

int t;

void solve() {
    int n;
    int s,f;
    int sum = 0;
    cin>>n;
    rep(i,n) {
        cin>>s>>f;
        sum += f-s;
    }

    if(t<=sum) {
        cout<<"OK"<<endl;
    }
    else {
        cout<<t-sum<<endl;
    }
}

int main() {
    while(cin>>t) {
        if(t==0) break;
        solve();
    }
    return 0;
}

