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
    string N,M;
    cin>>N>>M;
    if(M=="0") {
        cout<<"1"<<endl;
        return 0;
    }
    int t=N.back()-'0';
    if(t==0||t==1||t==6||t==5) {
        cout<<t<<endl;
        return 0;
    }
    if(t==4||t==9) {
        int a=M.back()-'0';
        if(a%2==1) cout<<t<<endl;
        else cout<<(t*t)%10<<endl;
        return 0;
    }

    stringstream ss;
    int m;
    if(M.size() > 1) {
        ss << M.substr(M.size()-2,2);
    }
    else {
        ss << M;
    }
    ss >> m;
    m = (m+3)%4+1;

    int ans=1;
    rep(i,m) ans=(ans*t)%10;
    cout<<ans<<endl;
    
    return 0;
}

