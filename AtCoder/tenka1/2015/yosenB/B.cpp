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

bool is_dict(string s) {
    if(s=="{}") return true;
    bool f=false;
    stack<int> st;
    rep(i,s.size()) {
        if(s[i]=='{') {
            st.push(i);
        }
        if(s[i]=='}') st.pop();
        if(s[i]==':'&&st.size()==1) f=true;
    }

    return f;
}

int main() {
    string s; cin>>s;
    if(is_dict(s)) cout<<"dict"<<endl;
    else cout<<"set"<<endl;
    return 0;
}

