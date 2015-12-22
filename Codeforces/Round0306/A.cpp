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

string s;
int main() {
    cin>>s;
    vector<int> vec1,vec2;
    rep(i,s.size()-1) {
        if(s.substr(i,2)=="AB") vec1.pb(i);
        if(s.substr(i,2)=="BA") vec2.pb(i);
    }

    rep(i,vec1.size()) rep(j,vec2.size()) {
        if(abs(vec1[i]-vec2[j])<=1) continue;
        cout<<"YES"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;


    return 0;
}

