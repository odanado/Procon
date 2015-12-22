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

int sum;
string str;
map<int,int> ans;
map<int,int> ans2;

int to_s(const string &in) {
    int res;
    sscanf(in.c_str(),"%d",&res);
    return res;
}

void dfs(int pos,int s,int bit) {
    // cout<<pos<<","<<s<<endl;
    if(pos >= str.size()) {
        if(s <= sum) ans[s]++,ans2[s]=bit;
        return;
    }

    for(int i=1;i<=str.size()-pos;i++) {
        string tmp=str.substr(pos,i);
        // cout<<"  "<<s<<" + "<<to_s(tmp)<<endl;
        dfs(pos+i,s+to_s(tmp),bit | (1<<(pos+i)));
    }

}

void solve() {
    ans.clear();
    dfs(0,0,0);
    if(ans.size() == 0) {
        cout<<"error"<<endl;
        return;
    }
    auto it=ans.end();
    --it;

    if(it->sc==0) {
        cout<<"error"<<endl;
    }
    else if(it->sc==1) {
        int s=it->fr;
        int bit=ans2[s];
        cout<<s<<" ";
        rep(i,str.size()) {
            if((bit>>i)&1) cout<<" ";
            cout<<str[i];
        }
        cout<<endl;

    }
    else {
        cout<<"rejected"<<endl;
    }

}

int main() {
    while(cin>>sum>>str) {
        if(sum==0&&str=="0") break;
        solve();
    }
    return 0;
}

