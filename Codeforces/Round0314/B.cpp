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
typedef pair<char ,int > P;
typedef long long ll;

int n;
int main() {
    vector<P> vec1,vec2;
    set<int> S;
    cin>>n;
    rep(i,n) {
        char c;
        int id;
        cin>>c>>id;
        vec1.pb(P(c,id));
    }
    rep(i,vec1.size()) {
        if(vec1[i].fr=='+') {
            S.insert(vec1[i].sc);
        }
        else {
            if(S.find(vec1[i].sc)==S.end()) {
                S.insert(vec1[i].sc);
                vec2.pb(P('+',vec1[i].sc));
            }
        }
    }
    rep(i,vec1.size()) vec2.pb(vec1[i]);
    int ans=0,cnt=0;
    rep(i,vec2.size()) {
        if(vec2[i].fr=='+') cnt++;
        else cnt--;
        ans=max(ans,cnt);
    }

    cout<<ans<<endl;
    return 0;
}

