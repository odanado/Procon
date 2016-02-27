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
    string s;
    cin>>s;
    int ans=INF;
    rep(i,s.size()) rep(j,s.size()) rep(k,s.size()) if(i<j&&j<k) {
        if(s[i]=='c'&&s[j]=='w'&&s[k]=='w') {
            ans=min(ans,k-i);
        }
    }
    if(ans==INF) ans=-2;
    cout<<ans+1<<endl;
    return 0;
}

