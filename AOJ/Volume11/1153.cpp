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
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int n,m;

int sum(vector<int> vec) {
    int res=0;
    rep(i,vec.size()) res+=vec[i];

    return res;
}

void solve() {
    P ans = mp(INF,INF);
    vector<int> taro,hanako;
    rep(i,n) {
        int a;cin>>a;
        taro.pb(a);
    }
    rep(i,m) {
        int a;cin>>a;
        hanako.pb(a);
    }
    rep(i,n) rep(j,m) {
        swap(taro[i],hanako[j]);
        if(sum(taro)==sum(hanako)) {
            if(ans.fr+ans.sc>=taro[i]+hanako[j]) {
                ans = mp(taro[i],hanako[j]);
            }
        }
        swap(taro[i],hanako[j]);

    }
    // swap 後なんだからそりゃ出力が逆
    if(ans.fr==INF&&ans.sc==INF) cout<<"-1"<<endl;
    else cout<<ans.sc<<" " <<ans.fr<<endl;

    return;

}


int main() {
    while(cin>>n>>m){

        if(!(n+m)) return 0;
        solve();

    }
    return 0;
}



