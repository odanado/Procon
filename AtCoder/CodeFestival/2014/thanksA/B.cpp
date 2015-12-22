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
int A[3];
int main() {
    cin>>N;
    cin>>A[0]>>A[1]>>A[2];
    int sum =0;
    int ans =0;
    int count=0;
    rep(i,3) A[i]=-A[i];
    sort(A,A+3);
    rep(i,3) A[i]=-A[i];

    while(1) {
        sum+=A[count];
        ans++;
        count++;
        count%=3;
        if(sum >= N) break;
    }
    cout<<ans<<endl;
    return 0;
}

