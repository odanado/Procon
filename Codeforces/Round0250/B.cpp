#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int lowbit(int i) {
    return (i&-i);
}

int bin[20];
int sum,lim;
vector<P> vec;
vector<int> ans;

int main() {
    cin>>sum>>lim;
    for(int i=1;i<=lim;i++) {
        vec.pb(mp(lowbit(i),i));
    }
    sort(all(vec),greater<P>() );
    int s = 0;
    rep(i,lim) {
        if(s + vec[i].first < sum) {
            s+=vec[i].first;
            ans.pb(vec[i].second);
        }
        else if(s + vec[i].first == sum) {
            s+=vec[i].first;
            ans.pb(vec[i].second);
            break;
        }
    }
    if(s!=sum) {
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size()) {
        cout<<(i==0?"":" ")<<ans[i];
    }
    cout<<endl;
    return 0;
}



