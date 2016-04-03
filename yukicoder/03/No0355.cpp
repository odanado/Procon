#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF=1e9;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<int> ans;
pair<int,int> query(vector<int> vec) {
    rep(i,4) cout<<vec[i]<<(i==3?"\n":" ");
    cout<<flush;
    pair<int,int> ret;
    cin>>ret.first>>ret.second;
    return ret;
}
int sum(pair<int,int> p) {
    return p.first+p.second;
}
int main() {
    ans.resize(4);
    rep(i,4) ans[i]=i;
    vector<int> vec=ans;
    vec.resize(4);
    rep(i,4) {
        auto p=query(ans);
        rep(j,10) if(find(all(vec), j)==vec.end()) {
            vec[i]=j;
            auto t=query(vec);
            if(sum(t)>sum(p)) {
                p=t;
                ans=vec;
                break;
            }
        }
        vec=ans;
    }
    sort(all(ans));
    do {
        auto p=query(ans);
        if(p.first==4) break;
    }while(std::next_permutation(all(ans)));

    return 0;
}

