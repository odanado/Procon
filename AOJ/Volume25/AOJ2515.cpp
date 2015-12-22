#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int N,T;
vector<pair<string,int> > ans;
inline int conv(int hh,int mm) {
    return hh*60+mm;
}
int main() {
    cin>>N>>T;
    int hh1,mm1,hh2,mm2;

    string st_name,ar_name;
    scanf("%d:%d",&hh1,&mm1);
    cin>>st_name;
    rep(i,N-1) {
        scanf("%d:%d",&hh1,&mm1);
        cin>>st_name;

        scanf("%d:%d",&hh2,&mm2);
        cin>>ar_name;

        int t = conv(hh2,mm2)-conv(hh1,mm1);
        if(t>=T) {
            ans.push_back(make_pair(st_name,t));
        }
    }
    scanf("%d:%d",&mm1,&hh1);
    cin>>st_name;

    cout<<ans.size()<<endl;
    rep(i,ans.size()) {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }


    return 0;
}
