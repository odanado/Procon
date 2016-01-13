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

double dist(P a, P b){
    return sqrt((a.fr-b.fr)*(a.fr-b.fr)+(a.sc-b.sc)*(a.sc-b.sc));
}
P a,b;
int T,V;
int n;
P p[1003];

int main() {
    cin>>a.fr>>a.sc;
    cin>>b.fr>>b.sc;
    cin>>T>>V;
    cin>>n;
    rep(i,n) cin>>p[i].fr>>p[i].sc;
    bool f=false;
    rep(i,n) {
        double d=dist(a,p[i])+dist(p[i],b);
        //printf("%.8f\n",d);
        f|=d<=T*V;
    }
    if(f) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

