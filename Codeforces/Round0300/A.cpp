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

string code="CODEFORCES";
int main() {
    string s;
    cin>>s;
    bool f=false;
    
    rep(i,s.size()) rep(j,s.size()+1) if(i<=j) {
        string t=s.substr(0,i);
        t+=s.substr(j,s.size()-j);
        //cout<<i<<","<<j<<endl;
        //cout<<s.substr(0,i)<<","<<s.substr(i,j-i)<<","<<s.substr(j,s.size()-j)<<endl;;
        if(t==code) {
            // cout<<t<<endl;
            f=true;
        }

    }
    if(f) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    return 0;
}

