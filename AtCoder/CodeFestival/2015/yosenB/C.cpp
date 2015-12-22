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

int N,M;
int A[100005];
int B[100005];
int main() {
    cin>>N>>M;
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];
    sort(A,A+N);
    sort(B,B+M);
    reverse(A,A+N);
    reverse(B,B+M);

    if(N<M) {
        cout<<"NO"<<endl;
        return 0;
    }
    int pos=0;
    rep(i,M) {
        while(1) {
            if(B[i]<=A[pos++]) {
                break;
            }
            if(pos==N) {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;

    return 0;
}

