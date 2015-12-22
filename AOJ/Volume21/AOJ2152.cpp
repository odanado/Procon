#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>
#include <tuple>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

struct Data{
    int l,r,id;

    bool operator<(const Data &rhs) const  {
        return tie(l,r) < tie(rhs.l,rhs.r);
    }
};

int n;
void insert(list<Data> &range, int id,int cnt) {
    if(range.size()==0) {
        range.push_front({0,cnt,id});
        return;
    }
    if(range.size()==1) {
        if(range.begin()->l==0) {
            range.push_back({range.begin()->r,range.begin()->r+cnt,id});
            return;
        }
        else {
            int t=range.begin()->l;
            range.push_front({0,t,id});
            cnt-=t;
            if(cnt<=0) return;
        }
    }
    auto it=range.begin();
    auto prev=it;
    it++;
    while(it!=range.end()) {
        if(prev->r!=it->l) {
            int t=it->l-prev->r;
            t=min(cnt,t);
            range.insert(it,{prev->l,prev->l+t,id});
            
            cnt-=t;
        }
        if(cnt<=0) return;
        prev=it;
        it++;
    }

    it--;
    range.push_back({it->r,it->r+cnt,id});
    
}
template<class T>
void dump(T range) {
    for(auto &e : range) {
        cout<<e.l<<","<<e.r<<" : "<<e.id<<endl;
    }
}
void solve() {
    list<Data> range;
    set<int> delete_set;
    rep(i,n) {
        char c;
        int a,b;
        cin>>c;
        if(c=='W') {
            cin>>a>>b;
            insert(range,a,b);
        }
        else if(c=='D') {
            cin>>a;

            auto it=range.begin();
            while(it!=range.end()) {
                if(it->id==a) it=range.erase(it);
                else it++;
            }
        }
        else {
            cin>>a;
            bool ok=false;
            for(auto &e : range) {
                if(e.l<=a&&a<e.r) {
                    ok=true;
                    cout<<e.id<<endl;
                }
            }
            if(!ok) cout<<"-1"<<endl;
        }
    }
}
int main() {
    while(cin>>n) {
        if(!n) break;
        solve();
        cout<<endl;
    }
    return 0;
}

