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

int a,b,c;
int main() {
    cin>>a>>b>>c;
    int t=0;
    int ans=0;

    while(1) {
        rep(i,a) {
            t++;
            ans++;
            t%=60;
            if(t==c) {
                cout<<ans<<endl;
                return 0;
            }
        }
        t+=b;
        ans+=b;
        t%=60;
        if(t==0) {
            cout<<"-1"<<endl;
            return 0;
        }
    }



    return 0;
}

