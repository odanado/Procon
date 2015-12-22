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

bool comp(const string& s1, const string& s2) {
    rep(i,min(s1.size(),s2.size())) {
        if(s1[i]<s2[i]) return true;
        if(s1[i]>s2[i]) return false;
    }

    return s1.size() < s2.size();
}
int main() {
    vector<string> vec;
    rep(i,1001) {
        if(!i) continue;
        string s;
        std::stringstream ss;

        ss << i;
        ss >> s;
        vec.pb(s);
    }
    sort(all(vec),comp);
    rep(i,vec.size()) {
        cout<<vec[i]<<endl;
    }

    return 0;
}

