#include <string>
#include <iostream>
#include <vector>

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

int N;
vector<string> S;
bool ok() {
    bool ret=true;
    rep(y,N) rep(x,N) if(S[y][x]!='o') {
        ret=false;
    }
    return ret;
}
void show() {
    rep(y,N) {
        rep(x,N) {
            cout<<S[y][x]<<" ";
        }
        cout<<endl;
    }
}
void fill(int y,int x1,int x2) {
    for(int x=x1;x<x2&&x<N;x++) {
        if(x<0) while(1) {}
        S[y][x]='o';
    }
}
int main() {
    int ans=0;
    cin>>N;
    S.resize(N);
    rep(i,N) cin>>S[i];

    rep(y,N) for(int x=N-1;x>=0;x--) if(S[y][x]=='.') {
        //printf("[debug] %d %d\n",y,x);
        int x1=x;
        //while(0<=x-1 && S[y][x-1]=='.') x--;
        ans++;
        fill(y,0,x+1);
        if(y!=N-1) fill(y+1,x1,N);

        //show();
        //cout<<endl;

        if(ok()) {
            goto end;
        }
    }

end:;
    cout<<ans<<endl;

    return 0;
}

