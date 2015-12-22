#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long ll;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int n;
int t[3][3];

int log2(ll a) {
    int res=0;
    if(a==0) return -1;
    while(a!=1) {
        a/=2;
        res++;
    }
    return res;
}

ll dfs(ll _S1,ll _S2,ll _S3) {
    cout<<_S3<<endl;
    if(_S3 == (1LL << n)-1) return 0;
    ll res = 1LL<<41;

    ll S[3] = {_S1,_S2,_S3};
    int S_min[3];
    rep(i,3) S_min[i] = log2(S[i]&-S[i]);

    rep(i,3) {
        rep(j,3) {
            //i -> j
            if(i==j) continue;

            if(S_min[i] < S_min[j]) {
                ll S1,S2,S3;
                if(i==0) {
                    S1 = S[i];
                    S1 &= ~(1LL<<S_min[i]);
                    if(j==1) S2 = S[j] | 1LL << S_min[j];
                    else S3 = S[j] | 1LL << S_min[j];
                }
                if(i==1) {
                    S2 = S[i];
                    S2 &= ~(1LL<<S_min[i]);
                    if(j==0) S1 = S[j] | 1LL << S_min[j];
                    else S3 = S[j] | 1LL << S_min[j];
                }
                if(i==2) {
                    S3 = S[i];
                    S3 &= ~(1LL<<S_min[i]);
                    if(j==0) S1 = S[j] | 1LL << S_min[j];
                    else S2 = S[j] | 1LL << S_min[j];
                }
                res = min(res,dfs(S1,S2,S3)+t[i][j]);
            }
        }
    }

    return res;
}

int main() {
    long long S[3];
    rep(i,3) rep(j,3) cin>>t[i][j];
    cin>>n;

    S[0] = (1LL << n)-1;
    S[1] = 0;
    S[2] = 0;

    long long ans = dfs(S[0],S[1],S[2]);

    cout<<ans<<endl;

    return 0;
}


