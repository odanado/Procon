#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

string ss;
int mod[]={0,5,3,3,3,3,3,4,3,4};
char key[][] = {
    {".",",","!","?"," "},
    {"a","b","c"},
    {"d","e","f"},
    {"g","h","i"},
    {"j","k","l"},
    {"m","n","o"},
    {"p","q","r","s"},
    {"t","u","v"},
    {"w","x","y","z"}
};

void solve() {
    char c;
    char a,b;
    a=b=ss[0];
    int cnt=0;
    rep(i,ss.size()) {
        a=ss[i];
        cnt++;
        if(ss[i]=='0') printf("%c",c);
        if(b!=a) {
            c=key[b-'0'][cnt%mod[b-'0']];
            cnt=0;
        }
        
        b=a;
    }
    puts("");

}

int main() {
    int n;
    cin>>n;
    rep(i,n) {
        cin>>ss;
        solve();
    }

    return 0;
}



