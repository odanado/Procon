#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int N;

class Q {
    public:
    int a,b;
    Q (int a,int b) :
        a(a),b(b) {
        };

    bool operator >(const Q &q) const {
        return a*q.b < b*q.a;
    }
    bool operator <(const Q &q) const {
        return a*q.b > b*q.a;
    }
    bool operator ==(const Q &q) const {
        return a*q.b == b*q.a;
    }


};

void solve() {
    vector<string> L(N);
    vector<pair<Q,string> > ans;
    rep(i,N) {
        string ss;
        int p,a,b,c,d,e,f,s,m;
        cin>>ss>>p>>a>>b>>c>>d>>e>>f>>s>>m;
        int mm = a+b+c;
        mm += (d+e)*m;
        int pp = f*s;
        pp = pp*m-p;
        Q q(pp,mm);
        ans.push_back(make_pair(q, ss));
    }
    sort(ans.begin(), ans.end());
    rep(i,ans.size()) {
        cout<<ans[i].second<<endl;
    }
}
int main() {
    while(cin>>N) {
        if(!N) return 0;
        solve();
        cout<<"#"<<endl;
    }

    return 0;
}
