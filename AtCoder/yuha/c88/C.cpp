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

string S[21],U[21],V[21];
map<string,int> ids;
int N;

int main() {
    vector<string> ans;
    cin>>N;
    rep(i,N) {
        cin>>S[i];
        ids[S[i]]=ids.size();
    }
    rep(i,N) {
        char t1[21],t2[21];
        scanf("%s is a %s venturer.",t1,t2);
        U[i]=string(t1);
        V[i]=string(t2);
    }

    rep(S1,1<<N) {
        bool ok=true;
        rep(i,N) {
            int t=((S1>>i)&1);
            if(t) {
                if(V[i]=="bad") t=0;
            }
            else {
                if(V[i]=="good") t=0;
                if(V[i]=="bad") t=1;
            }
            if(((S1>>ids[U[i]])&1)!=t) ok=false;
        }
        if(ok) {
            //cout<<S1<<endl;
            vector<string> tmp;
            rep(i,N) if(S1>>i&1) tmp.pb(S[i]);
            if(ans.size()<tmp.size()) ans=tmp;
            else if(ans.size()==tmp.size()) {
                bool f=false;
                sort(all(ans));
                sort(all(tmp));
                rep(i,ans.size()) {
                    if(tmp[i].size()<ans[i].size()||tmp[i]<ans[i]) {
                        f=true;
                        break;
                    }
                }
                if(f) ans=tmp;
            }
        }
    }

    if(!ans.size()) cout<<"No Answer"<<endl;
    sort(all(ans));
    rep(i,ans.size()) cout<<ans[i]<<endl;
    return 0;
}

