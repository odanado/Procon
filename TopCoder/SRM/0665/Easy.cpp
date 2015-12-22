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

class LuckyXor {
public:
    bool is_lucky(int n) {
        while(n) {
            int t=n%10;
            if(t!=7&&t!=4) return false;
            n/=10;
        }

        return true;
    }
    int construct(int a) {
        for(int i=a+1;i<=100;i++) {
            if(is_lucky(a^i)) return i;
        }
        return -1;
    }
};

int main() {
    int a;
    cin>>a;
    LuckyXor obj;
    cout<<obj.construct(a)<<endl;
    return 0;
}

