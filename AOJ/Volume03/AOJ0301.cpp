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

set<int> S;
int N,M,Q;

set<int>::iterator next_it(set<int>::iterator it) {
    ++it;
    if(it==S.end()) it=S.begin();
    return it;
}
set<int>::iterator prev_it(set<int>::iterator it) {
    if(it==S.begin()) it=S.end();
    --it;
    return it;
}

int main() {
    cin>>N>>M>>Q;
    rep(i,N) S.insert(i);
    set<int>::iterator it = S.begin();

    while(M-->0) {
        int a;
        cin>>a;
        if(a%2==0) rep(i,a) it=next_it(it);
        else rep(i,a) it=prev_it(it);

        it= S.erase(it);
        if(it==S.end()) it=S.begin();
    }

    while(Q-->0) {
        int q;
        cin>>q;
        if(S.find(q)==S.end()) cout<<"0"<<endl;
        else cout<<"1"<<endl;

    }


    return 0;
}

