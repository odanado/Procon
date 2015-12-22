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

struct RollingHash {
    typedef long long int_type;
    typedef pair<int_type,int_type> hash_type;

    int_type base1;
    int_type base2;
    int_type mod1;
    int_type mod2;
    vector<int_type> hash1;
    vector<int_type> hash2;
    vector<int_type> pow1;
    vector<int_type> pow2;

    RollingHash() : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {}

    void init(const string &s) {
        int n = s.size();

        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        pow1.assign(n+1,1);
        pow2.assign(n+1,1);

        for(int i=0;i<n;i++) {
            hash1[i+1] = (hash1[i]+s[i]) * base1 % mod1;
            hash2[i+1] = (hash2[i]+s[i]) * base2 % mod2;
            pow1[i+1] = pow1[i] * base1 % mod1;
            pow2[i+1] = pow2[i] * base2 % mod2;
        }
    }

    hash_type get(int l,int r) {
        int_type t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
        int_type t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
        return make_pair(t1, t2);
    }

    RollingHash::hash_type concat(hash_type h1, hash_type h2, int h2_len) {
        return make_pair((h1.fr*pow1[h2_len]+h2.fr)%mod1, (h1.sc*pow2[h2_len]+h2.sc)%mod2);
    }

};

int n,m;
set<RollingHash::hash_type> S[600005];

int main() {
    RollingHash rh_abc[3];
    RollingHash rh;
    rh_abc[0].init("a");
    rh_abc[1].init("b");
    rh_abc[2].init("c");

    cin>>n>>m;
    rep(i,n) {
        string s;
        cin>>s;
        rh.init(s);
        int sz=s.size();
        S[sz].insert(rh.get(0,sz));
    }

    rep(i,m) {
        string s;
        cin>>s;
        int sz=s.size();
        rh.init(s);
        bool flag = false;
        rep(j,sz) rep(k,3) {
            char c = 'a'+k;
            if(s[j]==c) continue;
            RollingHash::hash_type h;
            h = rh.concat(rh.get(0,j),rh_abc[k].get(0,1),1);
            h = rh.concat(h, rh.get(j+1,sz), sz-j-1);

            flag |= S[sz].count(h);
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}

