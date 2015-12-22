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
P a[5000];
int ans[5000];
int main() {
    cin>>n;
    rep(i,n) {
        int x;
        cin>>x;
        a[i]=P(-x,i);
    }
    sort(a,a+n);
    int cnt=1;
    ans[a[0].sc]=1;
    rep(i,n) if(i) {
        if(a[i-1].fr==a[i].fr) {
            ans[a[i].sc]=cnt;
        }
        else {
            ans[a[i].sc]=i+1;
            cnt=i+1;
        }
    }
    rep(i,n) {
        cout<<ans[i];
        if(i+1==n) cout<<endl;
        else cout<<" ";
    }
    return 0;
}

