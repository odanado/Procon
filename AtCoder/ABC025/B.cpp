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

int N,A,B;

int get(int d) {
    d=max(d,A);
    d=min(d,B);
    return d;
}

int main() {
    cin>>N>>A>>B;
    int ans=0;
    rep(i,N) {
        string s;
        int d;
        cin>>s>>d;
        if(s=="East") {
            ans-=get(d);
        }
        else ans+=get(d);
    }
    if(ans==0) cout<<ans<<endl;
    else if(ans<0) {
        cout<<"East "<<-ans<<endl;
    }
    else cout<<"West "<<ans<<endl;
    return 0;
}

