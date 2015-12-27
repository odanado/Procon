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
typedef long long ll;

int calc(char c1,char c2) {
    if(c1==c2) return 1;
    if(c1=='G'&&c2=='P') return 3;
    if(c1=='P'&&c2=='C') return 3;
    if(c1=='C'&&c2=='G') return 3;
    return 0;
}

template<class T>
bool chmax(T &a, const T &b) {
    if(a<b) {
        a=b;
        return true;
    }
    return false;
}

int encode(char c) {
    if(c=='G') return 0;
    else if(c=='C') return 1;
    else return 2;
}
int G,C,P;
string S;
int cnt1[3];
int cnt2[3];
int main() {
    cin>>G>>C>>P;
    cin>>S;
    cnt1[0]=G;
    cnt1[1]=C;
    cnt1[2]=P;
    rep(i,S.size()) cnt2[encode(S[i])]++;

    int ans=0;

    rep(i,3) {
        int t=min(cnt1[i],cnt2[(i+1)%3]);
        ans+=t*3;
        cnt1[i]-=t;
        cnt2[(i+1)%3]-=t;
    }

    rep(i,3) {
        ans+=min(cnt1[i],cnt2[i]);
    }

    cout<<ans<<endl;

    return 0;
}

