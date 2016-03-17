#include <iostream>
#include <map>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
struct RollingHash {
    typedef long long int_type;
    typedef pair<int_type, int_type> hash_type;

    int_type base1, base2;
    int_type mod1, mod2;
    vector<int_type> hash1, hash2;
    vector<int_type> pow1, pow2;
    RollingHash() : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {}

    void init(vector<int> s) {
        int n=s.size();
        hash1.assign(n+1, 0);
        hash2.assign(n+1, 0);
        pow1.assign(n+1, 1);
        pow2.assign(n+1, 1);

        rep(i,n) {
            hash1[i+1] = (hash1[i]+s[i]) * base1 % mod1;
            hash2[i+1] = (hash2[i]+s[i]) * base2 % mod2;
            pow1[i+1] = pow1[i] * base1 % mod1;
            pow2[i+1] = pow2[i] * base2 % mod2;
        }
    }

    hash_type get(int l,int r) {
        auto t1 = ((hash1[r]-hash1[l]*pow1[r-l])%mod1+mod1)%mod1;
        auto t2 = ((hash2[r]-hash2[l]*pow2[r-l])%mod2+mod2)%mod2;
        return make_pair(t1, t2);
    }
};

int N;
vector<int> S;
RollingHash rh;
void dump (int l,int r) {
    for(int i=l;i<r;i++) cout<<S[i]<<" ";
    cout<<endl;
}
bool ok(int t) {
    bool ret=true;
    for(int i=t;i<N;i+=t) {
        ret &= rh.get(0,t) == rh.get(i,i+t);
    }

    return ret;
}
int main() {
    cin>>N;
    S.resize(N);
    rep(i,N) cin>>S[i];
    rh.init(S);
    int ans=1;
    rep(t,N+1) if(t&&N%t==0) {
        if(ok(t)) ans=max(ans,N/t);
    }
    cout<<ans<<endl;
    return 0;
}
