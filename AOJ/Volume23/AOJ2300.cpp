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

struct Lab {
    double l,a,b;
    Lab(double l=0,double a=0,double b=0) :
        l(l),a(a),b(b) { }
};
double pow2(double a) {
    return a*a;
}
double func(const Lab& lab1,const Lab& lab2) {
    double res = 0;
    res += pow2(lab1.l-lab2.l);
    res += pow2(lab1.a-lab2.a);
    res += pow2(lab1.b-lab2.b);
    return res;
}

int bitcount(int S) {
    int res = 0;
    rep(i,32) if((S>>i)&1) res++;
    return res;
}

Lab lab[22];
int N,M;

int main() {
    cin>>N>>M;
    rep(i,N) {
        double l,a,b;
        cin>>l>>a>>b;
        lab[i].l=l;
        lab[i].a=a;
        lab[i].b=b;
    }
    double ans = 0;
    rep(S,1<<N) {
        double tmp=0;
        if(bitcount(S)!=M) continue;
        rep(i,N) for(int j=i+1;j<N;j++) {
            if(((S>>i)&1) && ((S>>j)&1)) {
                tmp += func(lab[i],lab[j]);
            }
        }
        ans=max(ans,tmp);
    }

    printf("%.6f\n", ans);
    return 0;
}

