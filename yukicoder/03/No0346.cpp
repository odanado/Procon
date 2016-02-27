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

string s;
ll cnt=0;
int main() {
    cin>>s;
    ll ans=0;
    rep(_,s.size()) {
        int i=s.size()-1-_;
        if(s[i]=='c') {
            //cout<<cnt<<endl;
            ans+=(cnt*(cnt-1))/2;
        }
        if(s[i]=='w') cnt++;
    }

    cout<<ans<<endl;
    return 0;
}
