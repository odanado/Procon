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
int R[10004];
stack<int> st[2];
vector<P> ans;

int now;
int idx = 0;
int st_id = 0;

int main() {
    cin>>N;
    if(N>400) return 0;
    rep(i,N) cin>>R[i];
    // for(int i=N-1;i>=0;i--) st[0].push(R[i]);
    rep(i,N) st[0].push(R[i]);
    ans.reserve(225001);
    now = N;

    while(1) {
        int t = st[st_id].top();
        // cout<<t<<endl;
        st[st_id].pop();

        if(t == now) {
            ans.pb(P(st_id+1,3));
            now--;
        }
        else {
            st[st_id^1].push(t);
            ans.pb(P(st_id+1,(st_id^1)+1));
        }
        if(st[st_id].empty()) {
            st_id ^= 1;
            if(st[st_id].empty()) {
                break;
            }
        }
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size()) {
        cout<<ans[i].fr<<" "<<ans[i].sc<<endl;
    }


    return 0;
}

