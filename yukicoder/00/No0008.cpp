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
typedef long long ll;

int P;
int N,K;
int main() {
    cin>>P;
    rep(_,P) {
        cin>>N>>K;
        if(N<=K) {
            cout<<"Win"<<endl;
            continue;
        }
        if(N%(K+1)==1) {
            cout<<"Lose"<<endl;
        }
        else {
            cout<<"Win"<<endl;
        }

    }
    return 0;
}

