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
#define fr first
#define sc second

typedef long long ll;
const ll INF=100000000;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
using namespace std;

struct Spell {
    ll mp,target,damage;
    Spell(ll mp=0,ll target=0,ll damage=0) :
        mp(mp),target(target),damage(damage){}

};

struct State {
    ll cost;
    vector<int> HP;
    State(ll cost=0,const vector<int> &HP=vector<int>()):
        cost(cost),HP(HP){}
    bool operator<(const State& rhs) const {
        return cost>rhs.cost;
    }
};

ll N;
vector<int> HP;
ll M;
Spell spells[102];
ll dp1[1000006],dp2[1000006];

ll solve() {
    ll ret=INF;
    rep(i,1000006) dp1[i]=dp2[i]=INF;
    dp1[0]=dp2[0]=0;
    rep(i,M) rep(j,1000006) {
        if(j+spells[i].damage>=1000006) continue;
        if(spells[i].target==0) {
            dp1[j+spells[i].damage]=min(dp1[j+spells[i].damage],dp1[j]+spells[i].mp);
        }
        else {
            dp2[j+spells[i].damage]=min(dp2[j+spells[i].damage],dp2[j]+spells[i].mp);
        }
    }
    for(ll i=1000005;i>=1;i--) {
        dp2[i-1]=min(dp2[i],dp2[i-1]);
        dp1[i-1]=min(dp1[i],dp1[i-1]);
    }

    rep(i,1000006) {
        ll s=dp2[i];
        rep(j,N) {
            s+=dp1[max(0,HP[j]-i)];
        }

        //printf("%d %d\n",i,s);
        ret=min(ret,s);
    }

    return ret;
}

int main() {
    while(cin>>N) {
        HP.clear();
        if(!N) break;
        HP.resize(N);
        rep(i,N) cin>>HP[i];
        cin>>M;
        rep(i,M) {
            string s1,s2;
            ll mp,damage;
            cin>>s1>>mp>>s2>>damage;
            ll t=0;
            if(s2=="All") t=1;
            spells[i]=Spell(mp,t,damage);
        }
        cout<<solve()<<endl;
    }
    return 0;
}

