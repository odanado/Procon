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

int main() {
    string s;
    cin>>s;
    bool f=true;
    string a[4]={"ch","o","k","u"};
    rep(i,s.size()-1) {
        if(!((s[i]=='c'&&s[i+1]=='h')||s[i]=='o'||s[i]=='k'||s[i]=='u')) {
            f=false;
        }
        else if(s[i]=='c') i++;
    }
    if(s.back()!='o'&&s.back()!='k'&&s.back()!='u') f=false;
    if(f) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

