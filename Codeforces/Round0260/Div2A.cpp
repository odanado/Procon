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
vector<P> vec;
int main() {
    cin>>n;
    rep(i,n) {
        int a,b;
        cin>>a>>b;
        vec.pb(P(a,b));
    }
    int a=0,b=0;
    rep(i,n) {
        if(vec[i].fr>a) {
            a = vec[i].fr;
            b = vec[i].sc;
        }
    }
    bool ans = false;
    rep(i,n) {
        if(vec[i].fr<a && vec[i].sc>b) {
            ans = true;
        }
    }
    if(ans) {
        cout<<"Happy Alex"<<endl;
    }
    else {
        cout<<"Poor Alex"<<endl;
    }

    return 0;
}

