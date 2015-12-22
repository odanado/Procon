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
string a;
string x;
int main() {
    x="";
    cin>>n;
    cin>>a;
    rep(i,n) {
        int val=a[i]-'0';
        if(val==0||val==1) continue;
        if(val==2||val==3||val==5||val==7) x+=a[i];
        if(val==4) x+="322";
        if(val==6) x+="53";
        if(val==8) x+="7222";
        if(val==9) x+="7332";
    }

    sort(all(x),greater<char>());
    cout<<x<<endl;

    return 0;
}

