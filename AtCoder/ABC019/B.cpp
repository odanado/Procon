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

string to_s(int n) {
    stringstream ss;
    ss<<n;
    return ss.str();
}

int main() {
    string s,ans;
    cin>>s;
    char c=s[0];
    int cnt=1;

    rep(i,s.size()) if(i) {
        if(c!=s[i]) {
            ans+=string(1,c)+to_s(cnt);
            cnt=0;
        }
        c=s[i];
        cnt++;
    }
    ans+=string(1,c)+to_s(cnt);

    cout<<ans<<endl;

    return 0;
}

