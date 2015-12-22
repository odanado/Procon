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
int main() {
    cin>>n;
    int a=1;
    bool f = true;
    rep(i,n) {
        int m = n - a;
        rep(i,m/2) cout<<"*";
        rep(i,a) cout<<"D";
        rep(i,m/2) cout<<"*";
        if(f) a+=2;
        else a-=2;
        if(a==n) f=false;
        cout<<endl;
    }
    return 0;
}

