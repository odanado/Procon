#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

int N,Q;

vector<pair<int,string> > vec;

int main() {
    cin>>N>>Q;
    rep(i,N) {
        int val;
        string ss;
        cin>>val>>ss;
        vec.push_back(make_pair(val,ss));
    }
    vec.push_back(make_pair(0,"kogakubu10gokan"));
    sort(vec.begin(),vec.end());

    rep(i,N) {
        if(vec[i].first <= Q && Q < vec[i+1].first) {
            cout<<vec[i].second<<endl;
            return 0;
        }
    }
    cout<<vec[N].second<<endl;
    return 0;
}
