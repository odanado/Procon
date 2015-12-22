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

class Similars {
public:
    bool ok(int n,int L,int R) {
        int m=n;
        vector<int> vec;
        while(n) {
            vec.pb(n%10);
            n/=10;
        }

        do {
            int a=1;
            int s=0;
            rep(i,vec.size()) {
                s+=vec[i]*a;
                a*=10;
            }
            printf("%d -> %d\n",m,s);
            if(m!=s&&L<=s&&s<=R) return true;
        }while(next_permutation(all(vec)));

        return false;
    }
    int maxsim(int L, int R) {
        for(int i=Li<=R;i++) {
            ans=max(ans,log10(i));
            if(ok(i,L,R)) ans=max(ans,(int)(log10(i))+1);
        }
        return ans;
    }

};

int main() {
    return 0;
}

