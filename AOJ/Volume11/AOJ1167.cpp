#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const int MAX = 250;
int dp1[1000006];
int dp2[1000006];
vector<int> pollock;
vector<int> pollock2;

int main() {
    rep(i,1000006) dp1[i] = dp2[i] = 10000000;
    rep(i,MAX){
        int t = i*(i+1)*(i+2)/6;
        if(t>1000006) break;
        pollock.push_back(t);
        if(t&1) pollock2.push_back(t);

    }
    rep(i,pollock.size()) {
        if(!i) continue;
        dp1[pollock[i]] = 1;
    }
    rep(i,pollock2.size()) {
        dp2[pollock2[i]] = 1;
    }
    rep(i,1000006) {
        rep(j,pollock.size()) {
            if(!j) continue;
            if(i+pollock[j]>1000006) continue;
            dp1[i+pollock[j]] = min(dp1[i+pollock[j]],dp1[i]+1);
        }
        rep(j,pollock2.size()) {
            if(i+pollock2[j]>1000006) continue;
            dp2[i+pollock2[j]] = min(dp2[i+pollock2[j]],dp2[i]+1);

        }
    }
    int n;
    while(cin>>n) {
        if(n==0) break;
        cout<<dp1[n]<<" "<<dp2[n]<<endl;

    }



    return 0;
}
