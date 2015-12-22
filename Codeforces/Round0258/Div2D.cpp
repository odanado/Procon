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

string s;
ll cnt[2]['c'];
// コンビネーションの計算
// 奇数の回文列を作るにはnのうちの1つを選ぶと残りのn-1の個数との組み合わせになる
ll f(ll n) {
    return n*(n-1)/2;
}
int main() {
    cin>>s;
    rep(i,s.size()) {
        cnt[i&1][s[i]]++;
    }
    //cout<<cnt[0]['a']<<","<<cnt[0]['b']<<endl;
    //cout<<cnt[1]['a']<<","<<cnt[1]['b']<<endl;
    ll ans1 = f(cnt[0]['a']) + f(cnt[0]['b']);
    ans1 += f(cnt[1]['a']) + f(cnt[1]['b']);
    ans1 += s.size();

    ll ans2 = cnt[0]['a']*cnt[1]['a'] + cnt[0]['b']*cnt[1]['b'];
    cout<<ans2<<" "<<ans1<<endl;
    return 0;
}

