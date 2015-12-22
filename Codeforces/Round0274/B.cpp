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

int n,k;
int a[103];
int sum;
P find_maxmini() {
    int mini = INF;
    int maxi = 0;
    int mini_idx = 0;
    int maxi_idx = 0;
    rep(i,n) {
        if(a[i] < mini) {
            mini = a[i];
            mini_idx = i;
        }
        if(maxi < a[i]) {
            maxi = a[i];
            maxi_idx = i;
        }
    }

    return P(maxi_idx,mini_idx);

}
int main() {
    cin>>n>>k;
    rep(i,n) cin>>a[i];
    rep(i,n) sum += a[i];
    vector<P> ans;
    rep(i,k) {
        P p = find_maxmini();
        int maxi_idx = p.first;
        int mini_idx = p.sc;
        if(sum % n != 0) {
            if(a[maxi_idx]-a[mini_idx] == 1) {
                break;
            }
            a[maxi_idx]--;
            a[mini_idx]++;
            ans.pb(P(maxi_idx,mini_idx));
        }
        else {
            if(a[maxi_idx]-a[mini_idx] == 0) {
                break;
            }
            a[maxi_idx]--;
            a[mini_idx]++;
            ans.pb(P(maxi_idx,mini_idx));

        }

    }
    P p = find_maxmini();
    int maxi_idx = p.first;
    int mini_idx = p.sc;
    cout<<a[maxi_idx]-a[mini_idx]<<" "<<ans.size()<<endl;
    rep(i,ans.size()) {
        P p = ans[i];
        cout<<p.fr+1<<" "<<p.sc+1<<endl;

    }
    return 0;
}

