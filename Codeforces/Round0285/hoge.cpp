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

int n;
const int NUM = 100;
int G[NUM][NUM];

int main() {
    cin>>n;
    rep(i,n) {
        int a,b;
        cin>>a>>b;
        G[a][b]=1;
        G[b][a]=1;
    }
    cout<<n+1<<endl;
    rep(i,n+1){
        int c=0;
        int s=0;
        rep(j,NUM) {
            if(G[i][j]==1) {
                c++;
                s^=j;

            }

        }
        cout<<c<<" "<<s<<endl;

    }


    return 0;
}

