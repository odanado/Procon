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

string A,B;

bool func(string& s1,string& s2,int depth) {
    if(depth == 0) return s1==s2;
    bool res = false;
    rep(i,s1.size()) {
        rep(j,s1.size()) {
            if(i==j) continue;
            swap(s1[i],s1[j]);
            res |= func(s1,s2,depth-1);
            swap(s1[i],s1[j]);
        }
    }
    return res;
}

bool ok() {
    if(A.size()!=B.size()) return false;
    int cnt=0;
    rep(i,A.size()) if(A[i]!=B[i]) cnt++;
    if(cnt>6) return false;
    string t1,t2;
    rep(i,A.size()) {
        if(A[i]!=B[i]) {
            t1+=A[i];
            t2+=B[i];
        }
    }
    if(func(t1,t2,1)) return true;
    if(func(t1,t2,3)) return true;

    rep(i,A.size()) {
        if(2 <= count(all(A),A[i])) {
            if(func(t1,t2,0)) return true;
            if(func(t1,t2,2)) return true;
            return false;
        }
    }
    return false;
}
int main() {
    cin>>A>>B;
    string ans[] = {"NO","YES"};
    cout<<ans[ok()]<<endl;
    return 0;
}

