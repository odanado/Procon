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

string str;
int main() {
    cin>>str;
    rep(i,str.size()) {
        char c = '9'-str[i]+'0';
        if(i==0) {
            if(c=='0') continue;
            if(!isdigit(c)) continue;
            str[i]=min(str[i],c);
        }
        else {
            if(!isdigit(c)) continue;
            str[i]=min(str[i],c);

        }
    }
    cout<<str<<endl;
    return 0;
}

