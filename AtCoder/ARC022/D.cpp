#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

struct circle {
    int x,y;
    double r;
    circle(int x,int y) {
        this->x=x;
        this->y=y;
        r=sqrt(x*x+y*y)+0.0000001;
    }
    circle() {

    }

};

int n;
circle  circ[100003];

void solve1() {
    long long ans=0;

    for(int x=-301;x<=301;x++) {
        for(int y=-301;y<=301;y++) {
            rep(i,n) {
                if((x-circ[i].x)*(x-circ[i].x)+(y-circ[i].y)*(y-circ[i].y)<=
                        circ[i].x*circ[i].x+circ[i].y*circ[i].y) {
                    ans++;
                    //printf("[debug] %d %d\n",x,y);
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}

void solve2() {
    long long ans=0;

    for(int x=-1000;x<=1000;x++) {
        for(int y=-1000;y<=1000;y++) {
            rep(i,n) {
                if(x*x+y*y<=circ[i].r*circ[i].r) {
                    ans++;
                    //printf("[debug] %d %d\n",x,y);
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main() {

    cin>>n;
    if(n>500) return 0;
    rep(i,n) {
        int x,y;
        cin>>x>>y;
        circ[i]=circle(x,y);
    }
    solve1();
    return 0;
}



