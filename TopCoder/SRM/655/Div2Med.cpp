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

struct FoldingPaper2{
public:
    int solve(int W, int H, int A) {
        vector<P> vec;
        rep(i,A) if(i&&A%i==0) vec.pb(i,A/i);
        rep(i,vec.size()) {
            P p=vec[i];
            if(p.fr<=W&&p.sc<=H) return 1;
            if(p.fr<=H&&p.sc<=W) return 1;
        }

        return 0;
    }
};

int main() {
    return 0;
}

