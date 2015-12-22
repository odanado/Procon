#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int N,M;

int ans=0;
vector<int> result;
vector<int> amida(const vector<int>& vec) {
    vector<int> ret;
    rep(i,N) ret.push_back(i+1);
    rep(i,vec.size()) {
        swap(ret[vec[i]-1],ret[vec[i]]);
    }

    return ret;
}

bool check(const vector<int>& vec1,const vector<int>& vec2) {
    if(vec1.size()!=vec2.size()) return false;
    rep(i,vec1.size()) if(vec1[i]!=vec2[i]) return false;
    return true;
}
int cnt(const vector<int>& vec) {
    int ret=1;
    int prev=0;
    rep(i,vec.size()) {
        if(!i) continue;
        for(int j=prev;j<i;j++) {
            if(abs(vec[i]-vec[j])<=1){
                ret++;
                prev=i;
                break;
            }
        }
    }
                    
    return ret;

}

int main() {
    cin>>N>>M;
    vector<int> yoko;
    yoko.resize(M);
    rep(i,M) {
        int a; cin>>a;
        yoko[i]=a;
    }
    result = amida(yoko);
    sort(yoko.begin(), yoko.end());
    ans=M;

    do {
        vector<int> t = amida(yoko);

        //cout<<t.size()<<" : "<<endl;
        //rep(i,t.size()) cout<<t[i]<<" ";
        //cout<<endl;

        if(check(result,t)) {
            /*
            cout<<"find : ";
            rep(i,yoko.size()) cout<<yoko[i]<<" ";
            cout<<endl;
            cout<<cnt(yoko)<<endl;
            */
            ans=min(ans,cnt(yoko));
        }

    } while(next_permutation(yoko.begin(), yoko.end()));
    cout<<ans<<endl;


    return 0;
}
