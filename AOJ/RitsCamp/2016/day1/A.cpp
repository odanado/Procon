#include <vector>
#include <map>
#include <iostream>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using ll = long long;
using P = pair<int,int>;
int L,N;
ll w[31],x[31];
vector<P> ans;
int main() {
    cin>>L>>N;
    rep(i,N) cin>>x[i]>>w[i];

    ll sum=0;
    rep(i,N) sum+=x[i]*w[i];

    int t=1;
    if(sum>0) t=-1;
    sum=abs(sum);

    while(sum>L) {
        sum-=L;
        ans.push_back(P(1,t*L));
    }

    ans.push_back(P(1,t*sum));
    cout<<ans.size()<<endl;
    rep(i,ans.size()) cout<<ans[i].second<<" "<<ans[i].first<<endl;
    

    return 0;
}
