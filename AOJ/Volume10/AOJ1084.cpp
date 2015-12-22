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

const int inf=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > p;
typedef long long ll;

int n;
int k;
int c[102];

void solve() {
    int maxi1,maxi2;
    maxi1=0;
    maxi2=0;
    rep(i,n) cin>>c[i];

    rep(i,n+1-k) {
        int tmp=1;
        rep(j,k) {
            tmp*=c[i+j];
        }
        maxi1=max(maxi1,tmp);
    }
    rep(i,n) rep(j,n) if(i<j) {
        swap(c[i],c[j]);
        rep(a,n+1-k) {
            int tmp=1;
            rep(b,k) tmp*=c[a+b];
            maxi2=max(maxi2,tmp);
        }
        
        swap(c[i],c[j]);
    }

    if(maxi2-maxi1<0) 
        cout<<"no game"<<endl;
    else
        cout<<maxi2-maxi1<<endl;

}

int main() {
    while(cin>>n>>k) {
        if(k+n==0) break;
        solve();
    }
    return 0;
}

