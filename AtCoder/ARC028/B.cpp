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

int N,K;
int X[100005];
int ans[100005];
set<int> S;
int t;
int main() {
    cin>>N>>K;
    vector<int> vec;
    rep(i,N) { 
        cin>>X[i];
        ans[X[i]] = i+1;
    }

    rep(i,K) vec.pb(X[i]);
    sort(all(vec)); 
    t = vec[K-1];
    cout<<ans[t]<<endl;
    rep(i,vec.size()) {
        if(vec[i]<t) S.insert(-vec[i]);
    }
    rep(i,N-K) {
        int a = X[i+K];
        //for(auto e : S) cout<<"S : "<<e<<endl;
        //cout<<"t = "<<t<<endl;
        if(a<t) {

            S.insert(-a);
            int maxi = -(*(S.begin()));
            //cout<<"max="<<maxi<<endl;
            S.erase(-maxi); 
            t = maxi;
        }
        cout<<ans[t]<<endl;
    }

    return 0;
}

