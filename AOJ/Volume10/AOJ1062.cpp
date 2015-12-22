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

int n;
bool ok(int a,int b,int c) {
    int s1=a*60+b;
    int s2;
    if(b<c) {
        s2=a*60+c;
    }
    else {
        s2=a*60+c;
        s2+=60;
    }
    return s2-s1<=8;
}
int f(int a,int b,int c) {
    int s1=a*60+b;
    if(11*60<=s1&&s1<=14*60+59) return 0;
    if(18*60<=s1&&s1<=20*60+59) return 1;
    if(21*60<=s1&&s1<=25*60+59) return 2;
    return 3;
}
void solve() {
    int cnt1[3]={},cnt2[3]={};
    int a,b,c;
    rep(i,n) {
        scanf("%d:%d %d",&a, &b, &c);
        if(a<3) a+=24;
        int t=f(a,b,c);
        if(t!=3) cnt1[t]++;
        if(ok(a,b,c)&&t!=3) cnt2[t]++;
    }
    string times[3]={"lunch","dinner","midnight"};
    rep(i,3) {
        if(cnt1[i]==0) {
            printf("%s no guest\n",times[i].c_str());
        }
        else {
            printf("%s %d\n",times[i].c_str(),100*cnt2[i]/cnt1[i]);
        }
    }

}
int main() {
    while(cin>>n) {
        if(n==0) break;
        solve();
    }

    return 0;
}

