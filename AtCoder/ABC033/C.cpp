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
vector<string> vec;
int main() {
    cin>>S;
    string cur;
    rep(i,S.size()) {
        if(S[i]=='+') {
            vec.pb(cur);
            cur="";
        }
        else {
            cur+=S[i];
        }
    }
    vec.pb(cur);
    int ans=0;
    rep(i,vec.size()) {
        bool zero=false;
        rep(j,vec[i].size()) {
            zero|=vec[i][j]=='0';
        }
        if(!zero) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

