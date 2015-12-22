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

template<class T>
bool chmax(T& a,const T& b) {
    if(a<b) {
        a=b;
        return true;
    }
    return false;
}
template<class T>
bool chmin(T& a,const T& b) {
    if(a>b) {
        a=b;
        return true;
    }
    return false;
}
int N;
int H[3003];
struct Movie {
    int m,s,e;
    Movie(int m=0,int s=0,int e=0) :
        m(m),s(s),e(e){}

    bool operator<(const Movie& movie) const {
        return this->s<movie.s;
    }
};
Movie M[3003];
int dp[3003];

int main() {
    int ans=0;
    cin>>N;
    rep(i,N) cin>>H[i];
    rep(i,N) {
        int m,s,e;
        cin>>m>>s>>e;
        M[i]=Movie(m,s,e);
    }
    sort(M,M+N);

    rep(i,N) {
        chmax(dp[i],H[0]);
        int cnt=0;
        int last=M[i].e;
        int sum=0;
        rep(j,N) if(i<j) {
            if(M[j].s<M[i].e) continue;
            if(M[i].m!=M[j].m) chmax(dp[j],dp[i]+H[0]);
            else {
                if(last<=M[j].s) {
                    cnt++;
                    sum+=H[cnt];
                    last=M[j].e;
                }
                else {
                    last=min(last,M[j].e);
                }
                chmax(dp[j],dp[i]+sum);
            }
        }
        chmax(ans,dp[i]);
    }

    cout<<ans<<endl;

    return 0;
}

