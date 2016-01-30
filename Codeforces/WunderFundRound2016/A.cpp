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
vector<int> ans;
void add() {
    rep(i,ans.size()) {
        if(ans[i]==1) {
            ans[i]++;
            return;
        }
    }
    ans.pb(1);
}

void pack() {
    for(int i=ans.size()-2;i>=0;i--) {
        int t1=ans[i+1];
        int t2=ans[i];
        if(t1!=t2) break;
        ans[i+1]=-1;
        ans[i]++;
    }
    auto it=ans.begin();
    while(it!=ans.end()) {
        if(*it==-1) it=ans.erase(it);
        else it++;
    }
}
int main() {
    cin>>n;
    rep(i,n) {
        add();
        pack();
    }
    rep(i,ans.size()) printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
    return 0;
}

