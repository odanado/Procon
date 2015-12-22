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

int N,M;
ll a[100005];
ll ans=0;
int main() {
    cin>>N>>M;
    rep(i,N) {
        int l,r,s;
        cin>>l>>r>>s;
        l--,r--;
        a[l]+=s;
        a[r+1]-=s;
        ans+=s;
    }

    rep(i,100005) if(i) a[i]+=a[i-1];
    ans-=*min_element(a,a+M);

    cout<<ans<<endl;
    return 0;
}

