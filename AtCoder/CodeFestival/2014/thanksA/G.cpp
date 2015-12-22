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
double p[103];

int bitcount(int S) {
    int res=0;
    rep(i,32) {
        if(S&1) res++;
        S>>=1;
    }
    return res;
}
int bitindex(int S) {
    int res=0;
    rep(i,32) {
        if((S&1)==0) return res;
        S>>=1;
        res++;
    }

    return res;
}
int isflag(int S, int i) {
    return (S>>i)&1;
}
int bitindex2(int S) {
    rep(i,31) {
        int a = i-1;
        int b = i;
        int c = i+1;
        if(!isflag(S,a) & !isflag(S,b) & !isflag(S,c)) {
            return i;
        }
    }
    return -1;
}
// 何人目,bit
double dfs(int a, int S) {
    // printf("[debug] %d,%d\n", a,S);
    if(N==a) return K-bitcount(S);
    if(K==bitcount(S)) return 0.0;
    double res = 0.0;
    int idx = bitindex(S);

    res += dfs(a+1, S|(1<<idx)) * p[a];
    int idx2 = bitindex2(S);
    if(idx2 != -1 && idx2 < K) {
        res += dfs(a+1, S|(1<<idx2)) * (1.0 - p[a]);
    }
    else {
        res += dfs(a+1, S) * (1.0 - p[a]);

    }
    return res;
}

int main() {
    cin>>N>>K;
    rep(i,N) cin>>p[i];
    rep(i,N) p[i] = p[i]/100.0;
    if(N>10) return 0;
    printf("%.10f\n", dfs(0,0));
    return 0;
}

