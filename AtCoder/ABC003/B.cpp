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

string atcoder="atcoder@";
string S,T;
int main() {
    cin>>S>>T;
    bool flag = true;
    rep(i,S.size()) {
        if(S[i] == '@') {
            if(atcoder.find(T[i]) == string::npos) flag = false;
        }
        else {
            if(T[i]!='@' && S[i]!=T[i]) flag = false;
        }
    }
    swap(S,T);
    rep(i,S.size()) {
        if(S[i] == '@') {
            if(atcoder.find(T[i]) == string::npos) flag = false;
        }
        else {
            if(T[i]!='@' && S[i]!=T[i]) flag = false;
        }
    }
    if(flag) {
        cout<<"You can win"<<endl;
    }
    else {
        cout<<"You will lose"<<endl;

    }
    return 0;
}

