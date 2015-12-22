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

class TheNicePair {
public:
    int func(const vector<int>& A,int v) {
        int ret=0;
        rep(i,A.size()) rep(j,A.size()) if(i<j) {
            int cnt=0;
            for(int k=i;k<j;k++) if(A[k]%v==0) cnt++;
            if((j-i)/2<cnt) ret=max(ret,j-i);
        }

        return ret;
    }
    int solve(vector <int> A) {
        int maxi = *max_element(all(A));
        int ans=0;
        rep(v,maxi+1) {
            if(v==0||v==1) continue;
            ans=max(ans,func(A,v));
        }
        if(ans==0) ans=-1;
        return ans;
    }
};

int main() {
    return 0;
}

