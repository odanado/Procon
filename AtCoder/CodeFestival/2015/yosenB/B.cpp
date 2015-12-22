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
    rep(i,N) B[A[i]]++;

    int ans,maxi=0;
    rep(i,N) {
        if(B[A[i]]>maxi) {
            maxi = B[A[i]];
            ans=A[i];
        }
    }
    if(maxi > N/2) {
        cout<<ans<<endl;
    }
    else cout<<"?"<<endl;

    return 0;
}

