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
set<int> NG;
bool visited[301][101];
int main() {
    cin>>N;
    rep(i,3) {
        int a;cin>>a;
        NG.insert(a);
    }
    string ans="NO";

    queue<P> que;
    que.push(P(N,0));
    while(que.size()) {
        P p=que.front(); que.pop();
        //cout<<p.fr<<", "<<p.sc<<endl;
        if(visited[p.fr][p.sc]) continue;
        visited[p.fr][p.sc]=true;
        if(NG.count(p.fr)) continue;
        if(p.fr==0) {
            ans="YES";
            break;
        }
        if(p.sc==101) continue;
        rep(i,3) {
            int t=i+1;
            if(p.sc+1<101)
                que.push(P(p.fr-t,p.sc+1));
        }
    }

    cout<<ans<<endl;

    return 0;
}

