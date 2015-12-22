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

int n;
int A[100003];

int main() {
    cin>>n;
    rep(i,n) cin>>A[i];
    int ans=0;
    queue<int> que;
    set<int> S;
    rep(i,n) {
        //cout<<A[i]<<endl;
        if(S.find(A[i])==S.end()) {
            que.push(A[i]);
            S.insert(A[i]);
        }
        else {
            while(true) {
                int p = que.front(); que.pop();
                S.erase(p);
                if(p==A[i]) break;
            }
            que.push(A[i]);
            S.insert(A[i]);

        }
        ans=max(ans,(int)que.size());

    }
    cout<<ans<<endl;


    return 0;
}


/* 2014/05/03 AC */

