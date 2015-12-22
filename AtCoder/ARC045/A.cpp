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
    getline(cin,s);
    rep(i,s.size()) {
        if(i+3<s.size()&&s.substr(i,4)=="Left") {
            cout<<"<";
            i+=3;
        }
        else if(i+4<s.size()&&s.substr(i,5)=="Right") {
            cout<<">";
            i+=4;
        }
        else if(i+6<s.size()&&s.substr(i,7)=="AtCoder") {
            cout<<"A";
            i+=6;
        }
        else cout<<s[i];
    }
    cout<<endl;
    return 0;
}

