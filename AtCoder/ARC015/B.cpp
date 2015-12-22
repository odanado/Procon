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

int ans[7];
int main() {
    int n;
    double a,b;
    cin>>n;
    rep(i,n) {
        cin>>a>>b;
        if(a>=35) ans[0]++;
        else if(a>=30) ans[1]++;
        else if(a>=25) ans[2]++;

        if(b>=25) ans[3]++;
        if(b<0&&a>=0) ans[4]++;
        if(a<0) ans[5]++;
    }
    rep(i,6) {
        cout<<ans[i];
        if(i+1==6) cout<<endl;
        else cout<<" ";
    }
    return 0;
}

