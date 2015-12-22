#include<iostream>
#include<map>
#include<algorithm>

using namespace std;
int n,m,a;

void solve() {
    int ary[1003];
    for(int i=0;i<=n;i++) ary[i]=i;
    pair<int,pair<int,int> > amida[1003];
    for(int i=0;i<m;i++) {
        int h,p,q;
        cin>>h>>p>>q;
        amida[i]=(make_pair(h,pair<int,int>(p,q)));
    }

    sort(amida,amida+m);
    for(int i=0;i<m;i++) {
        swap(ary[amida[i].second.first],ary[amida[i].second.second]);
    }
    cout<<ary[a]<<endl;



}

int main() {
    while(cin>>n>>m>>a) {
        if(n+m+a==0) return 0;
        solve();
    }

    return 0;
}

/* 2014/05/16 */

