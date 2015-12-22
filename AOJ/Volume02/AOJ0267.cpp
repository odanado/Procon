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
int b[205];
void plot() {
    rep(i,104) cout<<b[i]<<" ";
    cout<<endl;
}
void move() {
    //plot();
    int h = 0;
    rep(i,204) if(b[i]!=0) h++;
    rep(i,204) if(b[i]!=0) b[i]--;
    b[202]=h;
    //plot();
    rep(i,204) {
        if(!i) continue;
        if(b[i]!=0) {
            int j;
            for(j=i-1;j>=0;j--) {
                if(b[j]!=0) break;
            }
            swap(b[i],b[j+1]);
        }
    }

}
bool ok() {
    bool f=true;
    rep(i,204) {
        if(b[i]==0) break;
        f&=(i+1)==b[i];
    }
    return f;

}
void solve() {
    rep(i,205) b[i]=0;
    rep(i,N) cin>>b[i];
    int cnt=0;
    if(ok()) {
        cout<<"0"<<endl;
        return;
    }
    while(1) {
        cnt++;
        move();
        if(ok()) {
            cout<<cnt<<endl;
            return;
        }
        if(cnt == 10000) break;

    }
    cout<<"-1"<<endl;
}

int main() {
    while(cin>>N) {
        if(N==0) break;
        solve();

    }
    return 0;
}

