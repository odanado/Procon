#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class Phrase {
    public:
    int s,l,p;
    Phrase(int s,int l,int p) {

        this->s = s;
        this->l = l;
        this->p = p;
    }
    Phrase() {
        s=l=p=-1;
    }

};

int n;
Phrase phra[400];
int m;
int w[400];
int dp[400];

int main() {

    cin>>n;
    rep(i,n) {
        int s,l,p;
        cin>>s>>l>>p;
        phra[i] = Phrase(s,l,p);
    }
    cin>>m;
    rep(i,m) cin>>w[i];
    rep(i,400) dp[i]=-1;
    dp[0]=0;

    rep(i,n) {
        for(int j=phra[i].s;j<=phra[i].l;j++) {
            for(int k=j;k<400;k++) {
                dp[k] = max(dp[k],dp[k-j]+phra[i].p);
            }
        }
    }

    vector<int> ans;
    bool flag = false;
    
    rep(i,m) {
        int t = dp[w[i]];
        if(t < 0) flag=true;
        else ans.push_back(t);
    }
    if(flag) {
        cout<<"-1"<<endl;
        return 0;
    }

    rep(i,ans.size()) cout<<ans[i]<<endl;

    return 0;
}

/* 2014/05/21 AC */
