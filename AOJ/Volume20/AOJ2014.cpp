#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int w,h;
vector<string> ss;
bool is_white[103][103];
bool is_black[103][103];

void dfs(int x_,int y_,bool (*f_)[103],bool f2) {
    //cout<<x_<<","<<y_<<endl;
    if(f_[x_][y_]||(ss[x_][y_]!='.'&&f2)) return;
    f_[x_][y_]=true;
    rep(i,4) {
        int x = x_ + dx[i];
        int y = y_ + dy[i];
        if(0<=x&&x<ss.size() && 0<=y&&y<ss[x].size()) {
            dfs(x,y,f_,true);
        }
    }
}

void solve() {
    rep(i,103) rep(j,103) is_white[i][j]=is_black[i][j]=false;
    ss.resize(h);
    rep(i,h) {
        string t; cin>>t;
        ss[i]=t;
    }
    int ans_b=0,ans_w=0;
    rep(i,ss.size()) {
        rep(j,ss[i].size()) {
            if(ss[i][j]=='B') dfs(i,j,is_black,false);
            if(ss[i][j]=='W') dfs(i,j,is_white,false);
        }
    }
    rep(i,ss.size()) rep(j,ss[i].size()) {
        //cout<<i<<","<<j<<":"<<is_white[i][j]<<","<<is_black[i][j]<<ss[i][j]<<endl;
        if(ss[i][j]=='.'&&(is_white[i][j]^is_black[i][j])) {
           if(is_white[i][j]) ans_w++;
           else ans_b++; 
        }
    }
    cout<<ans_b<<" "<<ans_w<<endl;
    ss.clear();
}

int main() {
    while(cin>>w>>h) {
        if(w+h==0) return 0;
        solve();
    }

    return 0;
}
