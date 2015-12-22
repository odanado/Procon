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

int k;
char cnv(char c,int d) {
    c-='0';
    c=(c+d+10)%10;
    return c+'0';
}
int dfs(int pos,int cnt,string s,const string &goal) {
    //cout<<pos<<","<<cnt<<": "<<s<<endl;
    if(pos==s.size()) {
        if(s==goal) return cnt;
        else return INF;
    }
    int v1=s[pos]-'0';
    int v2=goal[pos]-'0';
    int d=v2-v1;
    int ret=INF;

    if(d==0) ret=min(ret,dfs(pos+1,cnt,s,goal));
    else {
        for(int i=pos;i<k;i++) {
            s[i]=cnv(s[i],d);
            ret=min(ret,dfs(pos+1,cnt+1,s,goal));
        }
    }

    return ret;
}

int main() {
    string init,goal;
    while(1) {
        cin>>k;
        if(k==0) break;
        cin>>init>>goal;
        cout<<dfs(0,0,init,goal)<<endl;
    }
    return 0;
}

