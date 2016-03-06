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

void dump(vector<P> vec) {
    rep(i,vec.size()) cout<<vec[i].fr<<", "<<vec[i].sc<<endl;
}
int N;
int R[100005],H[100005];
vector<P> vec[3];
int win[100005];
int lost[100005];
int main() {
    cin>>N;
    rep(i,3) vec[i].reserve(N);
    rep(i,N) {
        cin>>R[i]>>H[i];
        H[i]--;
        rep(j,3) vec[j].pb(P(R[i],(H[i])%3));
    }
    rep(i,3) {
        sort(all(vec[i]), [&](P &lhs,P &rhs){
                    if(lhs.fr!=rhs.fr) return lhs.fr > rhs.fr;
                    if(lhs.sc==rhs.sc) return false;
                    if((lhs.sc+1)%3==i) return true;
                    return false;
                });
    }
    rep(i,N) {
        P p=P(R[i],(H[i]));
        //cout<<"debug: "<<i<<endl;
        //cout<<"p = "<<p.fr<<", "<<p.sc<<endl;
        //dump(vec[H[i]]);
        lost[i]=lower_bound(all(vec[H[i]]), p, [&](const P &lhs,const P &rhs){
                    if(lhs.fr!=rhs.fr) return lhs.fr > rhs.fr;
                    if((lhs.sc+1)%3==rhs.sc) return true;
                    return false;
                }) - vec[H[i]].begin();
    }
    rep(i,3) {
        sort(all(vec[i]), [&](P &lhs,P &rhs){
                    if(lhs.fr!=rhs.fr) return lhs.fr < rhs.fr;
                    if(lhs.sc==rhs.sc) return false;
                    if((lhs.sc+2)%3==i) return true;
                    return false;
                });
    }
    rep(i,N) {
        P p=P(R[i],(H[i]));
        win[i]=lower_bound(all(vec[H[i]]), p, [&](const P &lhs,const P &rhs){
                    if(lhs.fr!=rhs.fr) return lhs.fr < rhs.fr;
                    if((lhs.sc+2)%3==rhs.sc) return true;
                    return false;
                }) - vec[H[i]].begin();
    }

    rep(i,N) {
        cout<<win[i]<<" "<<lost[i]<<" "<<(N-win[i]-lost[i]-1)<<endl;
    }

    return 0;
}

