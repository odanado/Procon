#include<iostream>
#include<map>
#include<cmath>

#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int n;
int a,b,c,d;
int f(int w) {
    char ary[103][103]={};
    pair<int,int> P['Z'];

    rep(i,103) rep(j,w) {
        int t = i*w+j;
        if(t==a) P['A'] = pair<int,int>(i,j);
        if(t==b) P['B'] = pair<int,int>(i,j);
        if(t==c) P['C'] = pair<int,int>(i,j);
        if(t==d) P['D'] = pair<int,int>(i,j);
    }

    int res = 0;
    res += abs(P['A'].first - P['B'].first);
    res += abs(P['A'].second - P['B'].second);
    res += abs(P['C'].first - P['D'].first);
    res += abs(P['C'].second - P['D'].second);

    return res;
}
int main() {
    cin>>n;
    cin>>a>>b>>c>>d;
    a--;
    b--;
    c--;
    d--;

    int ans=1000000;

    for(int i=1;i<=n;i++) {
        ans=min(ans,f(i));
    }
    
    cout<<ans<<endl;


    return 0;
}

/* 2014/05/21 AC */
