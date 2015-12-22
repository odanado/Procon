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
int a[100005];
set<ll> S;
int main() {
    cin>>N;
    rep(i,N) cin>>a[i];
    rep(i,N) while(a[i]%2==0) a[i]/=2;
    rep(i,N) S.insert(a[i]);

    rep(i,N) {
        S.erase(2*a[i]);
    }

    cout<<S.size()<<endl;


    return 0;
}

