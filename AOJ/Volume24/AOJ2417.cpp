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

char shi['Z'+10];
string bo['z'+10];

int main() {
    shi['T']='a';
    shi['L']='i';
    shi['U']='u';
    shi['R']='e';
    shi['D']='o';

    bo['1']="";
    bo['2']="k";
    bo['3']="s";
    bo['4']="t";
    bo['5']="n";
    bo['6']="h";
    bo['7']="m";
    bo['8']="y";
    bo['9']="r";
    bo['0']="w";
    string s;
    cin>>s;
    string ans="";
    rep(i,s.size()) {
        if(i%2==0) {
            ans+=bo[s[i]];
        }
        else ans+=shi[s[i]];
    }
    rep(i,ans.size()) {
        if(!i) continue;
        if(ans[i-1]=='w'&&ans[i]=='u'){
            ans[i-1]=ans[i]='n';
        }
    }
    cout<<ans<<endl;
    return 0;
}

