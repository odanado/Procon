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

int L,H;
int N;
int main() {
    cin>>L>>H;
    cin>>N;
    rep(i,N) {
        int A;
        cin>>A;
        if(A<L) {
            cout<<L-A<<endl;
        }
        else if(L<=A&&A<=H) {
            cout<<"0"<<endl;
        }
        else cout<<"-1"<<endl;

    }
    return 0;
}

