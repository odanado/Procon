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

int N,M;
int X[100005];
bool visit[100005];
bool ok(int t) {
    int p=1;
    rep(i,M) {
        printf("    [debug] %d: %d,%d\n",i,X[i],p);
        int d=abs(p-X[i]);
        if(p<X[i]) {
            if(t<d) return false;
            int nokori=t-d;
            if(nokori>d) {
                nokori-=d;
                p=X[i]+nokori;
            }
            else {
                p=X[i];
            }
            p++;
        }
        else {
            int nokori=t-d;
            if(nokori>0) {
                p+=nokori;
            }
            p++;
        }
        if(p>=N) return true;
    }

    return p>=N;
}
int main() {
    cin>>N>>M;
    rep(i,M) cin>>X[i];
    //rep(i,M) X[i]--;
    ll lb=-1,ub=INF;
    while(ub-lb>1) {
        ll mid=(ub+lb)/2;
        printf("[debug] %lld,%lld %lld\n",lb,ub,mid);
        if(ok(mid)) {
            cout<<"ok"<<endl;
            ub=mid;
        }
        else {
            cout<<"ng"<<endl;
            lb=mid;
        }
    }
    cout<<ub<<endl;
    return 0;
}

