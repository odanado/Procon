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

struct Edge {
    int to,weight;
    Edge(int to,int weight) :
        to(to),weight(weight){}
};

vector<Edge> G[110];
int mat[110][110];

class LuckyCycle {
public:
    int bfs(int s,int t,vector<int> &prev) {
        int d[110];
        rep(i,110) d[i]=INF;
        queue<P> que;
        que.push(P(s,0));
        d[s]=0;
        while(que.size()) {
            P p=que.front(); que.pop();
            //printf("%d %d : %d %d %d\n",s,t,p.fr,p.sc,G[p.fr].size());
            rep(i,G[p.fr].size()) {
                Edge e=G[p.fr][i];
                if(d[e.to]!=INF) continue;
                prev[e.to]=p.fr;
                d[e.to]=d[p.fr]+1;
                que.push(P(e.to,p.sc+1));
            }
        }

        return d[t];
    }
    vector <int> getEdge(vector <int> edge1, vector <int> edge2, vector <int> weight) {
        int N=edge1.size();
        rep(i,edge1.size()) {
            G[edge1[i]].pb(Edge(edge2[i],weight[i]));
            G[edge2[i]].pb(Edge(edge1[i],weight[i]));
            mat[edge1[i]][edge2[i]]=weight[i];
            mat[edge2[i]][edge1[i]]=weight[i];
        }
        rep(i,N+2) if(i) rep(j,N+2) if(j&&i!=j) {
            vector<int> prev(N+2,-1);
            int tmp=bfs(i,j,prev);
            if(tmp % 2==1&&tmp!=1) {
                //cout<<i<<", "<<j<<endl;
                vector<int> ans;
                ans.pb(i); ans.pb(j);
                int a=0,b=0;
                int v=j;
                while(v!=i) {
                    int u=prev[v];
                    if(mat[v][u]==4) a++;
                    else b++;
                    v=u;
                }
                if(a%2==0) {
                    ans.pb(7);
                }
                else ans.pb(4);

                return ans;
            }
        }

        return vector<int>();
    }
};

int main() {
    LuckyCycle obj;
    auto ans = obj.getEdge({1, 3, 2, 4},
            {2, 2, 4, 5},
            {4, 7, 4, 7});
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    return 0;
}

