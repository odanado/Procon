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
int c[1000006];
int main() {
    cin>>n;
    rep(i,n) {
        int a,b;
        cin>>a>>b;
        c[a]++;
        c[b+1]--;
    }
    // rep(i,1000006) cout<<c[i]<<endl;
    rep(i,1000006) c[i+1]+=c[i];
    cout<<*max_element(c,c+1000006)<<endl;
    return 0;
}

