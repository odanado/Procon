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
    int n;
    cin>>s;
    cin>>n;
    rep(i,n) {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        //cout<<s.substr(0,l)<<","<<s.substr(l,r-l+1)<<","<<s.substr(r+1,s.size()-r-1)<<endl;;
        string t=s.substr(l,r-l+1);
        reverse(all(t));
        s = s.substr(0,l)+t+s.substr(r+1,s.size()-r-1);
        //cout<<s<<endl;
    }

    cout<<s<<endl;
    return 0;
}

