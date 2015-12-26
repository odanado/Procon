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

ll a;
int main() {
    cin>>a;
    if(a<10000) {
        printf("%.12f\n",a*108/100.0);
        return 0;
    }
    a *= 108;
    string s;
    stringstream ss;
    ss << a;
    ss >> s;
    rep(i,s.size()) {
        cout<<s[i];
        if(i==s.size()-3) cout<<".";
    }
    cout<<endl;
    return 0;
}

