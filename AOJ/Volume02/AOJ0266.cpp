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

char G['Z'][2];

void init() {
    G['A'][0]='X';
    G['A'][1]='Y';
    G['X'][1]='Z';
    G['Z'][0]='W';
    G['Z'][1]='B';
    G['Y'][0]='X';
    G['W'][0]='B';
    G['W'][1]='Y';
    G['B'][0]='Y';
    G['B'][1]='X';

}
string s;
bool solve() {
    char v = 'A';
    rep(i,s.size()) {
        v = G[v][s[i]-'0'];
        if(v==0) return false;
    }
    if(v=='B') return true;
    return false;

}

int main() {
    init();
    while(cin>>s) {
        if(s=="#") break;
        printf("%s\n",solve()?"Yes":"No");

    }
    return 0;
}

