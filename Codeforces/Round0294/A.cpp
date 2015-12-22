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

string board[8];

int main() {
    int w,b;
    w=b=0;
    rep(i,8) cin>>board[i];

    rep(i,8) rep(j,8) {
        char c=board[i][j];
        if(c=='Q') w+=9;
        if(c=='R') w+=5;
        if(c=='B') w+=3;
        if(c=='N') w+=3;
        if(c=='P') w+=1;
        if(c=='q') b+=9;
        if(c=='r') b+=5;
        if(c=='b') b+=3;
        if(c=='n') b+=3;
        if(c=='p') b+=1;
    }
    if(w==b) cout<<"Draw"<<endl;
    else if(b<w) cout<<"White"<<endl;
    else cout<<"Black"<<endl;

    return 0;
}

