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
string S;
int a[100005];
int b[100005];

int main() {
    cin>>S;
    rep(i,S.size()) {
        if(S[i]=='+') a[i]++;
        if(S[i]=='-') b[i]++;
    }
    for(int i=S.size();i>=1;i--) {
        a[i-1]+=a[i];
        b[i-1]+=b[i];
    }
    vector<int> vec;
    rep(i,S.size()) if(S[i]=='M') {
        vec.pb(a[i]-b[i]);
    }
    sort(all(vec));
    reverse(all(vec));
    int ans=0;
    rep(i,vec.size()) {
        if(i<vec.size()/2) ans+=vec[i];
        else ans-=vec[i];
    }
    cout<<ans<<endl;
    return 0;
}

