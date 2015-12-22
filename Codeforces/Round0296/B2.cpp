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

int dist(string s1,string s2) {
    int res=0;
    rep(i,s1.size()) if(s1[i]!=s2[i]) res++;
    return res;
}
int n;
string s,t;
int main() {
    cin>>n>>s>>t;
    int ans=dist(s,t);
    P p(-1,-1);
    rep(i,n) rep(j,n) if(i!=j){
        swap(s[i],s[j]);

        int a=dist(s,t);
        if(a<ans) {
            ans=a;
            p=P(i+1,j+1);
        }

        swap(s[i],s[j]);
    }

    cout<<ans<<endl;
    cout<<p.fr<<" "<<p.sc<<endl;
    return 0;
}

