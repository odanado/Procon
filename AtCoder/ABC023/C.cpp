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


int R,C,K;
int N;
ll ans;
int cnt_R[100005],cnt_C[100005];

int main() {
    set<P> S;
    cin>>R>>C>>K;
    cin>>N;
    rep(i,N) {
        int r,c;
        cin>>r>>c;
        r--,c--;
        S.insert(P(r,c));
        cnt_R[r]++;
        cnt_C[c]++;
    }
    map<int,int> M;
    rep(i,R) {
        M[cnt_R[i]]++;
    }

    rep(i,C) {
        int s=K-cnt_C[i];
        //cout<<cnt_C[i]<<", "<<s<<", "<<M[s]<<endl;
        ans+=M[s];
    }
    //cout<<ans<<endl;
    for(auto e:S) {
        int s=cnt_R[e.fr]+cnt_C[e.sc];
        if(K==s) ans--;
        if(K==s-1) ans++;
    }



    cout<<ans<<endl;

    return 0;
}
