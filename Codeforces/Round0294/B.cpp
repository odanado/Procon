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
int n;
multiset<int> a,b,c,res;

int main() {
    int x;
    cin>>n;
    rep(i,n) {
        cin>>x;
        a.insert(x);
    }
    rep(i,n-1) {
        cin>>x;
        b.insert(x);
    }
    rep(i,n-2) {
        cin>>x;
        c.insert(x);
    }



    set_difference(all(a),all(b),inserter(res,res.end()));
    cout<<*res.begin()<<endl;
    res.clear();
    set_difference(all(b),all(c),inserter(res,res.end()));
    cout<<*res.begin()<<endl;

    return 0;
}

