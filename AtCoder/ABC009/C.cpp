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

int N,K;
string S;
int func(int idx) {

    char c = S[idx];
    int ret=idx;
    for(int i=idx;i<S.size();i++) {
        if(S[i]<c) {
            c=S[i];
            ret=i;
        }
    }

    return ret;
}

int main() {
    cin>>N>>K;
    cin>>S;
    rep(i,K) {
        int a=func(i);
        swap(S[a],S[i]);
    }
    cout<<S<<endl;
    return 0;
}

