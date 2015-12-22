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

string grid[8];
bool is_A(int i,int j) {
    if(i+1>=8 || j+1>=8) return false;
    if(grid[i][j]=='0') return false;
    if(grid[i+1][j]=='0') return false;
    if(grid[i][j+1]=='0') return false;
    if(grid[i+1][j+1]=='0') return false;
    return true;

}
bool is_B(int i,int j) {
    if(i+3>=8) return false;
    if(grid[i][j]=='0') return false;
    if(grid[i+1][j]=='0') return false;
    if(grid[i+2][j]=='0') return false;
    if(grid[i+3][j]=='0') return false;
    return true;
}
bool is_C(int i,int j) {
    if(j+3>=8) return false;
    if(grid[i][j]=='0') return false;
    if(grid[i][j+1]=='0') return false;
    if(grid[i][j+2]=='0') return false;
    if(grid[i][j+3]=='0') return false;
    return true;
}
bool is_D(int i,int j) {
    if(i+2>=8||j-1<0) return false;
    if(grid[i][j]=='0') return false;
    if(grid[i+1][j]=='0') return false;
    if(grid[i+1][j-1]=='0') return false;
    if(grid[i+2][j-1]=='0') return false;
    return true;
}
bool is_E(int i,int j) {
    if(i+1>=8||j+2>=8) return false;
    if(grid[i][j]=='0') return false;
    if(grid[i][j+1]=='0') return false;
    if(grid[i+1][j+1]=='0') return false;
    if(grid[i+1][j+2]=='0') return false;
    return true;
}
bool is_F(int i,int j) {
    if(j+1>=8||i+2>=8) return false;
    if(grid[i][j]=='0') return false;
    if(grid[i+1][j]=='0') return false;
    if(grid[i+1][j+1]=='0') return false;
    if(grid[i+2][j+1]=='0') return false;
    return true;
}
bool is_G(int i,int j) {
    if(i+1>=8||j-2<0) return false;
    if(grid[i][j]=='0') return false;
    if(grid[i][j-1]=='0') return false;
    if(grid[i+1][j-1]=='0') return false;
    if(grid[i+1][j-2]=='0') return false;
    return true;
}
void solve() {
    rep(i,8) rep(j,8) {

        if(is_A(i,j)) {
            cout<<"A"<<endl;
            return;
        }
        if(is_B(i,j)) {
            cout<<"B"<<endl;
            return;
        }
        if(is_C(i,j)) {
            cout<<"C"<<endl;
            return;
        }
        if(is_D(i,j)) {
            cout<<"D"<<endl;
            return;
        }
        if(is_E(i,j)) {
            cout<<"E"<<endl;
            return;
        }
        if(is_F(i,j)) {
            cout<<"F"<<endl;
            return;
        }
        if(is_G(i,j)) {
            cout<<"G"<<endl;
            return;
        }
        if(is_B(i,j)) {
            cout<<"B"<<endl;
            return;
        }
        if(is_B(i,j)) {
            cout<<"B"<<endl;
            return;
        }
    }

    cout<<"hoge"<<endl;
}
int main() {
    while(cin>>grid[0]) {
        rep(i,7) cin>>grid[i+1];
        solve();

    }
    return 0;
}

