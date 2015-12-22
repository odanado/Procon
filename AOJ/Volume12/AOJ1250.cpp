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
typedef unsigned int uint;
#define rep(i,n) for(uint i=0;i<(n);i++)

uint f(uint bit,uint shift) {
    return ((bit>>shift)&1);
}

int main() {
    int N;
    cin>>N;
    while(N-->0) {
        uint a[9];
        uint sum,ans=0;
        rep(i,9) scanf("%x",a+i);
        rep(i,32) {
            sum=0;
            rep(j,8) sum+=a[j]^ans;
            ans |= (f(sum,i) != f(a[8],i))<<i;
        }
        printf("%x\n",ans);

    }
    return 0;
}

