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
int A[100005];
int main() {
    vector<int> ans;
    cin>>N;
    rep(i,N-1) cin>>A[i];
    ans.pb(A[0]);
    rep(i,N-1) {
        //printf("debug: %d %d %d\n",i,A[i],ans.back());
        if(ans.back()<=A[i]) {
            ans.pb(A[i]);
        }
        else {
            ans.back()=A[i];
            ans.pb(A[i]);
        }
    }
    rep(i,ans.size()) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}

