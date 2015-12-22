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

class OneEntrance {
public:
    vector<int> G[10];
    bool used[11],visit[11];
    int N;
    bool ok(int v,int s) {
        visit[v]=true;
        if(v==s) return true;
        bool f=false;
        rep(i,G[v].size()) {
            int u=G[v][i];
            if(!visit[u]&&!used[u]) f|=ok(u,s);
        }
        return f;
    }
    int count(vector <int> a, vector <int> b, int s) {
        rep(i,a.size()) {
            G[a[i]].pb(b[i]);
            G[b[i]].pb(a[i]);
            N=max(N,a[i]);
            N=max(N,b[i]);
        }
        vector<int> vec(N+1);
        rep(i,vec.size()) vec[i]=i;

        int ans=0;
        do {
            // rep(i,vec.size()) cout<<vec[i]<<" ";
            // cout<<endl;

            if(s!=vec[N]) continue;
            bool f=true;
            rep(i,11) used[i]=false;
            rep(i,vec.size()) {
                rep(j,11) visit[j]=false;
                used[vec[i]]=true;
                f&=ok(vec[i],s);
            }

            ans+=f;


        } while(next_permutation(all(vec)));
        return ans;
    }
};

