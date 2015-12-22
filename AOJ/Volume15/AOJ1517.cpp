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
#include <array>

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

int n,m;
array<array<int, 20>,20> mat;

void rotate(int r1,int c1,int size) {
    array<array<int, 20>,20> tmp(mat);
    rep(i,size) rep(j,size) {
            //printf("%d %d -> %d %d\n",r1+i,c1+j,r1+j,c1+size-i-1);
            tmp[r1+j][c1+size-i-1]=mat[r1+i][c1+j];
    }

    mat=tmp;
}
/*
void rotate(int r1,int c1,int size) {
    array<array<int, 20>,20> tmp(mat);
    for(int c=c1;c<c1+size;c++) {
        array<int, 20> vec={};
        for(int r=r1;r<r1+size;r++) vec[r]=mat[r][c];
        reverse(vec.begin()+r1,vec.begin()+r1+size);
        //for(auto e:vec) cout<<e<<" ";
        //cout<<endl;
        for(int r=r1;r<r1+size;r++) tmp[c][r]=vec[r];
    }

    mat=tmp;
}
*/
void reversal(int r1,int c1,int size) {
    for(int r=r1;r<r1+size;r++) {
        for(int c=c1;c<c1+size;c++) mat[r][c]^=1;
    }
}
void left_shift(int r1) {
    int tmp=mat[r1][0];
    rep(c,n-1)  mat[r1][c]=mat[r1][c+1];
    mat[r1][n-1]=tmp;
}
void right_shift(int r1) {
    int tmp=mat[r1][n-1];
    for(int c=n-1;c>=1;c--) mat[r1][c]=mat[r1][c-1];
    mat[r1][0]=tmp;
}
void island_reversal(int r1,int c1) {
    int val=mat[r1][c1];
    mat[r1][c1]^=1;
    queue<P> que;
    que.push(P(r1,c1));
    while(que.size()) {
        P p=que.front(); que.pop();
        int r=p.fr;
        int c=p.sc;
        rep(i,4) {
            int nr=r+dy[i];
            int nc=c+dx[i];
            if(nr<0||nc<0) continue;
            if(nr>=n||nc>=n) continue;
            if(mat[nr][nc]!=val) continue;
            mat[nr][nc]^=1;
            que.push(P(nr,nc));
        }
    }
}
void dump() {
    rep(i,n) {
        rep(j,n) {
            cout<<mat[i][j];
            if(j+1==n) cout<<endl;
            else cout<<" ";
        }
    }
            
}
int main() {
    cin>>n>>m;
    rep(i,n) rep(j,n) cin>>mat[i][j];
    rep(i,m) {
        int op;
        cin>>op;
        if(op==0) {
            int r,c,size,ang;
            cin>>r>>c>>size>>ang;
            r--,c--;
            rep(i,ang/90) rotate(r,c,size);
        }
        if(op==1) {
            int r,c,size;
            cin>>r>>c>>size;
            r--,c--;
            reversal(r,c,size);
        }
        if(op==2) {
            int r;
            cin>>r;
            r--;
            left_shift(r);
        }
        if(op==3) {
            int r;
            cin>>r;
            r--;
            right_shift(r);
        }
        if(op==4) {
            int r,c,size;
            cin>>r>>c;
            r--,c--;
            island_reversal(r,c);
        }
    }
    dump();
    return 0;
}

