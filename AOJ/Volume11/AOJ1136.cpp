#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;

int n;
void rotation(vector<P>& vec) {
    rep(i,vec.size()) {
        int x = vec[i].first;
        int y = vec[i].second;
        vec[i].first = -y;
        vec[i].second = x;
    }

}
bool ok(vector<vector<P> >& vec,int index) {
    if(vec[0].size() != vec[index].size()) return false;
    bool ret = false;
    rep(i,4) {
        rotation(vec[index]);
        rep(j,2) {
            reverse(vec[index].begin(), vec[index].end());
            bool f = true;
            //sort(vec[index].begin(),vec[index].end());

            P diff;
            diff.first = vec[0][0].first - vec[index][0].first;
            diff.second = vec[0][0].second - vec[index][0].second;
            rep(j,vec[index].size()) {
                P tmp;
                tmp.first = vec[0][j].first - vec[index][j].first;
                tmp.second = vec[0][j].second - vec[index][j].second;
                if(tmp.first != diff.first) f = false;
                if(tmp.second != diff.second) f = false;
            }
            ret |= f;
        }
    }
    rep(i,vec[index].size()) {
        vec[index][i].first -= vec[index].back().first;
        vec[index][i].first -= vec[index].back().first;
    }

    rep(i,4) {
        rotation(vec[index]);
        rep(j,2) {
            reverse(vec[index].begin(), vec[index].end());
            bool f = true;
            //sort(vec[index].begin(),vec[index].end());

            P diff;
            diff.first = vec[0][0].first - vec[index][0].first;
            diff.second = vec[0][0].second - vec[index][0].second;
            rep(j,vec[index].size()) {
                P tmp;
                tmp.first = vec[0][j].first - vec[index][j].first;
                tmp.second = vec[0][j].second - vec[index][j].second;
                if(tmp.first != diff.first) f = false;
                if(tmp.second != diff.second) f = false;
            }
            ret |= f;
        }
    }
    return ret;

}
void solve() {
    vector<vector<P> > vec(n+1);
    rep(i,n+1) {
        int m;
        cin>>m;
        vec[i].resize(m);
        rep(j,m) {
            int x,y;
            cin>>x>>y;
            vec[i][j] = P(x,y);
        }
    }
    //sort(vec[0].begin(), vec[0].end());

    rep(i,n+1) {
        if(!i) continue;
        if(ok(vec,i)) {
            cout<<i<<endl;
        }
    }


}
int main() {
    while(cin>>n) {
        if(!n) return 0;
        solve();
        cout<<"+++++"<<endl;
    }

    return 0;
}
