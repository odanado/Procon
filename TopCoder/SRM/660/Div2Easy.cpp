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

class Cyclemin {
public:
    string f(string s,int k) {
        int cnt=0;
        rep(i,s.size()) {
            if(k==cnt) break;
            if(s[i]!='a') {
                cnt++;
                s[i]='a';
            }
        }

        return s;
    }
    string bestmod(string s, int k) {
        string ans=s;
        rep(i,s.size()) {
            string t=s.substr(0,s.size()-1);
            t=s[s.size()-1]+t;
            ans=min(ans,f(t));
            s=t;
        }

        return ans;
    }
};

int main() {
    return 0;
}

