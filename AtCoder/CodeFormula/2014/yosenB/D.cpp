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

int N;
int A[55];
const int MOD = 1000000007;
vector<vector<ll> > mat;
int main() {
    cin>>N;
    rep(i,N) cin>>A[i];

    vector<ll> vec;
    ll sum = 0;
    rep(i,N) {
        sum += A[i];
        sum /= 10;
        // cout<<sum<<endl;
        if(sum==0) {
            vec.pb(A[i]);
            mat.pb(vec);
            vec.clear();
            sum = 0;
        }
        else {
            vec.pb(A[i]);
        }
    }
    mat.pb(vec);

    ll ans = 1;
    rep(i,mat.size()) {
        vec = mat[i];
        ll a = 1;
        sum = 1;
        rep(j,vec.size()) {
            // cout<<vec[j]<<",";
            sum += (a*vec[j])%MOD;
            a *= 10;
            a %= MOD;
        }
        // cout<<endl;
        // cout<<sum<<endl;
        ans *= sum;
        ans %= MOD;

    }
    ans--;
    ans+=MOD;
    ans%=MOD;

    cout<<ans<<endl;


    return 0;
}

