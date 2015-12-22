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

class Powerit{
public:
    int mod_pow2(int a,int n,int m) {
        int ret = 1;
        rep(i,n) {
            ret *= a;
            ret %= m;
            a *= a;
            a %= m;
        }

        return ret;
    }
    int mod_pow(int a,int n,int m) {
        int ret = 1;
        while(n > 0) {
            if(n & 1) {
                ret *= a;
                ret %= m;
            }
            a *= a;
            a %= m;

            n >>= 1;
        }

        return ret;
    }
    int calc(int n, int k, int m) {
        ll ans=0;
        rep(i,n+1) if(i) {
            ans+=mod_pow2(i,k,m)%m;
            ans%=m;
        }

        return ans;
    }
};

int main() {
    return 0;
}

