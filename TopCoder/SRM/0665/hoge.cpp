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
    int construct(int a) {
        int i,t;char s[5];
        for(i=a+1;i<=100;i++) {
            t=a^i;
            sprintf(s,"%d",t);
            int ok=0;
            for(int j=0;j<strlen(s);j++) 
                if(s[j]=='4'||s[j]=='7') ok=1;
            else {
                ok=0;
                break;
            }
            if(ok) return i;
        }

        return -1;
    }
};

int main() {
    LuckyXor obj;
    int a;cin>>a;
    cout<<obj.construct(a)<<endl;
    return 0;
}

