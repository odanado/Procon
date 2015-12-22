#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

int n,T;
int r2;
long long ans=0;
string ss;

bool dfs(int index) {
    if(index == ss.size()) return true;
    int r = 0;
    if(ss[index] == 'n') {
        r = ss[index+2]-'0';
        if((n!=1&&r>9) || r2*r > 9) return false;
        
        ans += pow(n,r);
        if(ans > 1000000000) return false;
    }

    return dfs(index+1);
}

int main() {
    cin>>n>>T;
    cin>>ss;
    r2 = log10(n);

    if(dfs(0)) {
        if(log10(T) > 10.0 || log10(T) + log10(ans) > 10.0) cout<<"TLE"<<endl;
        else {
            if(ans*T>1000000000) cout<<"TLE"<<endl;
            else cout<<ans*T<<endl;
        }
    }
    else {
        cout<<"TLE"<<endl;
    }

    return 0;
}
