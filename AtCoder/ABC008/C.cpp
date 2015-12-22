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
vector<int> vec;
int f() {
    int cnt=0;
    bool f[10];
    rep(i,10) f[i]=true;
    rep(i,vec.size()) {
        for(int j=i+1;j<vec.size();j++) {
            if(vec[j]%vec[i]==0) {
                f[j]^=1;
            }
        }
    }

    /*
    rep(i,vec.size()) cout<<vec[i]<<",";
    cout<<endl;
    rep(i,vec.size()) cout<<f[i]<<",";
    cout<<endl;
    */
    rep(i,vec.size()) if(f[i]) cnt++;


    return cnt;
}
int main() {
    cin>>N;
    rep(i,N) {
        int a;
        cin>>a;
        vec.pb(a);
    }
    double ans=0.0;
    rep(i,vec.size()) {
        int s = 0;
        rep(j,vec.size()) {
            if(vec[i]%vec[j]==0&&i!=j) s++;
        }
        if(s&1) ans+=0.5;
        else ans+=1.0*((s>>1)+1.0)/(s+1.0);

    }
    printf("%.8f\n",ans);
    return 0;
}

