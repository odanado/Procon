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
    int N;
    int a[102];
    cin>>N;
    rep(i,N) cin>>a[i];
    int s=0;
    rep(i,N) s+=a[i];
    if(s%N!=0) {
        cout<<"-1"<<endl;
        return 0;
    }
    int t=s/N;
    s=0;
    int ans=0,cnt=1;
    rep(i,N) {
        if((a[i]+s)%cnt==0&&(a[i]+s)/cnt==t) {
            s=0;
            cnt=1;
            continue;
        }
        cnt++;
        s+=a[i];
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}

