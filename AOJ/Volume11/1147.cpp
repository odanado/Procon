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
int solve() {
    int max;
    int min;
    int s;
    cin>>s;
    int sum=s;
    max=min=s;
    rep(i,n-1) {
        cin>>s;
        sum+=s;
        max=std::max(max,s);
        min=std::min(min,s);
    }

    sum-=max;
    sum-=min;

    return sum/(n-2);

}

int main() {
    while(cin>>n) {

        if(!n) return 0;

        cout<<solve()<<endl;

    }
    return 0;
}



