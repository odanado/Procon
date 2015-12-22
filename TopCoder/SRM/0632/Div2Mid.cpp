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

class PotentialGeometricSequence {
    public:
        int numberOfSubsequences(vector <int> d) {
            int ans = d.size();
            for(int i=2;i<=d.size();i++) {
                for(int j=0;j<d.size();j++) {
                    int diff = d[j]-d[j+1];
                    bool f = i+j<=d.size();
                    for(int k=j;k<j+i-1;k++) {
                        f &= diff == d[k]-d[k+1];
                    }
                    if(f) ans++;
                    if(f) printf("%d,%d\n",i,j);
                }
            }

            return ans;
        }

};

int main() {
    return 0;
}

