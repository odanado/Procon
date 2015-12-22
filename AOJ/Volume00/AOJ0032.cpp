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

int main() {
    int a[3];
    int cnt1=0,cnt2=0;
    while(~scanf("%d,%d,%d",&a[0],&a[1],&a[2])) {
        if(a[2]*a[2]==a[0]*a[0]+a[1]*a[1]) cnt1++;
        if(a[0] == a[1] ) cnt2++;
    }
    cout<<cnt1<<endl;
    cout<<cnt2<<endl;
    return 0;
}

