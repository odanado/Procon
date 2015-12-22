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

class XorSequenceEasy {
public:
    int bitcount(int S) {
        int res=0;
        while(S) {
            if(S&1) res++;
            S>>=1;
        }
        return res;
    }
    int getmax(vector <int> A, int N) {
        int t = bitcount(N-1);
        int ary[32][2];
        rep(i,32) rep(j,2) ary[i][j]=0;
        rep(i,A.size()) for(int j=i+1;j<A.size();j++) {
            for(int bit=t-1;bit>=0;bit--) {
                if(((A[i]>>bit)&1) != ((A[j]>>bit)&1)) {
                    ary[bit][(A[i]>>bit)&1]++;
                    break;
                }
            }
        }
        int ans=0;
        rep(i,32) ans+=max(ary[i][0],ary[i][1]);
        return ans;

    }
};

