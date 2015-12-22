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

int n,m;



bool solve() {
    bool mat[21][21];
    int cnt=0;
    rep(i,21) rep(j,21) mat[i][j]=false;
    int x,y;
    rep(i,n) {
        cin>>x>>y;
        mat[x][y]=true;
    }

    x=10;
    y=10;
    
    cin>>m;

    rep(i,m) {
        char c;
        int d;
        cin>>c>>d;
        if(c == 'N') {
            while(d --> 0) {
                y++;
                if(mat[x][y]) {
                    cnt++;
                    mat[x][y]=false;
                }
            }
        }
        if(c == 'E') {
            while(d --> 0) {
                x++;
                if(mat[x][y]) {
                    cnt++;
                    mat[x][y]=false;
                }
            }
        }
        if(c == 'S') {
            while(d --> 0) {
                y--;
                if(mat[x][y]) {
                    cnt++;
                    mat[x][y]=false;
                }
            }
        }
        if(c == 'W') {
            while(d --> 0) {
                x--;
                if(mat[x][y]) {
                    cnt++;
                    mat[x][y]=false;
                }
            }
        }
    }

    return cnt == n;

}

int main()
{
    while(cin>>n) {
        if(!n) return 0;

        cout<<(solve()?"Yes":"No")<<endl;
    }
    
    
    return 0;
}


