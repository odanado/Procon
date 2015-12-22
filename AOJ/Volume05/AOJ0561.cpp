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

int N,K;
vector<int> books[2003];
int sum[2003][2003];;
int dp[2003][2003];

template<class T>
bool chmax(T &a, const T &b) {
    if(a<b) {
        a=b;
        return true;
    }
    return false;

}

int main() {
    cin>>N>>K;
    rep(i,N) {
        int c,g;
        cin>>c>>g;
        g--;
        books[g].pb(c);
    }
    rep(i,2003) sort(all(books[i]),greater<int>());
    rep(i,2003) {
        if(books[i].size()==0) continue;
        sum[i][0]=books[i][0];
        rep(j,books[i].size()) if(j) sum[i][j]=sum[i][j-1]+books[i][j]+j*2;
    }
    rep(i,N) rep(j,books[i].size()) {
        rep(k,K+1) {
            if(k-j-1>=0)
                chmax(dp[i][k],dp[i][k-j-1]+sum[i][j]);
        }
    }
    cout<<dp[N][K]<<endl;
    return 0;
}

