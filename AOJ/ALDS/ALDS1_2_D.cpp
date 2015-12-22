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

int cnt=0;
void insertion_sort(int *a,int n, int g) {
    for(int i=g;i<n;i++) {
        int v=a[i];
        int j=i-g;
        while(j>=0&&a[j]>v) {
            a[j+g]=a[j];
            j-=g;
            cnt++;
        }
        a[j+g]=v;
    }
}

vector<int> G;
void shell_sort(int *a,int n) {
    int h=1;
    while(h<=n) {
        G.pb(h);
        h=3*h+1;
    }

    reverse(all(G));
    rep(i,G.size()) insertion_sort(a,n,G[i]);

}

int n;
int a[1000006];

int main() {
    cin>>n;
    rep(i,n) cin>>a[i];

    shell_sort(a,n);
    cout<<G.size()<<endl;
    rep(i,G.size()) cout<<(i==0?"":" ")<<G[i];
    if(G.size()) cout<<endl;
    cout<<cnt<<endl;
    rep(i,n) cout<<a[i]<<endl;
    return 0;
}

