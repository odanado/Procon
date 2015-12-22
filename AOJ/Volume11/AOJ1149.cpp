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

struct Cake {
    int w,d;
    int p;
    Cake(int w=0,int d=0,int p=0) : w(w),d(d),p(p) {}
    bool operator<(const Cake &obj) const {
        if(this->p!=obj.p) return this->p<obj.p;
        else return this->w*this->d<obj.w*obj.d;
    }
    bool operator==(const Cake &obj) const {
        return this->p==obj.p;
    }
};

int n,w,d;
vector<Cake> cakes;

void solve() {
    int turn=0;
    cakes.clear();
    cakes.pb(Cake(w,d,1));

    while(n--) {
        turn++;
        int p,s;
        int cnt=0;
        cin>>p>>s;
        p--;
        // printf("[input] %d %d\n",p,s);
        Cake cake = cakes[p];
        // printf("[debug]%d : %d %d %d %d\n",n,cakes.size(),cake.w,cake.d,cake.p);
       
        cakes.erase(cakes.begin()+p);
        while(s>0) {
            if(cnt%2==0) s-=cake.w;
            else s-=cake.d;
            cnt++;
        }
        // cout<<cnt<<endl;
        s=abs(s);
        if(cnt%2==1) {
            int w1=cake.w-s;
            int w2=s;
            w1=abs(w1);
            if(w2<w1) swap(w1,w2);

            cakes.pb(Cake(w1,cake.d,turn));
            cakes.pb(Cake(w2,cake.d,turn));
        }
        else {
            int d1=cake.d-s;
            int d2=s;
            d1=abs(d1);
            if(d2<d1) swap(d1,d2);

            cakes.pb(Cake(cake.w,d1,turn));
            cakes.pb(Cake(cake.w,d2,turn));
        }
        sort(all(cakes));
    }
    vector<int> ans;
    ans.reserve(cakes.size());
    for(auto &cake : cakes) {
        ans.pb(cake.w*cake.d);
    }
    sort(all(ans));
    rep(i,ans.size()) {
        cout<<(i==0?"":" ")<<ans[i];
    }
    cout<<endl;
}

int main() {
    while(cin>>n>>w>>d) {
        if(n+w+d==0) break;
        solve();
    }
    return 0;
}

