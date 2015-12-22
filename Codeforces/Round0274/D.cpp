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

int n,l,x,y;
int a[20005];
set<int> d;
bool a_find(int xxx) {
    rep(i,n) if(a[i]==xxx) return true;
    return false;

}
bool func(int z) {
    rep(i,n) {
        int r = abs(a[i]-z);
        if(d.find(r) != d.end()) return true;
    }
    return false;
}
int main() {
    cin>>n>>l>>x>>y;
    rep(i,n) cin>>a[i];
    if(a_find(x) && a_find(y)) {
        cout<<"0"<<endl;
        return 0;
    }
    rep(i,n-1) d.insert(abs(a[i]-a[i+1]));
    bool f1 = func(x);
    bool f2 = func(y);
    if(f1&f2) {
        cout<<"0"<<endl;
    }
    else if(f1&!f2) {
        cout<<"1"<<endl;
        cout<<y<<endl;
    }
    else if(!f1&f2) {
        cout<<"1"<<endl;
        cout<<x<<endl;
    }
    else {
        cout<<"2"<<endl;
        cout<<x<<" "<<y<<endl;

    }


    return 0;
}

