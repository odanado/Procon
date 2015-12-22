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

int N,L;
int x[100005];
char d[100005];
vector<vector<int>> mat;
int main() {
    cin>>N>>L;
    x[0]=0;
    d[0]='R';
    rep(i,N) cin>>x[i+1]>>d[i+1];
    x[N]=L;
    d[N]='L';
    ll ans=0;
    int pos=0;
    vector<int> vec;

    rep(i,N+2) {
        if(d[i]=='L') {
            pos=i;
        }
        else {
            mat.pb(vec);
            vec.clear();
        }
        vec.pb(x[i]);
    }
    mat.pb(vec);
    rep(i,mat.size()) {
        rep(j,mat[i].size()) cout<<mat[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

