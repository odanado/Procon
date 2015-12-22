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

int to_minite(int w,int t) {
    int h=t/100;
    int m=t%100;

    return (w*1440+h*60+m);
}

int N;
int solve() {
    map<string,int> animes;
    vector<pair<int,string>> animes2;
    map<int,string> range;
    bool ok=true;
    rep(i,N) {
        string name;
        int w,t;
        cin>>name>>w>>t;
        int m=to_minite(w,t);
        //cout<<m<<endl;
        animes[name]=m;
        animes2.pb(mp(m,name));
    }
    int m; cin>>m;
    set<string> ans;
    rep(i,m) {
        string s; cin>>s;
        int m=animes[s];
        rep(i,30) {
            if(range.count(i+m)) ok=false;;
            range[i+m]=s;
        }
        ans.insert(s);
    }
    sort(all(animes2));
    for(const auto &anime : animes2) {
        string s=anime.second;
        int m=anime.first;
        bool f=true;
        rep(i,30) f&=!range.count(m+i);
        if(f) {
            ans.insert(s);
            rep(i,30) {
                range[i+m]=s;
            }
        }
    }

    if(!ok) return -1;
    return ans.size();
}
int main() {
    while(cin>>N) {
        if(!N) break;
        cout<<solve()<<endl;
    }
    return 0;
}

