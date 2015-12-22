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

int N,R;
string s;
bool finish(string s) {
    bool ret=true;
    rep(i,N) ret&=s[i]=='o';

    return ret;
}
string fill(int pos,string s) {
    for(int i=pos;i<pos+R&&i<N;i++) s[i]='o';

    return s;
}

int main() {
    cin>>N>>R;
    cin>>s;
    int ans=0;
    int pos=0;
    if(finish(s)) {
        cout<<"0"<<endl;
        return 0;
    }
    while(pos<N) {
        //printf("%d %d\n",pos,ans);
        string t=fill(pos,s);
        if(finish(t)) {
            ans++;
            break;
        }
        if(s[pos]=='.') {
            s=t;
            ans++;
        }
        ans++;
        pos++;
        
    }



    cout<<ans<<endl;

    return 0;
}

