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

struct ID {
    map<string,int> ids;
    map<int,string> rev;
    int reg(const string &name) {
        if(!ids.count(name)) {
            int t=ids.size();
            ids[name]=t;
            rev[t]=name;
        }
        return ids[name];
    }
    string get_name(int id) {
        return rev[id];
    }
};

int count_space(string &s) {
    int cnt=0;
    rep(i,s.size()) {
        if(s[i]!=' ') break;
        cnt++;
    }
    s=s.substr(cnt,s.size()-cnt);

    return cnt;
}
int n,m;
vector<int> G[1003];
int parents[1003];

int main() {
    while(cin>>n>>m) {
        if(n==0) break;
        ID ids;
        stack<P> st;
        cin.ignore();
        rep(i,m) {
            string s;
            getline(cin,s);
            int cnt=count_space(s);
            int id=ids.reg(s);
            if(st.empty()) st.push(P(cnt,id));
            else {
                P p=st.top();
                if(p.fr==cnt) {
                    G[p.sc].pb(id);
                    G[id].pb(p.sc);
                }
                else if(p.fr+1==cnt) {
                    parents[id]=p.sc;
                    G[p.sc].pb(id);
                    G[id].pb(p.sc);
                    st.push(P(cnt,id));
                }
                else if(p.fr==cnt+1) {
                    while(1) {
                        p=st.top();
                        if(p.fr==cnt) break;
                        st.pop();
                    }
                }
            }
        }
        rep(i,m) {
            printf("v = %d: ",i);
            rep(j,G[i].size()) printf("%d, ",G[i][j]);
            cout<<endl;
        }

    }
    return 0;
}

