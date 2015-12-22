#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

const int MAX = 1299809;
bool is_prime[MAX];
int n;


void solve() {
    int ans=0;
    int m=n;
    while(!is_prime[m]) {
        m--;
        ans++;
    }
    while(!is_prime[n]) {
        n++;
        ans++;
    }
    cout<<ans<<endl;
}

int main() {
    fill(is_prime,is_prime+MAX,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<MAX;i++) {
        if(is_prime[i]) for(int j=i+i;j<MAX;j+=i) is_prime[j]=false;
    }

    while(cin>>n) {
        if(!n) return 0;
        solve();
    }

    return 0;
}
