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

string s;
bool ok(int pos) {
    if(s.size()<=pos) return true;
    else if(s[pos]=='c') {
        if(pos+1==s.size()) return false;
        if(s[pos+1]=='h') return ok(pos+2);
    }
    else if(s[pos]=='o') return ok(pos+1);
    else if(s[pos]=='k') return ok(pos+1);
    else if(s[pos]=='u') return ok(pos+1);


    return false;
}

int main() {
    cin>>s;
    if(ok(0)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

