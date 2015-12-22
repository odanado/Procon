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

int n;
int a[100005];
int cnt[100005];

int main() {
    cin>>n;
    rep(i,n) cin>>a[i];
    set<int> S,S2;
    rep(i,n) S.insert(a[i]);
    rep(i,n) cnt[a[i]]++;
    rep(i,n) {
        if(!S.count(i+1)) S2.insert(i+1);
    }

    int pos=0;

    for(auto e : S2) {
        //printf("%d\n",e);
        if(cnt[e]==0) {
            while(1) {
                if(cnt[a[pos]]>=2||a[pos]>n) break;
                pos++;
            }
            cnt[a[pos]]--;
            a[pos]=e;
        }
    }


    rep(i,n) cout<<a[i]<<(i+1==n?"\n":" ");

    /*
    sort(a,a+n);
    rep(i,n) {
        int pos = lower_bound(a,a+n,i+1) - a;
        //printf("%d %d\n",pos,a[pos]);
        if(pos==n) {
            a[pos-1]=i+1;
        }
        else if(a[pos]!=i+1) {
            a[pos]=i+1;
        }
    }
    */
    return 0;
}

