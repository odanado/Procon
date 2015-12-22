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

class RunningAroundPark {
    public:
        int numberOfLap(int N, vector <int> d) {
            int n=N;
            if(d.size()==1) return 1;
            int ans = 1;
            int prev = d[0];
            for(int i=1;i<d.size();i++) {
                if(prev>=d[i]) ans++;
                prev=d[i];
            }
            return ans;

        }

};

int main() {
    return 0;
}

