#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

int D;
int x;
int y;

//i 個マークしたときの点数
int dp[23];
vector<pair<int,int> > vec;

int main() {
    cin>>D;
    cin>>x;
    rep(i,x) {
        string a;
        int p;
        cin>>a>>p;
        if(a=="D") vec.push_back(make_pair(p,0));
    }

    cin>>y;
    rep(i,y) {
        string a;
        int p;
        cin>>a>>p;
        if(a=="DD") vec.push_back(make_pair(p,1));
    }

    rep(i,vec.size()) {
        for(int j=D-1;j>=0;j--) {
            if(vec[i].second) {
                dp[j+2] = max(dp[j+2],dp[j] + vec[i].first);
            }
            else {
                dp[j+1] = max(dp[j+1],dp[j] + vec[i].first);
            }

        }
    }
    int ans=0;
    ans=*max_element(dp,dp+D+1);
    cout<<ans<<endl;


    return 0;
}

/* 2014/05/28 AC */
