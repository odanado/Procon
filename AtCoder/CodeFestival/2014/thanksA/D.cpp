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

int N,Q;
int a[100005];
int b[100005];
int s[100005];
int t[100005];
int main() {
    cin>>N>>Q;
    rep(i,Q) cin>>a[i]>>b[i]>>s[i]>>t[i];
    rep(i,Q) {
        int ans = 0;


        if(b[i]<=s[i]) ans=t[i]-s[i];
        else if(t[i]<=a[i]) ans=t[i]-s[i];
        else if(a[i]<=s[i]&&t[i]<=b[i]) ans=0;
        else {
            if(a[i]-s[i]>=0) ans=a[i]-s[i];
            if(t[i]-b[i]>=0) ans+=t[i]-b[i];
        }
        cout<<ans*100<<endl;

    }
    return 0;
}

