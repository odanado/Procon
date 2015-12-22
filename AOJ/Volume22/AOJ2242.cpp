#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int N,Q;

struct Data {
    int a,b;
    string ss;
    Data() {};
    Data(int a,int b,string ss) :
        a(a),b(b),ss(ss) {};

    bool operator<(const Data& data_) const {
        return (data_.b) > (b);
    }
    bool operator<(const int& val) const {
        return val > b;
    }
};

void solve() {
    Data data[1003];

    rep(i,N) {
        int a,b;
        string ss;
        cin>>ss>>a>>b;

        data[i] = Data(a,b,ss);
    }
    sort(data,data+N);

    rep(i,Q) {
        int a;
        cin>>a;
        int pos = lower_bound(data,data+N, a) - data;
        if(pos ==N) {
            cout<<"Unknown"<<endl;
            continue;
        }
        int t = a - (data[pos].b-data[pos].a);
        if(t <= 0) {
            cout<<"Unknown"<<endl;
            continue;
        }
        cout<<data[pos].ss<<" "<<t<<endl;


        
        
    }


}

int main() {
    while(cin>>N>>Q) {
        if(N+Q==0) return 0;
        solve();
    }

    return 0;
}
