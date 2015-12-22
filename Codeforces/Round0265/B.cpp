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
int a[1003];

int next_index(int index) {
    int ret = index+1;
    while(1) {
        if(a[ret]==1) break;
        ret++;
        if(n<=ret) return -1;
    }
    return ret;
}
int main() {
    cin>>n;
    rep(i,n) cin>>a[i];
    int index = next_index(-1);
    //cout<<index<<endl;
    if(index==-1) {
        cout<<"0"<<endl;
        return 0;
    }
    int ans = 1;

    while(1) {
        if(index>=n) break;
        int tmp = next_index(index);
        //cout<<tmp<<endl;
        if(tmp==-1) break;
        int t = tmp-index;
        ans+=min(t,2);
        index=tmp;
    }
    
    cout<<ans<<endl;

    return 0;
}

