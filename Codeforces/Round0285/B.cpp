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

map<string,string> data;

void update(string o, string n) {
    bool f = true;
    for(auto& e : data) {
        if(e.sc == o) {
            e.sc = n;
            f = false;
        }
    }
    if(f) {
        data[o]=n;
    }
}

int main() {
    int Q;
    cin>>Q;
    rep(i,Q) {
        string o,n;
        cin>>o>>n;
        update(o,n);
    }
    cout<<data.size()<<endl;
    for(auto& e : data) {
        cout<<e.fr<<" "<<e.sc<<endl;
    }
    return 0;
}

