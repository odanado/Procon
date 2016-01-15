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

string S1,S2;
bool ch() {
    if(S1.size()!=S2.size()) return S1.size() > S2.size();
    rep(i,S1.size()) {
        if(S1[i]=='4' and S2[i]=='7') return true;
        if(S2[i]=='4' and S1[i]=='7') return false;
        if(S1[i] != S2[i]) return S1[i] > S2[i];
    }

    return false;
}
int main() {
    cin>>S1>>S2;
    if(ch()) cout<<S1<<endl;
    else cout<<S2<<endl;



    return 0;
}

