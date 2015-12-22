#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int n,m,q;
set<char> row[1000];
set<char> col[1000];

int main() {
    cin>>n>>m>>q;
    string ss[1000];
    rep(i,n) cin>>ss[i];
    rep(i,n) {
        rep(j,m) {
            row[i].insert(ss[i][j]);
        }
        //cout<<ss[i]<<endl;
    }
    rep(i,m) {
        rep(j,n) {
            col[i].insert(ss[j][i]);
        }
    }
    rep(i,q) {
        bool flag = false;
        char c;
        cin>>c;
        rep(j,n) {
            if(row[j].find(c) != row[j].end()) {
                cout<<j+1<<" ";
                flag=true;
            }
        }
        rep(j,m) {
            if(col[j].find(c) != col[j].end()) {
                cout<<j+1<<"\n";
            }

        }
        if(!flag){
            cout<<"NA"<<endl;
        }

    }

    return 0;
}



