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

int T,N,M;
int A[102],B[102];
bool ok() {
    if(N<M) return false;
    int pos_a=0,pos_b=0;

    while(1) {
        if(pos_b==M) break;
        if(pos_a==N) return false;
        if(A[pos_a]<=B[pos_b]&&B[pos_b]<=A[pos_a]+T) {
            pos_b++;
        }
        pos_a++;
    }

    return true;
}

int main() {
    cin>>T;
    cin>>N;
    rep(i,N) cin>>A[i];
    cin>>M;
    rep(i,M) cin>>B[i];
    if(ok()) {
        cout<<"yes"<<endl;
    }
    else cout<<"no"<<endl;
    return 0;
}

