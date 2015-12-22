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
int R,C,M;
int N;
int r[2][5050];
int c[2][5050];

int grid[55][55];

void view() {
    rep(i,R+1) {
        rep(j,C+1) {
            cout<<grid[i][j]<<" ";

        }
        cout<<endl;
    }

    cout<<endl;
}
void init() {
    rep(i,55) rep(j,55) grid[i][j]=0;
}
void rote(int a) {
    grid[r[0][a]][c[0][a]]++;
    grid[r[0][a]][c[1][a]+1]--;
    grid[r[1][a]+1][c[0][a]]--;
    grid[r[1][a]+1][c[1][a]+1]++;
}
void imos() {
    rep(i,R+1) {
        rep(j,C+1) {
            if(j!=0) grid[i][j]+=grid[i][j-1];
        }
    }
    rep(i,R+1) {
        if(i==0) continue;
        rep(j,C+1) {
            grid[i][j]+=grid[i-1][j];
        }
    }
}
int count() {
    int res = 0;
    rep(i,R) rep(j,C) if(grid[i][j]%4==0) res++;
    return res;
}
int main() {
    cin>>R>>C>>M;
    cin>>N;
    rep(i,N) cin>>r[0][i]>>r[1][i]>>c[0][i]>>c[1][i];
    rep(i,N) r[0][i]--,r[1][i]--,c[0][i]--,c[1][i]--;

    init();
    rep(i,N) {
        rep(j,N) {
            if(i==j) continue;
            rote(j);
        }
        imos();
        int c = count();
        if(M==c) {
            cout<<i+1<<endl;
        }
        init();
    }
    return 0;
}

