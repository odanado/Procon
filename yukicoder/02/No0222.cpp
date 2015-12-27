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

int to_i(string &s) {
    int ret;
    stringstream ss;
    ss<<s;
    ss>>ret;
    return ret;
}

int main() {
    bool islhs = true;
    string lhs,rhs;
    string op;
    string s;
    cin>>s;
    // 真ん中の(+,-)で区切ってstringstream
    rep(i,s.size()) {
        if(islhs) {
            lhs += s[i];
        }
        else {
            rhs += s[i];
        }
        if(i!=0 && !isdigit(s[i]) && islhs) {
            islhs = false;
            op += s[i];
        }
    }
    int a,b;
    a=to_i(lhs);
    b=to_i(rhs);
    if(op=="+") cout<<a-b<<endl;
    else cout<<a+b<<endl;
    return 0;
}

