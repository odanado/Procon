#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

int n,x,m;
int l[11],r[11],s[11];
bool flag=false;
int ans[11];

bool check(const int* values) {
    int s2[11]={};
    rep(i,m) {
        for(int j=l[i];j<=r[i];j++) {
            s2[i]+=values[j];
        }
        if(s[i]!=s2[i]) return false;
    }
    return true;
}

//何番目,部屋の状態
void dfs(int index, int* values) {
    //printf("[debug] %d,%d\n",index,0);
    if(index == n+1) {
        if(check(values)) {
            flag = true;
            for(int i=1;i<=n;i++) {
                ans[i] = values[i];
            }
        }
        return;
    }
    rep(i,x+1) {
        values[index+1] = i;
        dfs(index+1,values);
    }

}


int main() {
    cin>>n>>x>>m;
    rep(i,m) cin>>l[i]>>r[i]>>s[i];

    int values[7]={};
    dfs(0,values);

    if(!flag) cout<<"-1"<<endl;
    else {
        for(int i=1;i<=n;i++) {
            cout<<(i==1?"":" ")<<ans[i];
        }
        cout<<endl;
    }

    return 0;
}
