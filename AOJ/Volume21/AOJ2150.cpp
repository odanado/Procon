#include<iostream>
#include<algorithm>
#include<vector>

#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

bool is_prime[200010];
int n,p;

void init() {
    rep(i,200010) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<200010;i++) {
        if(is_prime[i]) for(int j=i+i;j<200010;j+=i) is_prime[j]=false;
    }
}

int next_prime(int m) {
    m++;
    while(true) {
        if(is_prime[m]) break;
        m++;
    }
    
    return m;
}

void solve() {
    vector<int> vec,ans;
    int t = n;
    for(int i=0;i<p;i++) {
        t = next_prime(t);
        vec.push_back(t);
        
    }
    for(int i=0;i<p;i++)  for(int j=i;j<p;j++) {
        ans.push_back(vec[i]+vec[j]);

    }
    sort(ans.begin(),ans.end());
    cout<<ans[p-1]<<endl;

}
int main() {
    init();

    while(cin>>n>>p) {
        if(n==-1 && p==-1) return 0;
        solve();
    }
}

/* 2014/05/25 AC */
